#ifndef __JUCE_PLUGIN_CHARACTERISTICS_H__
#define __JUCE_PLUGIN_CHARACTERISTICS_H__


#define JucePlugin_Name								"Shredder"
#define JucePlugin_Desc								"Instigator - Shredder"
#define JucePlugin_Manufacturer						"Instigator"
#define JucePlugin_ManufacturerCode					'insr'
#define JucePlugin_PluginCode						'shr0'
#define JucePlugin_MaxNumInputChannels              2
#define JucePlugin_MaxNumOutputChannels             2
#define JucePlugin_PreferredChannelConfigurations   { 1, 1 }, { 2, 2 }
#define JucePlugin_IsSynth                          0
#define JucePlugin_WantsMidiInput                   0
#define JucePlugin_ProducesMidiOutput               0
#define JucePlugin_SilenceInProducesSilenceOut      0
#define JucePlugin_TailLengthSeconds                0
#define JucePlugin_EditorRequiresKeyboardFocus      1
#define JucePlugin_VersionCode						0x00010100
#define JucePlugin_VersionString					"1.0"

/* VST */

#define JUCE_USE_VSTSDK_2_4							1
#define JucePlugin_VSTUniqueID						JucePlugin_PluginCode

#if JucePlugin_IsSynth
  #define JucePlugin_VSTCategory					kPlugCategSynth
#else
  #define JucePlugin_VSTCategory					kPlugCategEffect
#endif

/* AU */

#if JucePlugin_IsSynth
  #define JucePlugin_AUMainType						kAudioUnitType_MusicDevice
#else
  #define JucePlugin_AUMainType						kAudioUnitType_Effect
#endif

#define JucePlugin_AUSubType						JucePlugin_PluginCode
#define JucePlugin_AUExportPrefix					ShredderAU
#define JucePlugin_AUExportPrefixQuoted				"ShredderAU"
#define JucePlugin_AUManufacturerCode				JucePlugin_ManufacturerCode
#define JucePlugin_CFBundleIdentifier				"com.edo.Shredder"
#define JucePlugin_AUCocoaViewClassName				JuceDemoAU_V1

#endif
