/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  21 May 2010 2:55:55pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDEREDITOROPTIONS_SHREDDEREDITOROPTIONS_66417E4A__
#define __JUCER_HEADER_SHREDDEREDITOROPTIONS_SHREDDEREDITOROPTIONS_66417E4A__

//[Headers]     -- You can add your own extra header files here --
#include "Includes.h"
#include "Shredder.h"
class ShredderEditor;

#define SHREDDER_PLUGIN_MODE		T("pluginMode")
#define SHREDDER_PLUGIN_FILE_MODE	1
#define SHREDDER_PLUGIN_DIR_MODE	2

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
                               public TableListBoxModel,
                               public ButtonListener
{
public:
    //==============================================================================
    ShredderEditorOptions (ShredderEditor *_shredderEditor, Shredder *_shredder);
    ~ShredderEditorOptions();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void run();
	int getNumRows();
	void paintCell (Graphics& g,int rowNumber,int columnId,int width, int height,bool rowIsSelected);
	void paintRowBackground (Graphics& g, int rowNumber, int width, int height, bool rowIsSelected);
	const bool validatePlugin (const File &pluginFile);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Shredder *shredder;
	StringArray foundPluginsDir;
	StringArray foundPluginsFiles;
	ShredderEditor *shredderEditor;
	File lastBrowsedLocation;
	AudioPluginFormat *vstAudioPluginFormat;
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent2;
    GroupComponent* groupComponent;
    TextEditor* pathText;
    TextButton* browseButton;
    Label* label;
    TextButton* rescanButton;
    Label* progressLabel;
    TextButton* saveCache;
    ToggleButton* toggleDirMode;
    Label* label2;
    ToggleButton* toggleFileMode;
    TableListBox* filePluginList;
    TextButton* filePluginAdd;
    TextButton* filePluginRemove;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ShredderEditorOptions (const ShredderEditorOptions&);
    const ShredderEditorOptions& operator= (const ShredderEditorOptions&);
};


#endif   // __JUCER_HEADER_SHREDDEREDITOROPTIONS_SHREDDEREDITOROPTIONS_66417E4A__
