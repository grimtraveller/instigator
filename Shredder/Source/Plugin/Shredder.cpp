/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "Shredder.h"
#include "ShredderEditor.h"

//==============================================================================
Shredder::Shredder() : savedSamplesPerBlock(8192), savedSampleRate(44100)
{
    // Set up some default values..
	shredderDefaults.setValue (T("vstPluginDir"), String(T("C:\\Program Files\\VstPlugins")));
	shredderProperties.setFallbackPropertySet (&shredderDefaults);
    
	lastPosInfo.resetToDefault();

	pluginFormatManager.addDefaultFormats();

	for (int i=0; i<pluginFormatManager.getNumFormats(); i++)
	{
		Log (T("Shredder::ctor found plugin format: ") + pluginFormatManager.getFormat(i)->getName());
	}

	File f = _cacheFile();
	if (f.existsAsFile())
	{
		XmlDocument doc(f.loadFileAsString());

		XmlElement *pluginCache = doc.getDocumentElement();

		if (pluginCache)
		{
			forEachXmlChildElement (*pluginCache, e)
			{
				PluginDescription *p = new PluginDescription();
				p->loadFromXml (*e);
				pluginsToUse.add (p);
			}

			deleteAndZero (pluginCache);
		}
	}
}

Shredder::~Shredder()
{
	Log (T("Shredder::dtor"));
	loadedPlugins.clear();
}

//==============================================================================
int Shredder::getNumParameters()
{
    return 0;
}

float Shredder::getParameter (int index)
{
    return 0.0f;
}

void Shredder::setParameter (int index, float newValue)
{
}

const String Shredder::getParameterName (int index)
{
    return String::empty;
}

const String Shredder::getParameterText (int index)
{
    return String (getParameter (index), 2);
}

const String Shredder::getInputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String Shredder::getOutputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

bool Shredder::isInputChannelStereoPair (int index) const
{
    return true;
}

bool Shredder::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool Shredder::acceptsMidi() const
{
    return true;
}

bool Shredder::producesMidi() const
{
    return false;
}

//==============================================================================
void Shredder::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	loadedPlugins.getLock().enter();

	savedSamplesPerBlock	= samplesPerBlock;
	savedSampleRate			= sampleRate;

	for (int i=0; i<loadedPlugins.size(); i++)
	{
		loadedPlugins[i]->prepareToPlay (sampleRate, samplesPerBlock);
	}

	loadedPlugins.getLock().exit();
}

void Shredder::releaseResources()
{
	loadedPlugins.getLock().enter();

	for (int i=0; i<loadedPlugins.size(); i++)
	{
		loadedPlugins[i]->releaseResources ();
	}

	loadedPlugins.getLock().exit();
}

void Shredder::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    AudioPlayHead::CurrentPositionInfo newTime;

    if (getPlayHead() != 0 && getPlayHead()->getCurrentPosition (newTime))
    {
		lastPosInfo = newTime;
    }
    else
    {
        lastPosInfo.resetToDefault();
    }

	currentRmsValue[0] = buffer.getRMSLevel(0, 0, buffer.getNumSamples());
	currentRmsValue[1] = buffer.getRMSLevel(1, 0, buffer.getNumSamples());

	processPlugins (buffer, midiMessages, lastPosInfo);

	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	sendChangeMessage (this);
}

//==============================================================================
AudioProcessorEditor* Shredder::createEditor()
{
    return new ShredderEditor (this);
}

//==============================================================================
void Shredder::getStateInformation (MemoryBlock& destData)
{
	Log (T("Shredder::getStateInformation"));

	XmlElement *pluginCache = new XmlElement (T("pluginCache"));
	for (int i=0; i<pluginsToUse.size(); i++)
	{
		pluginCache->addChildElement (pluginsToUse[i]->createXml());
	}

	XmlElement *pluginsActive = new XmlElement (T("pluginsActive"));
	
	loadedPlugins.getLock().enter();

	for (int i=0; i<loadedPlugins.size(); i++)
	{
		XmlElement *state = loadedPlugins[i]->createXml();
		if (state)
		{
			pluginsActive->addChildElement (state);
		}
	}

	loadedPlugins.getLock().exit();

	shredderProperties.setValue (T("pluginCache"), pluginCache);
	shredderProperties.setValue (T("pluginsActive"), pluginsActive);

	XmlElement *e = shredderProperties.createXml (T("shredder"));
	copyXmlToBinary (*e, destData);

	Log (e->createDocument(String::empty));

	deleteAndZero (e);
	deleteAndZero (pluginCache);
	deleteAndZero (pluginsActive);
}

void Shredder::setStateInformation (const void* data, int sizeInBytes)
{
	Log (T("Shredder::setStateInformation"));

    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState != 0)
    {
		Log (xmlState->createDocument (String::empty));

		shredderProperties.restoreFromXml (*xmlState);

		pluginsToUse.clear();
		
		XmlElement *pluginCache = shredderProperties.getXmlValue (T("pluginCache"));
		if (pluginCache)
		{
			forEachXmlChildElement (*pluginCache, e)
			{
				PluginDescription *p = new PluginDescription();
				p->loadFromXml (*e);
				pluginsToUse.add (p);
			}

			deleteAndZero (pluginCache);
		}

		XmlElement *pluginsActive = shredderProperties.getXmlValue (T("pluginsActive"));
		if (pluginsActive)
		{
			forEachXmlChildElement (*pluginsActive, e)
			{
				if (e->hasTagName (T("shredderPlugin")))
				{
					ShredderPlugin *p = new ShredderPlugin (e, pluginFormatManager);
					if (p->pluginInstance)
						loadedPlugins.add (p);
					else
						deleteAndZero (p);
				}
			}

			deleteAndZero (pluginsActive);
		}
    }
}

bool Shredder::loadPluginOnSlot (const int slotNumber, ShredderPlugin::SlotType slotType, const int pluginIndex)
{
	Log (T("Shredder::loadPluginOnSlot slotNumber:") + String(slotNumber) + T(" type:") + String((int)slotType) + T(" index:") + String(pluginIndex));

	if (pluginIndex >= 0)
	{
		/* new plugin */
		PluginDescription *pd = pluginsToUse[pluginIndex];
		if (pd)
		{
			if (!pluginFormatManager.doesPluginStillExist (*pd))
			{
				AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("This plugin does not exist"), T("Looks like the selected plugin does not exist anymore, check your settings"));
				return (false);
			}

			String errorMessage;
			AudioPluginInstance *instance = pluginFormatManager.createPluginInstance (*pd, errorMessage);
			instance->prepareToPlay (savedSampleRate, savedSamplesPerBlock);

			if (instance == 0)
			{
				AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("Error"), T("Unable to load plugin: ") + errorMessage);
				return (false);
			}
			else
			{
				loadedPlugins.getLock().enter();

				ShredderPlugin *p = getPluginOnSlot(slotNumber);
				if (p)
				{
					p->replacePlugin (instance, *pd);
					p->setSlotType (slotType);
				}
				else
				{
					p = new ShredderPlugin(instance, *pd);
					p->setSlotNumber (slotNumber);
					p->setSlotType (slotType);
					loadedPlugins.add (p);
				}
				
				loadedPlugins.getLock().exit();
				return (true);
			}
		}
	}

	return (false);
}

bool Shredder::clearPluginOnSlot (const int slotNumber, const bool deleteEditor)
{
	if (slotNumber >= 0)
	{
		if (getPluginOnSlot (slotNumber))
		{
			getPluginOnSlot (slotNumber)->closePlugin (deleteEditor);
			return (true);
		}
	}
	return (false);
}

ShredderPlugin *Shredder::getPluginOnSlot(const int slotNumber)
{
	for (int i=0; i<loadedPlugins.size(); i++)
	{
		if (loadedPlugins[i]->getSlotNumber() == slotNumber)
		{
			return (loadedPlugins[i]);
		}
	}

	return (0);
}

void Shredder::processPlugins(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo)
{
	const int soloSlot = shredderProperties.getIntValue (T("soloSlot"), -1);

	if (soloSlot >=0 && getPluginOnSlot(soloSlot))
	{
		loadedPlugins.getLock().enter();
		getPluginOnSlot(soloSlot)->process (buffer, midiMessages, lastPosInfo);
		loadedPlugins.getLock().exit();

		return;
	}

	AudioSampleBuffer directInput(buffer);

	loadedPlugins.getLock().enter();

	for (int i=0; i<loadedPlugins.size(); i++)
	{
		if (loadedPlugins[i]->getDirect())
		{
			AudioSampleBuffer tempBuf (directInput);
			loadedPlugins[i]->process (tempBuf, midiMessages, lastPosInfo);
			for (int i=0; i<tempBuf.getNumChannels(); i++)
			{
				buffer.addFrom (i, 0, tempBuf, i, 0, tempBuf.getNumSamples());
			}
		}
		else
		{
			loadedPlugins[i]->process (buffer, midiMessages, lastPosInfo);
		}
	}

	loadedPlugins.getLock().exit();
}

const bool Shredder::dumpPluginCache (const File &cacheFile)
{
	XmlElement *pluginCache = new XmlElement (T("pluginCache"));
	
	loadedPlugins.getLock().enter();

	for (int i=0; i<pluginsToUse.size(); i++)
	{
		pluginCache->addChildElement (pluginsToUse[i]->createXml());
	}

	loadedPlugins.getLock().exit();
	const String doc = pluginCache->createDocument(String::empty);
	deleteAndZero (pluginCache);

	return (cacheFile.replaceWithText (doc));
}

void Shredder::setSoloSlot (const int newSoloSlot)
{
	shredderProperties.setValue (T("soloSlot"), newSoloSlot);

	sendChangeMessage (this);
}

const int Shredder::getSoloSlot()
{
	return (shredderProperties.getIntValue (T("soloSlot"), -1));
}
//==============================================================================
// Some utility stuff

const String timeToTimecodeString (const double seconds)
{
    const double absSecs = fabs (seconds);
    const tchar* const sign = (seconds < 0) ? T("-") : T("");

    const int hours = (int) (absSecs / (60.0 * 60.0));
    const int mins  = ((int) (absSecs / 60.0)) % 60;
    const int secs  = ((int) absSecs) % 60;

	String t;
	t<< String(sign) + T(":");
	t<< String(hours) + T(":");
	t<< String(mins) + T(":");
	t<< String(secs) + T(":");
	t<< String(roundDoubleToInt (absSecs * 1000) % 1000);
    return (t);
}

const String ppqToBarsBeatsString (const double ppq, const double lastBarPPQ, const int numerator, const int denominator)
{
    if (numerator == 0 || denominator == 0)
        return T("1|1|000");

    const int ppqPerBar = (numerator * 4 / denominator);
    const double beats  = (fmod (ppq, ppqPerBar) / ppqPerBar) * numerator;

    const int bar       = ((int) ppq) / ppqPerBar + 1;
    const int beat      = ((int) beats) + 1;
    const int ticks     = ((int) (fmod (beats, 1.0) * 960.0));
	const int qnote		= ((int) (beats*denominator)) + 1;
	const int step		= qnote * beat;

	double i;
	// return (String::formatted (T("bar:%2d - beat:%2d - qnote:%2d - tick:%4d - ppq:%.4d"), bar, beat, qnote, ticks, ppq));
	return (String::formatted (T("%1.4f"), modf (beats * denominator, &i) ));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Shredder();
}
