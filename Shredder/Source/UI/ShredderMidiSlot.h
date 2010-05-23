/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  23 May 2010 10:33:22pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDERMIDISLOT_SHREDDERMIDISLOT_E15E2152__
#define __JUCER_HEADER_SHREDDERMIDISLOT_SHREDDERMIDISLOT_E15E2152__

//[Headers]     -- You can add your own extra header files here --
#include "Includes.h"
#include "ImageToggleButton.h"
#include "ImageSlider.h"
#include "ShredderResources.h"
#include "Shredder.h"
#include "ShredderPluginEditor.h"

class ShredderEditor;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ShredderMidiSlot  : public Component,
                          public ChangeListener,
                          public ChangeBroadcaster,
                          public MidiKeyboardStateListener,
                          public ButtonListener,
                          public SliderListener
{
public:
    //==============================================================================
    ShredderMidiSlot (ShredderEditor *_shredderEditor, Shredder *_shredder);
    ~ShredderMidiSlot();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setSlotNumber (const int _slotNumber);
	void reloadState();
	void changeListenerCallback (void* objectThatHasChanged);
	void handleNoteOn (MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity);
	void handleNoteOff (MidiKeyboardState* source, int midiChannel, int midiNoteNumber);
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
    static const char* midi_png;
    static const int midi_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ImageToggleButton stepButton;
	Shredder *shredder;
	ShredderEditor *shredderEditor;
	int slotNumber;
	ShredderPluginEditor *shredderPluginEditor;
	ImageSlider whiteKnob;
	ImageToggleButton greenButton, blueButton, yellowButton, whiteButton;
	MidiKeyboardState midiKeyboardState;
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent;
    ImageButton* pluginMenu;
    ImageButton* pluginEditor;
    Label* pluginName;
    ToggleButton* processButton;
    Slider* dryLevel;
    ToggleButton* soloButton;
    Label* label;
    Label* label7;
    Label* label8;
    Slider* wetLevel;
    Label* label9;
    ToggleButton* directButton;
    Label* label10;
    ImageButton* midiNoteButton;
    Label* midiNoteLabel;
    Slider* midiChannel;
    Label* label3;
    ToggleButton* matchVelo;
    Label* label4;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ShredderMidiSlot (const ShredderMidiSlot&);
    const ShredderMidiSlot& operator= (const ShredderMidiSlot&);
};


#endif   // __JUCER_HEADER_SHREDDERMIDISLOT_SHREDDERMIDISLOT_E15E2152__
