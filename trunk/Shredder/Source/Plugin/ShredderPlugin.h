#ifndef __SHREDDER_PLUGIN_526ED7A9__
#define __SHREDDER_PLUGIN_526ED7A9__

#include "Includes.h"
#include "Hydrogen/adsr.h"

#define SP_LAST_POSITION		T("lastPosition")
#define SP_LENGTH				T("length")
#define SP_PROCESSING			T("processing")
#define SP_SLOT_NUMBER			T("slotNumber")
#define SP_STEP_BITS			T("stepBits")
#define SP_PLUGIN_STATE			T("pluginState")
#define SP_PLUGIN_DESCRIPTION	T("pluginDescription")
#define SP_SLOT_TYPE			T("slotType")
#define SP_SAMPLERATE			T("sampleRate")
#define SP_ENVELOPE				T("envelope")
#define SP_WET_LEVEL			T("wetLevel")
#define SP_DRY_LEVEL			T("dryLevel")
#define SP_DIRECT				T("direct")
#define SP_MIDI_CHANNEL			T("midiChannel")
#define SP_MIDI_NOTE			T("midiNote")
#define SP_MIDI_NOTE_VELO		T("midiNoteVelocity")
#define SP_GATE_MODE			T("gateMode")
#define SP_VELOCITY_MATCH		T("velocityMatch")

#define _propB(x)			shredderPluginProperties.getBoolValue(x)
#define _propI(x)			shredderPluginProperties.getIntValue(x)
#define _propD(x)			shredderPluginProperties.getDoubleValue(x)
#define _propF(x)			(float)shredderPluginProperties.getDoubleValue(x)
#define _propS(x)			shredderPluginProperties.getValue(x)
#define _propX(x)			shredderPluginProperties.getXmlValue(x)

class ShredderProperies : public PropertySet, public ChangeBroadcaster
{
	void propertyChanged()
	{
		sendChangeMessage (this);
	}
};

class ShredderPlugin : public ChangeBroadcaster, public ChangeListener
{
	public:
		enum SlotType
		{
			SequencerSlot,
			PeakSlot,
			MidiSlot
		};

		ShredderPlugin (AudioPluginInstance *_pluginInstance, PluginDescription &_pluginDescription);
		ShredderPlugin (XmlElement *xmlState, AudioPluginFormatManager &pluginManager);
		~ShredderPlugin();
		void changeListenerCallback (void* objectThatHasChanged);

		AudioProcessorEditor *getEditor();
		void editorClosed(const bool deleteEditor=true);
		void closePlugin(const bool deleteEditor=true);
		void replacePlugin(AudioPluginInstance *_pluginInstance, PluginDescription &_pluginDescription);

		XmlElement *createXml();	
		void setDefaults();

		const AudioPluginInstance *getPluginInstance() { return (pluginInstance); }
		
		void prepareToPlay (double sampleRate, int samplesPerBlock);
		void releaseResources();
		void process(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo);
		void processSequence(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo);
		void processMidi(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo);
		void processPlugin (AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const bool applyEffect=true);
		
		const String getName();

		const Rectangle<int> getLastPos();
		void setLastPos (const Rectangle<int> newPosition);

		void setStep (const int stepNumber, const bool stepState);
		void setStepsAsInt (const int steps);
		const bool getStep (const int stepNumber);
		BigInteger getSteps() { return (stepBits); }

		const int getLength ();
		void setLength (const int _length);
		
		void setProcessing (const bool _shouldBeProcessing);
		const bool getProcessing () { return (_propB(SP_PROCESSING)); }
		
		void setSlotNumber (const int newSlot);
		const int getSlotNumber () { return (_propI(SP_SLOT_NUMBER)); }

		const ShredderPlugin::SlotType getSlotType();
		void setSlotType(const SlotType newSlotType);

		void setDryLevel (const double newDryLevel);
		const double getDryLevel();

		void setWetLevel (const double newWetLevel);
		const double getWetLevel();

		void setMidiChannel (const int midiChannel);
		const int getMidiChannel();

		void setMidiNote (const int midiNote, const double velocity);
		const int getMidiNote ();
		const double getMidiNoteVelocity ();

		void setGate (const bool setGateMode);
		const bool getGate();

		void setDirect (const bool setDirect);
		const bool getDirect();

		void setVelocityMatch (const bool setVelocityMatch);
		const bool getVelocityMatch ();

		AudioPluginInstance *pluginInstance;

		/* ADSR */
		const float getAttack();
		void setAttack(const float newAttack);

		const float getDecay();
		void setDecay(const float newDecay);

		const float getSustain();
		void setSustain(const float newSustain);

		const float getRelease();
		void setRelease(const float newRelease);

	private:
		PropertySet shredderPluginDefaultProperties;
		ShredderProperies shredderPluginProperties;
		PluginDescription pluginDescription;
		AudioProcessorEditor *editor;
		BigInteger stepBits;
		int lastBeat;
		float wetGain, dryGain;
		ADSR envelope;
		bool continueMidiProcessing;
};

#endif