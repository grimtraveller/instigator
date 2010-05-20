/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  20 May 2010 12:56:41am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDEREDITOR_SHREDDEREDITOR_187FE5D__
#define __JUCER_HEADER_SHREDDEREDITOR_SHREDDEREDITOR_187FE5D__

//[Headers]     -- You can add your own extra header files here --
#include "Includes.h"
#include "ShredderEditorOptions.h"
#include "ShredderPluginEditor.h"
#include "ShredderResources.h"
#include "../../../About/Instigator.h"
//[/Headers]

#include "ShredderSlot.h"
#include "ShredderPeakSlot.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ShredderEditor  : public AudioProcessorEditor,
                        public ChangeListener,
                        public ButtonListener
{
public:
    //==============================================================================
    ShredderEditor (AudioProcessor *_shredder);
    ~ShredderEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void reloadLists();
	void closePluginEditor (ShredderPluginEditor *editorToClose);
	PopupMenu &getPluginMenu() { return (pluginMenu); }
	void changeListenerCallback (void* objectThatHasChanged);
	void toggleLed(const int ledIndex);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* name_png;
    static const int name_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ImageToggleButton ledButton;
	ShredderEditorOptions shredderOptions;
	Shredder *shredder;
	OwnedArray <ShredderPluginEditor> editors;
	Image* backgroundImage;
	PopupMenu pluginMenu;
	int lastBeat;
	Array <ToggleButton*>leds;
	Instigator instigator;
    //[/UserVariables]

    //==============================================================================
    ShredderSlot* slot1;
    ShredderSlot* slot2;
    ToggleButton* led1;
    TextButton* optionsButton;
    ShredderSlot* slot3;
    ShredderSlot* slot4;
    ToggleButton* led2;
    ToggleButton* led3;
    ToggleButton* led4;
    ToggleButton* led5;
    ToggleButton* led6;
    ToggleButton* led7;
    ToggleButton* led8;
    ToggleButton* led9;
    ToggleButton* led10;
    ToggleButton* led11;
    ToggleButton* led12;
    ToggleButton* led13;
    ToggleButton* led14;
    ToggleButton* led15;
    ToggleButton* led16;
    Label* positionInfo;
    ShredderPeakSlot* component;
    ImageButton* instigatorBtn;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ShredderEditor (const ShredderEditor&);
    const ShredderEditor& operator= (const ShredderEditor&);
};


#endif   // __JUCER_HEADER_SHREDDEREDITOR_SHREDDEREDITOR_187FE5D__
