/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  20 May 2010 11:31:35pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDERSLOT_SHREDDERSLOT_2B138642__
#define __JUCER_HEADER_SHREDDERSLOT_SHREDDERSLOT_2B138642__

//[Headers]     -- You can add your own extra header files here --
#include "Includes.h"
#include "ImageToggleButton.h"
#include "ImageSlider.h"
#include "ShredderResources.h"
#include "Shredder.h"
#include "ShredderPluginEditor.h"
#include "FSerializedTypeface.h"

class ShredderEditor;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ShredderSlot  : public Component,
                      public ButtonListener,
                      public SliderListener
{
public:
    //==============================================================================
    ShredderSlot (ShredderEditor *_shredderEditor, Shredder *_shredder);
    ~ShredderSlot();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setSlotNumber (const int _slotNumber);
	void reloadState();
	void setLength(const int _length);
	void step (Button *stepButton);
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
	ImageToggleButton stepButton;
	Shredder *shredder;
	ShredderEditor *shredderEditor;
	int slotNumber;
	ShredderPluginEditor *shredderPluginEditor;
	int length;
	FSerializedTypeface serializedSekuntiaTf;
	Typeface *sekuntiaTf;
	Array <ToggleButton*> steps;
	ImageSlider whiteKnob;
	ImageToggleButton onOffButton;
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent;
    ToggleButton* step1;
    ToggleButton* step2;
    ToggleButton* step3;
    ToggleButton* step4;
    ToggleButton* step5;
    ToggleButton* step6;
    ToggleButton* step7;
    ToggleButton* step8;
    ToggleButton* step9;
    ToggleButton* step10;
    ToggleButton* step11;
    ToggleButton* step12;
    ToggleButton* step13;
    ToggleButton* step14;
    ToggleButton* step15;
    ToggleButton* step16;
    ImageButton* pluginMenu;
    ImageButton* pluginEditor;
    Label* pluginName;
    Slider* fadeSlider;
    ToggleButton* processButton;
    Slider* attack;
    Slider* decay;
    Slider* sustain;
    Slider* release;
    Slider* mix;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ShredderSlot (const ShredderSlot&);
    const ShredderSlot& operator= (const ShredderSlot&);
};


#endif   // __JUCER_HEADER_SHREDDERSLOT_SHREDDERSLOT_2B138642__
