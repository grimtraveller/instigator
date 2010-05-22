#include "ShredderPlugin.h"

ShredderPlugin::ShredderPlugin (AudioPluginInstance *_pluginInstance, PluginDescription &_pluginDescription) 
	:	pluginInstance(_pluginInstance), editor(0), pluginDescription(_pluginDescription), continueMidiProcessing(false)
{	
	setDefaults();
}

ShredderPlugin::ShredderPlugin (XmlElement *xmlState, AudioPluginFormatManager &pluginManager)
	:	editor(0), pluginInstance(0), continueMidiProcessing(false)
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
			envelope.loadXml (_propX (SP_ENVELOPE));

			pluginInstance		= pluginManager.createPluginInstance (pluginDescription, errorMessage);

			dryGain = _propF(SP_DRY_LEVEL)/100.0f;
			wetGain = _propF(SP_WET_LEVEL)/100.0f;

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
	lastBeat	= 1;
	wetGain		= 1.0f;
	dryGain		= 1.0f;

	stepBits.clear();
	shredderPluginDefaultProperties.setValue (SP_LENGTH, 16);
	shredderPluginDefaultProperties.setValue (SP_SAMPLERATE, 44100.0);
	shredderPluginDefaultProperties.setValue (SP_PROCESSING, true);
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
		shredderPluginProperties.setValue (SP_ENVELOPE, envelope.createXml());

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
		if (editor == 0)
		{
			editor = new GenericAudioProcessorEditor (pluginInstance);
		}

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

void ShredderPlugin::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	lastBeat				= 1;
	continueMidiProcessing	= false;

	shredderPluginProperties.setValue (SP_SAMPLERATE, sampleRate);

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

	switch (_propI(SP_SLOT_TYPE))
	{
		case SequencerSlot:
			processSequence (buffer, midiMessages, lastPosInfo);
			break;

		case MidiSlot:
			processMidi (buffer, midiMessages, lastPosInfo);
			break;

		default:
			break;
	}
}

void ShredderPlugin::processSequence(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo)
{
	const int ppqPerBar			= (lastPosInfo.timeSigNumerator * 4 / lastPosInfo.timeSigDenominator);
	const double beats			= (fmod (lastPosInfo.ppqPosition, ppqPerBar) / ppqPerBar) * lastPosInfo.timeSigNumerator;
	const int qnote				= ((int) (beats * lastPosInfo.timeSigDenominator)) + 1;
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
		processPlugin (buffer, midiMessages);
	}
	else
	{
		processPlugin (buffer, midiMessages, false);
	}
}

void ShredderPlugin::processMidi(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo)
{
	MidiBuffer::Iterator i(midiMessages);
	MidiMessage m(0xf0);
	int pos;

	while (i.getNextEvent (m, pos))
	{
		const bool nOn	= m.isNoteOn (true);
		const bool nOff	= m.isNoteOff (true);

		if (nOn)
		{
			continueMidiProcessing = true;
		}
		if (nOff)
		{
			continueMidiProcessing = false;
		}
	}

	if (continueMidiProcessing)
	{
		processPlugin (buffer, midiMessages);
	}
	else
	{
		processPlugin (buffer, midiMessages, false);
	}
}

void ShredderPlugin::processPlugin (AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const bool applyEffect)
{
	AudioSampleBuffer internalBuffer (buffer);

	if (applyEffect)
	{
		pluginInstance->processBlock (internalBuffer, midiMessages);
		for (int i=0; i<buffer.getNumChannels(); i++)
		{
			buffer.applyGain (i, 0, buffer.getNumSamples(), dryGain);
			buffer.addFrom (i, 0, internalBuffer, i, 0, internalBuffer.getNumSamples(), wetGain);
		}
	}
	else
	{
		pluginInstance->processBlock (internalBuffer, midiMessages);
	}
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

void ShredderPlugin::setLength (const int _length)
{
	shredderPluginProperties.setValue (SP_LENGTH, _length);
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

const float ShredderPlugin::getAttack()
{
	return (envelope.__attack);
}

void ShredderPlugin::setAttack(const float newAttack)
{
	envelope.__attack = newAttack;
}

const float ShredderPlugin::getDecay()
{
	return (envelope.__decay);
}

void ShredderPlugin::setDecay(const float newDecay)
{
	envelope.__decay = newDecay;
}

const float ShredderPlugin::getSustain()
{
	return (envelope.__sustain);
}

void ShredderPlugin::setSustain(const float newSustain)
{
	envelope.__sustain = newSustain;
}

const float ShredderPlugin::getRelease()
{
	return (envelope.__release);
}

void ShredderPlugin::setRelease(const float newRelease)
{
	envelope.__release = newRelease;
}

void ShredderPlugin::setDryLevel (const double newDryLevel)
{
	dryGain = (float)newDryLevel/100.0f;
	shredderPluginProperties.setValue (SP_DRY_LEVEL, newDryLevel);
}

const double ShredderPlugin::getDryLevel()
{
	return (_propD(SP_DRY_LEVEL));
}

void ShredderPlugin::setWetLevel (const double newWetLevel)
{
	wetGain = (float)newWetLevel/100.0f;
	shredderPluginProperties.setValue (SP_WET_LEVEL, newWetLevel);
}

const double ShredderPlugin::getWetLevel()
{
	return (_propD(SP_WET_LEVEL));
}