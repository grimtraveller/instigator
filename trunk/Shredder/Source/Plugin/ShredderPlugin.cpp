#include "ShredderPlugin.h"

ShredderPlugin::ShredderPlugin (AudioPluginInstance *_pluginInstance, PluginDescription &_pluginDescription) 
	:	pluginInstance(_pluginInstance), editor(0), pluginDescription(_pluginDescription)
{	
	setDefaults();
}

ShredderPlugin::ShredderPlugin (XmlElement *xmlState, AudioPluginFormatManager &pluginManager)
	:	editor(0), pluginInstance(0)
{
	setDefaults();

	if (xmlState->hasTagName (T("shredderPlugin")))
	{
		String errorMessage;

		shredderPluginProperties.restoreFromXml (*xmlState);

		stepBits.parseString (_propS(SP_STEP_BITS), 2);

		if (shredderPluginProperties.containsKey (T("pluginState")))
		{
			pluginDescription.loadFromXml (*_propX (SP_PLUGIN_DESCRIPTION));
			pluginInstance		= pluginManager.createPluginInstance (pluginDescription, errorMessage);

			if (pluginInstance == 0)
			{
				AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("Error"), T("Unable to load plugin: ") + errorMessage);
				return;
			}

			MemoryBlock bl;
			bl.fromBase64Encoding (_propS(SP_PLUGIN_STATE));

			pluginInstance->setStateInformation (bl.getData(), bl.getSize());
		}
	}
}

void ShredderPlugin::setDefaults()
{
	lastBeat = 1;

	stepBits.clear();
	shredderPluginDefaultProperties.setValue (SP_LENGTH, 16);
	shredderPluginDefaultProperties.setValue (SP_PROCESSING, true);
	shredderPluginDefaultProperties.setValue (SP_FADE_OFF, 0.0);
	shredderPluginDefaultProperties.setValue (SP_SLOT_TYPE, SequencerSlot);

	shredderPluginProperties.setFallbackPropertySet (&shredderPluginDefaultProperties);
}

XmlElement *ShredderPlugin::createXml()
{
	if (pluginInstance)
	{
		MemoryBlock pluginState;
		pluginInstance->getStateInformation (pluginState);

		shredderPluginProperties.setValue (SP_PLUGIN_STATE, pluginState.toBase64Encoding());
		shredderPluginProperties.setValue (SP_PLUGIN_DESCRIPTION, pluginDescription.createXml());
		shredderPluginProperties.setValue (SP_STEP_BITS, stepBits.toString (2, 16));

		return (shredderPluginProperties.createXml(T("shredderPlugin")));
	}

	return (0);
}

ShredderPlugin::~ShredderPlugin()
{
	if (editor)
	{
		deleteAndZero (editor);
	}
	if (pluginInstance)
	{
		deleteAndZero (pluginInstance);
	}
}

void ShredderPlugin::replacePlugin (AudioPluginInstance *_pluginInstance, PluginDescription &_pluginDescription)
{
	closePlugin();
	setProcessing (true);

	pluginInstance		= _pluginInstance;
	pluginDescription	= _pluginDescription;
}

void ShredderPlugin::closePlugin(const bool deleteEditor)
{
	shredderPluginProperties.setValue (SP_LAST_POSITION, Rectangle<int>().toString());
	setFadeOff (0.0f);
	setProcessing (false);

	if (pluginInstance)
	{
		deleteAndZero (pluginInstance);
	}
	if (deleteEditor && editor)
	{
		deleteAndZero (editor);
	}
}

AudioProcessorEditor *ShredderPlugin::getEditor ()
{
	if (pluginInstance)
	{
		editor = pluginInstance->createEditorIfNeeded();
		return (editor);
	}
	
	return (0);
}

void ShredderPlugin::editorClosed(const bool deleteEditor)
{
	if (editor && deleteEditor)
	{
		deleteAndZero (editor);
	}

	if (editor && !deleteEditor)
	{	
		editor = 0;
	}
}

const String ShredderPlugin::getName()
{
	if (pluginInstance)
	{
		return (pluginInstance->getName());
	}

	return (T("--- No plugin"));
}

void ShredderPlugin::setLength (const int _length)
{
	shredderPluginProperties.setValue (SP_LENGTH, _length);
}

void ShredderPlugin::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	lastBeat = 1;

	if (pluginInstance)
	{
		pluginInstance->prepareToPlay (sampleRate, samplesPerBlock);
	}
}

void ShredderPlugin::releaseResources()
{
	if (pluginInstance)
	{
		pluginInstance->releaseResources ();
	}
}

void ShredderPlugin::process(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo)
{
	if (pluginInstance == 0 || lastPosInfo.timeSigDenominator == 0 || lastPosInfo.timeSigNumerator == 0)
	{
		return;
	}

	AudioSampleBuffer internalBuffer (buffer);

	const int ppqPerBar			= (lastPosInfo.timeSigNumerator * 4 / lastPosInfo.timeSigDenominator);
	const double beats			= (fmod (lastPosInfo.ppqPosition, ppqPerBar) / ppqPerBar) * lastPosInfo.timeSigNumerator;
	const int qnote				= ((int) (beats * lastPosInfo.timeSigDenominator)) + 1;
	const float fade			= _propF(SP_FADE_OFF);
	const int length			= _propI(SP_LENGTH);

	/* move forward */
	if (qnote > lastBeat)
	{
		lastBeat++;
	}
	
	if (qnote < lastBeat)
	{
		if (lastBeat >= length)
		{
			lastBeat = 1;
		}
	}

	if (!_propB(SP_PROCESSING))
	{
		return;
	}

	if (stepBits[lastBeat-1])
	{
		pluginInstance->processBlock (buffer, midiMessages);
	}
	else if (fade == 0.0)
	{
		pluginInstance->processBlock (internalBuffer, midiMessages);
	}
	else if (		/* first step, but last was played */(lastBeat == 1 && stepBits[length-1] && fade > 0.0) 
				||	/* previous step was played */ (lastBeat>1 && stepBits[lastBeat-2] && fade > 0.0))
	{
		double ip;
		const double pos = modf (beats * lastPosInfo.timeSigDenominator, &ip);

		if (pos < fade)
		{
			pluginInstance->processBlock (buffer, midiMessages);
			
			const float gain = (float)(fade - pos);

			for (int i=0; i<buffer.getNumChannels(); i++)
			{
				buffer.applyGain (i, 0, buffer.getNumSamples(), gain);				
			}
		}
	}
}

void ShredderPlugin::processSequence(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo)
{
}

void ShredderPlugin::processPeak(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo)
{
}

void ShredderPlugin::setFadeOff (const float newFade)
{
	shredderPluginProperties.setValue (SP_FADE_OFF, newFade);
}

void ShredderPlugin::setProcessing (const bool _shouldBeProcessing)
{
	shredderPluginProperties.setValue (SP_PROCESSING, _shouldBeProcessing);
}

void ShredderPlugin::setSlotNumber (const int newSlot)
{
	shredderPluginProperties.setValue (SP_SLOT_NUMBER, newSlot);
}

void ShredderPlugin::setLastPos (const Rectangle<int> newPosition)
{
	shredderPluginProperties.setValue (SP_LAST_POSITION, newPosition.toString());
}

const Rectangle<int> ShredderPlugin::getLastPos()
{
	return (Rectangle<int>::fromString (_propS(SP_LAST_POSITION)));
}

const int ShredderPlugin::getLength()
{
	return (_propI(SP_LENGTH));
}

const ShredderPlugin::SlotType ShredderPlugin::getSlotType()
{
	return ((const ShredderPlugin::SlotType)_propI(SP_SLOT_TYPE));
}

void ShredderPlugin::setSlotType(const SlotType newSlotType)
{
	shredderPluginProperties.setValue (SP_SLOT_TYPE, newSlotType);
}

void ShredderPlugin::setStep (const int stepNumber, const bool stepState)
{
	stepBits.setBit (stepNumber-1, stepState);
}

const bool ShredderPlugin::getStep (const int stepNumber)
{
	return (stepBits[stepNumber-1]);
}