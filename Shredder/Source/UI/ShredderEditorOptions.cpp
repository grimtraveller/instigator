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

//[Headers] You can add your own extra header files here...
#include "ShredderEditor.h"
//[/Headers]

#include "ShredderEditorOptions.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ShredderEditorOptions::ShredderEditorOptions (ShredderEditor *_shredderEditor, Shredder *_shredder)
    : vstAudioPluginFormat(0), shredder(_shredder), shredderEditor(_shredderEditor), ThreadWithProgressWindow(T("Plugin cache update"), true, true),
      groupComponent2 (0),
      groupComponent (0),
      pathText (0),
      browseButton (0),
      label (0),
      rescanButton (0),
      progressLabel (0),
      saveCache (0),
      toggleDirMode (0),
      label2 (0),
      toggleFileMode (0),
      filePluginList (0),
      filePluginAdd (0),
      filePluginRemove (0)
{
    addAndMakeVisible (groupComponent2 = new GroupComponent (T("new group"),
                                                             String::empty));
    groupComponent2->setColour (GroupComponent::outlineColourId, Colour (0xcdffffff));

    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            String::empty));
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0xcfffffff));

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

    addAndMakeVisible (saveCache = new TextButton (T("saveCache")));
    saveCache->setButtonText (T("Save Cache"));
    saveCache->addButtonListener (this);
    saveCache->setColour (TextButton::buttonColourId, Colour (0xffdaffbb));

    addAndMakeVisible (toggleDirMode = new ToggleButton (T("toggleDirMode")));
    toggleDirMode->setButtonText (T("Directory"));
    toggleDirMode->setRadioGroupId (1);
    toggleDirMode->addButtonListener (this);

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Plugin files")));
    label2->setFont (Font (15.0000f, Font::bold));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (toggleFileMode = new ToggleButton (T("toggleFileMode")));
    toggleFileMode->setButtonText (T("Files"));
    toggleFileMode->setRadioGroupId (1);
    toggleFileMode->addButtonListener (this);

    addAndMakeVisible (filePluginList = new TableListBox (T("Plugin List"), this));
    filePluginList->setName (T("filePluginList"));

    addAndMakeVisible (filePluginAdd = new TextButton (T("filePluginAdd")));
    filePluginAdd->setButtonText (T("Add"));
    filePluginAdd->addButtonListener (this);
    filePluginAdd->setColour (TextButton::buttonColourId, Colour (0xffbbffbf));

    addAndMakeVisible (filePluginRemove = new TextButton (T("filePluginRemove")));
    filePluginRemove->setButtonText (T("Remove"));
    filePluginRemove->addButtonListener (this);
    filePluginRemove->setColour (TextButton::buttonColourId, Colour (0xffffbbbb));


    //[UserPreSize]
	filePluginList->setHeaderHeight (16);
	filePluginList->getHeader()->addColumn (T("Name"),		1, 100, 70, 150);
	filePluginList->getHeader()->addColumn (T("Vendor"),	2, 50, 50, 150);
	filePluginList->getHeader()->addColumn (T("Category"),		3, 50,  50, 150);
	filePluginList->getHeader()->addColumn (T("Version"),		4, 50,  50, 150);
	filePluginList->getHeader()->setStretchToFitActive (true);

	vstAudioPluginFormat = shredder->pluginFormatManager.getFormat(0); /* should be vst */

	if (vstAudioPluginFormat == 0)
	{
		AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("Error"), T("No plugin formats support found"));
		return;
	}

	progressLabel->setFont (Font(14));
	pathText->setText (shredder->shredderProperties.getValue (T("vstPluginDir"), String::empty), false);
    //[/UserPreSize]

    setSize (400, 400);

    //[Constructor] You can add your own custom stuff here..
	if (shredder->shredderProperties.getIntValue (SHREDDER_PLUGIN_MODE) == SHREDDER_PLUGIN_FILE_MODE)
	{
		filePluginAdd->setEnabled (true);
		filePluginRemove->setEnabled (true);
		filePluginList->setEnabled (true);

		rescanButton->setEnabled (false);
		browseButton->setEnabled (false);
		toggleFileMode->setToggleState (true, false);

		filePluginList->updateContent();
	}
	else if (shredder->shredderProperties.getIntValue (SHREDDER_PLUGIN_MODE) == SHREDDER_PLUGIN_DIR_MODE)
	{
		filePluginAdd->setEnabled (false);
		filePluginRemove->setEnabled (false);
		filePluginList->setEnabled (false);

		rescanButton->setEnabled (true);
		browseButton->setEnabled (true);
		toggleDirMode->setToggleState (true, false);

		filePluginList->updateContent();
	}
    //[/Constructor]
}

ShredderEditorOptions::~ShredderEditorOptions()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent2);
    deleteAndZero (groupComponent);
    deleteAndZero (pathText);
    deleteAndZero (browseButton);
    deleteAndZero (label);
    deleteAndZero (rescanButton);
    deleteAndZero (progressLabel);
    deleteAndZero (saveCache);
    deleteAndZero (toggleDirMode);
    deleteAndZero (label2);
    deleteAndZero (toggleFileMode);
    deleteAndZero (filePluginList);
    deleteAndZero (filePluginAdd);
    deleteAndZero (filePluginRemove);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ShredderEditorOptions::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.setGradientFill (ColourGradient (Colour (0xffcecece),
                                       (float) ((getWidth() / 2)), 0.0f,
                                       Colour (0xffababab),
                                       (float) ((getWidth() / 2)), (float) (getHeight()),
                                       false));
    g.fillRect (0, 0, getWidth() - 0, getHeight() - 0);

    g.setColour (Colour (0xff6c6c6c));
    g.drawRect (0, 0, getWidth() - 0, getHeight() - 0, 2);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ShredderEditorOptions::resized()
{
    groupComponent2->setBounds (8, 120, 384, 248);
    groupComponent->setBounds (8, 8, 384, 120);
    pathText->setBounds (16, 48, 312, 24);
    browseButton->setBounds (328, 48, 56, 24);
    label->setBounds (16, 24, 150, 24);
    rescanButton->setBounds (320, 96, 64, 24);
    progressLabel->setBounds (104, 80, 208, 40);
    saveCache->setBounds (152, 370, 88, 24);
    toggleDirMode->setBounds (16, 96, 95, 24);
    label2->setBounds (16, 136, 96, 24);
    toggleFileMode->setBounds (16, 336, 95, 24);
    filePluginList->setBounds (24, 160, 352, 168);
    filePluginAdd->setBounds (320, 336, 64, 24);
    filePluginRemove->setBounds (248, 336, 64, 24);
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
		filePluginAdd->setEnabled (false);
		filePluginRemove->setEnabled (false);
		filePluginList->setEnabled (false);
		toggleDirMode->setToggleState (true, false);

		FileChooser myChooser ("Select VST directory", lastBrowsedLocation, "*.*");

		if (myChooser.browseForDirectory())
        {
			lastBrowsedLocation = myChooser.getResult();

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
		filePluginAdd->setEnabled (false);
		filePluginRemove->setEnabled (false);
		filePluginList->setEnabled (false);
		toggleDirMode->setToggleState (true, false);

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
    else if (buttonThatWasClicked == saveCache)
    {
        //[UserButtonCode_saveCache] -- add your button handler code here..
		File sharedSettingsFile = _cacheFile();
		if (sharedSettingsFile.existsAsFile())
		{
			const int ret = AlertWindow::showOkCancelBox (AlertWindow::WarningIcon, T("Overwrite"), T("Settings already exist, would you like to overwrite them?"), T("Yes"), T("No"));
			if (ret)
			{
				if (shredder->dumpPluginCache (sharedSettingsFile))
				{
					AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("Plugin cache"), T("Wrote shared plugin cache to: ") + sharedSettingsFile.getFullPathName());
				}
			}
		}
		else
		{
			if (sharedSettingsFile.hasWriteAccess ())
			{
				if (shredder->dumpPluginCache (sharedSettingsFile))
				{
					AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("Plugin cache"), T("Wrote shared plugin cache to: ") + sharedSettingsFile.getFullPathName());
				}
			}
			else
			{
				AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("Can't write"), T("I can't write to the common settings file: ") + sharedSettingsFile.getFullPathName());
				return;
			}
		}
        //[/UserButtonCode_saveCache]
    }
    else if (buttonThatWasClicked == toggleDirMode)
    {
        //[UserButtonCode_toggleDirMode] -- add your button handler code here..
		shredder->pluginsToUse.clear();

		filePluginAdd->setEnabled (false);
		filePluginRemove->setEnabled (false);
		filePluginList->setEnabled (false);

		rescanButton->setEnabled (true);
		browseButton->setEnabled (true);

		filePluginList->updateContent();

		shredder->shredderProperties.setValue (SHREDDER_PLUGIN_MODE, SHREDDER_PLUGIN_DIR_MODE);
        //[/UserButtonCode_toggleDirMode]
    }
    else if (buttonThatWasClicked == toggleFileMode)
    {
        //[UserButtonCode_toggleFileMode] -- add your button handler code here..
		shredder->pluginsToUse.clear();

		filePluginAdd->setEnabled (true);
		filePluginRemove->setEnabled (true);
		filePluginList->setEnabled (true);

		rescanButton->setEnabled (false);
		browseButton->setEnabled (false);

		filePluginList->updateContent();

		shredder->shredderProperties.setValue (SHREDDER_PLUGIN_MODE, SHREDDER_PLUGIN_FILE_MODE);
        //[/UserButtonCode_toggleFileMode]
    }
    else if (buttonThatWasClicked == filePluginAdd)
    {
        //[UserButtonCode_filePluginAdd] -- add your button handler code here..
		rescanButton->setEnabled (false);
		browseButton->setEnabled (false);
		toggleFileMode->setToggleState (true, false);

		FileChooser myChooser ("Select VST file", lastBrowsedLocation, "*.*");

		if (myChooser.browseForMultipleFilesToOpen())
        {
			Array <File> res = myChooser.getResults();
			lastBrowsedLocation = res[0].getParentDirectory();

			for (int i=0; i<res.size(); i++)
			{
				if (!validatePlugin (res[i]))
				{
					AlertWindow::showMessageBox (AlertWindow::WarningIcon, T("Plugin validation"), T("Plugin ") + res[i].getFullPathName() + T(" failed to validate, disabled"));
				}
			}

			filePluginList->updateContent();
			shredderEditor->reloadLists();
		}
        //[/UserButtonCode_filePluginAdd]
    }
    else if (buttonThatWasClicked == filePluginRemove)
    {
        //[UserButtonCode_filePluginRemove] -- add your button handler code here..
		rescanButton->setEnabled (false);
		browseButton->setEnabled (false);
		toggleFileMode->setToggleState (true, false);

		SparseSet<int> s = filePluginList->getSelectedRows();
		if (s.size() > 0)
		{
			for (int i=0; i<s.size(); i++)
			{
				if (shredder->pluginsToUse[i])
				{
					shredder->pluginsToUse.remove (i);
				}
			}

			filePluginList->updateContent();
			shredderEditor->reloadLists();
		}
        //[/UserButtonCode_filePluginRemove]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
const bool ShredderEditorOptions::validatePlugin (const File &pluginFile)
{
	if (pluginFile.existsAsFile() && vstAudioPluginFormat != 0)
	{
		shredder->getCallbackLock().enter();

		const int pre	= shredder->pluginsToUse.size();
		vstAudioPluginFormat->findAllTypesForFile (shredder->pluginsToUse, pluginFile.getFullPathName());
		const int post	= shredder->pluginsToUse.size();

		shredder->getCallbackLock().exit();

		if (post > pre)
		{
			return (true);
		}
	}

	return (false);
}

void ShredderEditorOptions::run()
{
	if (vstAudioPluginFormat == 0)
		return;

	FileSearchPath pluginLocations (shredder->shredderProperties.getValue (T("vstPluginDir"), String::empty));

	setStatusMessage (T("Scanning directory for possible files"));
	setProgress (-1);

	shredder->getCallbackLock().enter();
	foundPluginsDir = vstAudioPluginFormat->searchPathsForPlugins (pluginLocations, true);
	shredder->getCallbackLock().exit();

	for (int i=0; i<foundPluginsDir.size(); i++)
	{
		if (threadShouldExit())
			return;

		setStatusMessage (foundPluginsDir[i]);
		setProgress ((double)i/(double)foundPluginsDir.size());

		shredder->getCallbackLock().enter();
		vstAudioPluginFormat->findAllTypesForFile (shredder->pluginsToUse, foundPluginsDir[i]);
		shredder->getCallbackLock().exit();
	}

	return;
}

int ShredderEditorOptions::getNumRows()
{
	return (shredder->pluginsToUse.size());
}

void ShredderEditorOptions::paintCell (Graphics& g,int rowNumber,int columnId,int width, int height,bool rowIsSelected)
{
	switch (columnId)
	{
		case 1:
			g.setFont (12);
			g.setColour (Colours::black);
			g.drawFittedText (shredder->pluginsToUse[rowNumber]->name, 0, 0, width, height, Justification::centred, 2);
			break;

		case 2:
			g.setFont (12);
			g.setColour (Colours::black);
			g.drawFittedText (shredder->pluginsToUse[rowNumber]->manufacturerName, 0, 0, width, height, Justification::centred, 2);
			break;

		case 3:
			g.setFont (12);
			g.setColour (Colours::black);
			g.drawFittedText (shredder->pluginsToUse[rowNumber]->category, 0, 0, width, height, Justification::centred, 2);
			break;

		case 4:
			g.setFont (12);
			g.setColour (Colours::black);
			g.drawFittedText (shredder->pluginsToUse[rowNumber]->version, 0, 0, width, height, Justification::centred, 2);
			break;
	}
}

void ShredderEditorOptions::paintRowBackground (Graphics& g, int rowNumber, int width, int height, bool rowIsSelected)
{
	if (rowIsSelected)
	{
		g.fillAll (Colours::lightblue);
	}
	else
	{
		g.fillAll (Colours::white);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ShredderEditorOptions" componentName=""
                 parentClasses="public Component, public ThreadWithProgressWindow, public TableListBoxModel"
                 constructorParams="ShredderEditor *_shredderEditor, Shredder *_shredder"
                 variableInitialisers="vstAudioPluginFormat(0), shredder(_shredder), shredderEditor(_shredderEditor), ThreadWithProgressWindow(T(&quot;Plugin cache update&quot;), true, true), "
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="0">
    <RECT pos="0 0 0M 0M" fill="linear: 0C 0, 0C 0R, 0=ffcecece, 1=ffababab"
          hasStroke="1" stroke="2, mitered, butt" strokeColour="solid: ff6c6c6c"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="e3aa2771d8ff1cb6" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="8 120 384 248" outlinecol="cdffffff"
                  title=""/>
  <GROUPCOMPONENT name="new group" id="46a47b2991c4eec8" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 8 384 120" outlinecol="cfffffff"
                  title=""/>
  <TEXTEDITOR name="pathText" id="efbf0322b70669ce" memberName="pathText" virtualName=""
              explicitFocusOrder="0" pos="16 48 312 24" outlinecol="97000000"
              shadowcol="0" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="browseButton" id="27fd7f8c89652503" memberName="browseButton"
              virtualName="" explicitFocusOrder="0" pos="328 48 56 24" buttonText="Browse"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="d0fc04b672272c13" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 24 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Plugin directory" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <TEXTBUTTON name="rescanButton" id="46e5346469d0dfdf" memberName="rescanButton"
              virtualName="" explicitFocusOrder="0" pos="320 96 64 24" bgColOff="ffbbffbf"
              buttonText="Rescan" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="progressLabel" id="b97a778d39c0a2ff" memberName="progressLabel"
         virtualName="" explicitFocusOrder="0" pos="104 80 208 40" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="1" italic="0" justification="36"/>
  <TEXTBUTTON name="saveCache" id="e8f77abc82cd4220" memberName="saveCache"
              virtualName="" explicitFocusOrder="0" pos="152 370 88 24" bgColOff="ffdaffbb"
              buttonText="Save Cache" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="toggleDirMode" id="8d23db2bad47fa5" memberName="toggleDirMode"
                virtualName="" explicitFocusOrder="0" pos="16 96 95 24" buttonText="Directory"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <LABEL name="new label" id="bf2f7b0680fd1553" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="16 136 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Plugin files" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <TOGGLEBUTTON name="toggleFileMode" id="3edef8a430c0cbc6" memberName="toggleFileMode"
                virtualName="" explicitFocusOrder="0" pos="16 336 95 24" buttonText="Files"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <GENERICCOMPONENT name="filePluginList" id="5537719841ddf9f1" memberName="filePluginList"
                    virtualName="" explicitFocusOrder="0" pos="24 160 352 168" class="TableListBox"
                    params="T(&quot;Plugin List&quot;), this"/>
  <TEXTBUTTON name="filePluginAdd" id="7ef5d66f44fd655a" memberName="filePluginAdd"
              virtualName="" explicitFocusOrder="0" pos="320 336 64 24" bgColOff="ffbbffbf"
              buttonText="Add" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="filePluginRemove" id="51edbccf9c47ec24" memberName="filePluginRemove"
              virtualName="" explicitFocusOrder="0" pos="248 336 64 24" bgColOff="ffffbbbb"
              buttonText="Remove" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
