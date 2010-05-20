/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  20 May 2010 4:12:59pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDERPEAKSLOT_SHREDDERPEAKSLOT_8E7DEE37__
#define __JUCER_HEADER_SHREDDERPEAKSLOT_SHREDDERPEAKSLOT_8E7DEE37__

//[Headers]     -- You can add your own extra header files here --
#include "Includes.h"
#include "ImageToggleButton.h"
#include "ImageSlider.h"
#include "ShredderResources.h"
#include "Shredder.h"
#include "ShredderPluginEditor.h"
#include "FSerializedTypeface.h"
#include "ShredderRMSMeter.h"
class ShredderEditor;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ShredderPeakSlot  : public Component,
                          public ChangeListener,
                          public ButtonListener,
                          public SliderListener
{
public:
    //==============================================================================
    ShredderPeakSlot (ShredderEditor *_shredderEditor, Shredder *_shredder);
    ~ShredderPeakSlot();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void changeListenerCallback (void* objectThatHasChanged);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);

    // Binary resources:
    static const char* plugin_editor_png;
    static const int plugin_editor_pngSize;
    static const char* plugin_loaded_png;
    static const int plugin_loaded_pngSize;
    static const char* plugin_unloaded_png;
    static const int plugin_unloaded_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ImageSlider stepSlider;
	Shredder *shredder;
	ShredderEditor *shredderEditor;
	int slotNumber;
	ShredderPluginEditor *shredderPluginEditor;
	int length;
	FSerializedTypeface serializedSekuntiaTf;
	Typeface *sekuntiaTf;
	Array <ToggleButton*> steps;
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent;
    ImageButton* pluginMenu;
    ImageButton* pluginEditor;
    Label* pluginName;
    ToggleButton* processButton;
    Slider* slider;
    ShredderRMSMeter* rmsMeterL;
    ShredderRMSMeter* rmsMeterR;
    Label* label;
    Label* label2;
    Slider* attack;
    Slider* decay;
    Slider* sustain;
    Slider* release;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ShredderPeakSlot (const ShredderPeakSlot&);
    const ShredderPeakSlot& operator= (const ShredderPeakSlot&);
};


#endif   // __JUCER_HEADER_SHREDDERPEAKSLOT_SHREDDERPEAKSLOT_8E7DEE37__
