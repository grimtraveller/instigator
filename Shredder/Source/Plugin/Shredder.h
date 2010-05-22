#ifndef __SHREDDER_H_526ED7A9__
#define __SHREDDER_H_526ED7A9__

#include "Includes.h"
#include "ShredderPlugin.h"

//==============================================================================
class Shredder  : public AudioProcessor, public ChangeBroadcaster
{
	public:
		Shredder();
		~Shredder();

		/* begin VST stuff */
		void prepareToPlay (double sampleRate, int samplesPerBlock);
		void releaseResources();
		void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
		AudioProcessorEditor* createEditor();
		const String getName() const        { return JucePlugin_Name; }
		int getNumParameters();
		float getParameter (int index);
		void setParameter (int index, float newValue);
		const String getParameterName (int index);
		const String getParameterText (int index);
		const String getInputChannelName (const int channelIndex) const;
		const String getOutputChannelName (const int channelIndex) const;
		bool isInputChannelStereoPair (int index) const;
		bool isOutputChannelStereoPair (int index) const;
		bool acceptsMidi() const;
		bool producesMidi() const;
		int getNumPrograms()                                        { return 0; }
		int getCurrentProgram()                                     { return 0; }
		void setCurrentProgram (int index)                          { }
		const String getProgramName (int index)                     { return String::empty; }
		void changeProgramName (int index, const String& newName)   { }
		void getStateInformation (MemoryBlock& destData);
		void setStateInformation (const void* data, int sizeInBytes);
		/* end VST stuff */

		/* Shredder implementation */
		void dumpPluginCache (const File &cacheFile);
		bool loadPluginOnSlot (const int slotNumber, ShredderPlugin::SlotType slotType, const int pluginIndex);
		bool clearPluginOnSlot (const int slotNumber, const bool deleteEditor=true);
		ShredderPlugin *getPluginOnSlot (const int slotNumber);
		void processPlugins(AudioSampleBuffer& buffer, MidiBuffer& midiMessages, const AudioPlayHead::CurrentPositionInfo &lastPosInfo);
		void setSoloSlot (const int newSoloSlot);
		const int getSoloSlot();

		/* public properties for faster access */
		float currentRmsValue[2];
		PropertySet shredderProperties;
		AudioPluginFormatManager pluginFormatManager;
		OwnedArray <PluginDescription> pluginsToUse;
		AudioPlayHead::CurrentPositionInfo lastPosInfo;

	    juce_UseDebuggingNewOperator
	
	private:
		/* default properties */
		int savedSamplesPerBlock;
		double savedSampleRate;
		PropertySet shredderDefaults;
		OwnedArray <ShredderPlugin, CriticalSection> loadedPlugins;
};

#endif  // __PLUGINPROCESSOR_H_526ED7A9__
