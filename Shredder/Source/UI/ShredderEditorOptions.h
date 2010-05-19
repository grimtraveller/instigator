/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  17 May 2010 9:51:50pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDEREDITOROPTIONS_SHREDDEREDITOROPTIONS_83940AC4__
#define __JUCER_HEADER_SHREDDEREDITOROPTIONS_SHREDDEREDITOROPTIONS_83940AC4__

//[Headers]     -- You can add your own extra header files here --
#include "Includes.h"
#include "Shredder.h"
class ShredderEditor;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ShredderEditorOptions  : public Component,
                               public ThreadWithProgressWindow,
                               public ButtonListener
{
public:
    //==============================================================================
    ShredderEditorOptions (ShredderEditor *_shredderEditor, Shredder *_shredder);
    ~ShredderEditorOptions();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void run();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Shredder *shredder;
	StringArray foundPlugins;
	ShredderEditor *shredderEditor;
    //[/UserVariables]

    //==============================================================================
    TextEditor* pathText;
    TextButton* browseButton;
    Label* label;
    TextButton* rescanButton;
    Label* progressLabel;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ShredderEditorOptions (const ShredderEditorOptions&);
    const ShredderEditorOptions& operator= (const ShredderEditorOptions&);
};


#endif   // __JUCER_HEADER_SHREDDEREDITOROPTIONS_SHREDDEREDITOROPTIONS_83940AC4__
