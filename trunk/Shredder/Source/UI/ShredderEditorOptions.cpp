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

//[Headers] You can add your own extra header files here...
#include "ShredderEditor.h"
//[/Headers]

#include "ShredderEditorOptions.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ShredderEditorOptions::ShredderEditorOptions (ShredderEditor *_shredderEditor, Shredder *_shredder)
    : shredder(_shredder), shredderEditor(_shredderEditor), ThreadWithProgressWindow(T("Plugin cache update"), true, true),
      pathText (0),
      browseButton (0),
      label (0),
      rescanButton (0),
      progressLabel (0)
{
    addAndMakeVisible (pathText = new TextEditor (T("pathText")));
    pathText->setMultiLine (false);
    pathText->setReturnKeyStartsNewLine (false);
    pathText->setReadOnly (true);
    pathText->setScrollbarsShown (true);
    pathText->setCaretVisible (true);
    pathText->setPopupMenuEnabled (true);
    pathText->setColour (TextEditor::outlineColourId, Colour (0x97000000));
    pathText->setColour (TextEditor::shadowColourId, Colour (0x0));
    pathText->setText (String::empty);

    addAndMakeVisible (browseButton = new TextButton (T("browseButton")));
    browseButton->setButtonText (T("Browse"));
    browseButton->setConnectedEdges (Button::ConnectedOnLeft);
    browseButton->addButtonListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Plugin directory")));
    label->setFont (Font (15.0000f, Font::bold));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (rescanButton = new TextButton (T("rescanButton")));
    rescanButton->setButtonText (T("Rescan"));
    rescanButton->addButtonListener (this);
    rescanButton->setColour (TextButton::buttonColourId, Colour (0xffbbffbf));

    addAndMakeVisible (progressLabel = new Label (T("progressLabel"),
                                                  String::empty));
    progressLabel->setFont (Font (15.0000f, Font::bold));
    progressLabel->setJustificationType (Justification::centred);
    progressLabel->setEditable (false, false, false);
    progressLabel->setColour (TextEditor::textColourId, Colours::black);
    progressLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));


    //[UserPreSize]
	progressLabel->setFont (Font(14));
	pathText->setText (shredder->shredderProperties.getValue (T("vstPluginDir"), String::empty), false);
    //[/UserPreSize]

    setSize (400, 120);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ShredderEditorOptions::~ShredderEditorOptions()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (pathText);
    deleteAndZero (browseButton);
    deleteAndZero (label);
    deleteAndZero (rescanButton);
    deleteAndZero (progressLabel);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ShredderEditorOptions::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff767676));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ShredderEditorOptions::resized()
{
    pathText->setBounds (16, 32, 312, 24);
    browseButton->setBounds (328, 32, 56, 24);
    label->setBounds (16, 8, 150, 24);
    rescanButton->setBounds (288, 88, 102, 24);
    progressLabel->setBounds (16, 64, 264, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ShredderEditorOptions::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == browseButton)
    {
        //[UserButtonCode_browseButton] -- add your button handler code here..
		FileChooser myChooser ("Select VST directory",
                               File::getSpecialLocation (File::userHomeDirectory),
                               "*.*");

		if (myChooser.browseForDirectory())
        {
            File vstDir (myChooser.getResult());

			if (vstDir.isDirectory())
			{
				shredder->shredderProperties.setValue (T("vstPluginDir"), vstDir.getFullPathName());
				pathText->setText (shredder->shredderProperties.getValue (T("vstPluginDir"), String::empty), false);
			}
        }

        //[/UserButtonCode_browseButton]
    }
    else if (buttonThatWasClicked == rescanButton)
    {
        //[UserButtonCode_rescanButton] -- add your button handler code here..
		shredder->pluginsToUse.clear();

		if (!runThread())
		{
			progressLabel->setText (T("Search cancelled"), false);
		}
		else
		{
			progressLabel->setText (T("Found ") + String (shredder->pluginsToUse.size()) + T(" plugins"), false);
			shredderEditor->reloadLists();
		}
        //[/UserButtonCode_rescanButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ShredderEditorOptions::run()
{
	AudioPluginFormat *fmt = shredder->pluginFormatManager.getFormat(0); /* should be vst */

	if (fmt == 0)
	{
		AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("Error"), T("No plugin formats support found"));
		return;
	}
	FileSearchPath pluginLocations (shredder->shredderProperties.getValue (T("vstPluginDir"), String::empty));

	setStatusMessage (T("Scanning directory for possible files"));
	setProgress (-1);

	foundPlugins = fmt->searchPathsForPlugins (pluginLocations, true);

	for (int i=0; i<foundPlugins.size(); i++)
	{
		if (threadShouldExit())
			return;

		setStatusMessage (foundPlugins[i]);
		setProgress ((double)i/(double)foundPlugins.size());
		fmt->findAllTypesForFile (shredder->pluginsToUse, foundPlugins[i]);
	}

	return;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ShredderEditorOptions" componentName=""
                 parentClasses="public Component, public ThreadWithProgressWindow"
                 constructorParams="ShredderEditor *_shredderEditor, Shredder *_shredder"
                 variableInitialisers="shredder(_shredder), shredderEditor(_shredderEditor), ThreadWithProgressWindow(T(&quot;Plugin cache update&quot;), true, true), "
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="400" initialHeight="120">
  <BACKGROUND backgroundColour="ff767676"/>
  <TEXTEDITOR name="pathText" id="efbf0322b70669ce" memberName="pathText" virtualName=""
              explicitFocusOrder="0" pos="16 32 312 24" outlinecol="97000000"
              shadowcol="0" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="browseButton" id="27fd7f8c89652503" memberName="browseButton"
              virtualName="" explicitFocusOrder="0" pos="328 32 56 24" buttonText="Browse"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="d0fc04b672272c13" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Plugin directory" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <TEXTBUTTON name="rescanButton" id="46e5346469d0dfdf" memberName="rescanButton"
              virtualName="" explicitFocusOrder="0" pos="288 88 102 24" bgColOff="ffbbffbf"
              buttonText="Rescan" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="progressLabel" id="b97a778d39c0a2ff" memberName="progressLabel"
         virtualName="" explicitFocusOrder="0" pos="16 64 264 24" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="1" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
