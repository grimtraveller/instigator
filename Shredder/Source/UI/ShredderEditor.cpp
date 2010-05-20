/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  20 May 2010 9:26:54pm

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
//[/Headers]

#include "ShredderEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
Array <ComboBox *> getCombosByPrefix(Component *parentComponent, const String &prefix)
{
	Array <ComboBox *> result;

	for (int i=0; i<parentComponent->getNumChildComponents(); i++)
	{
		Component *c	= parentComponent->getChildComponent(i);
		ComboBox *cb	= dynamic_cast<ComboBox*>(c);
		if (cb!=NULL && cb->getName().startsWith (prefix))
			result.add (cb);
	}

	return (result);
}

Array <ToggleButton *> getToggleButtonsByPrefix(Component *parentComponent, const String &prefix)
{
	Array <ToggleButton *> result;

	for (int i=0; i<parentComponent->getNumChildComponents(); i++)
	{
		Component *c	= parentComponent->getChildComponent(i);
		ToggleButton *t	= dynamic_cast<ToggleButton*>(c);
		if (t!=NULL && t->getName().startsWith (prefix))
			result.add (t);
	}

	return (result);
}

Array <ToggleButton *> getToggleButtons (Component *parentComponent)
{
	Array <ToggleButton *> result;

	for (int i=0; i<parentComponent->getNumChildComponents(); i++)
	{
		Component *c	= parentComponent->getChildComponent(i);
		ToggleButton *t	= dynamic_cast<ToggleButton*>(c);
		if (t!=NULL)
			result.add (t);
	}

	return (result);
}

void applyLookAndFeelToToggleButtons (Component *parentComponent, const String &buttonPrefix, LookAndFeel *lookAndFeelToApply)
{
	Array <ToggleButton *>buttonsToChange = getToggleButtonsByPrefix (parentComponent, buttonPrefix);
	for (int i=0; i<buttonsToChange.size(); i++)
	{
		buttonsToChange[i]->setLookAndFeel (lookAndFeelToApply);
	}
}

void applyLookAndFeelToToggleButtons (Component *parentComponent, LookAndFeel *lookAndFeelToApply)
{
	Array <ToggleButton *>buttonsToChange = getToggleButtons (parentComponent);
	for (int i=0; i<buttonsToChange.size(); i++)
	{
		buttonsToChange[i]->setLookAndFeel (lookAndFeelToApply);
	}
}

Component *getComponentByName(Component *parentComponent, const String &componentName)
{
	for (int i=0; i<parentComponent->getNumChildComponents(); i++)
	{
		if (parentComponent->getChildComponent(i)->getName() == componentName)
			return (parentComponent->getChildComponent(i));
	}

	return (0);
}

void applyLookAndFeelToSliders (Component *parentComponent, LookAndFeel *lookAndFeelToApply)
{
	if (parentComponent == 0)
		return;

	for (int i=0; i<parentComponent->getNumChildComponents(); i++)
	{
		Component *ptr = parentComponent->getChildComponent(i);
		Slider *s = dynamic_cast<Slider*>(ptr);
		if (s!=0)
		{
			s->setLookAndFeel (lookAndFeelToApply);
		}
	}
}

void applyLookAndFeelToSliders (Component *parentComponent, const String &sliderPrefix, LookAndFeel *lookAndFeelToApply)
{
	Array <Slider *>slidersToChange = getSlidersByPrefix (parentComponent, sliderPrefix);
	for (int i=0; i<slidersToChange.size(); i++)
	{
		slidersToChange[i]->setLookAndFeel (lookAndFeelToApply);
	}
}

Array <Slider *> getSlidersByPrefix(Component *parentComponent, const String &prefix)
{
	Array <Slider *> result;

	for (int i=0; i<parentComponent->getNumChildComponents(); i++)
	{
		Component *c	= parentComponent->getChildComponent(i);
		Slider *s		= dynamic_cast<Slider*>(c);
		if (s!=NULL && s->getName().startsWith (prefix))
			result.add (s);
	}

	return (result);
}
//[/MiscUserDefs]

//==============================================================================
ShredderEditor::ShredderEditor (AudioProcessor *_shredder)
    : AudioProcessorEditor (_shredder), shredder((Shredder *)_shredder), shredderOptions(this, (Shredder *)_shredder),  ledButton(Pic(ShredderResources::btn_led_png, ShredderResources::btn_led_pngSize), Font(12)),
      slot1 (0),
      slot2 (0),
      led1 (0),
      optionsButton (0),
      slot3 (0),
      slot4 (0),
      led2 (0),
      led3 (0),
      led4 (0),
      led5 (0),
      led6 (0),
      led7 (0),
      led8 (0),
      led9 (0),
      led10 (0),
      led11 (0),
      led12 (0),
      led13 (0),
      led14 (0),
      led15 (0),
      led16 (0),
      positionInfo (0),
      component (0),
      instigatorBtn (0)
{
    addAndMakeVisible (slot1 = new ShredderSlot (this, shredder));
    addAndMakeVisible (slot2 = new ShredderSlot (this, shredder));
    addAndMakeVisible (led1 = new ToggleButton (T("led1")));
    led1->setButtonText (String::empty);
    led1->setRadioGroupId (2);

    addAndMakeVisible (optionsButton = new TextButton (T("optionsButton")));
    optionsButton->setButtonText (T("Options"));
    optionsButton->addButtonListener (this);

    addAndMakeVisible (slot3 = new ShredderSlot (this, shredder));
    addAndMakeVisible (slot4 = new ShredderSlot (this, shredder));
    addAndMakeVisible (led2 = new ToggleButton (T("led1")));
    led2->setButtonText (String::empty);
    led2->setRadioGroupId (2);

    addAndMakeVisible (led3 = new ToggleButton (T("led1")));
    led3->setButtonText (String::empty);
    led3->setRadioGroupId (2);

    addAndMakeVisible (led4 = new ToggleButton (T("led1")));
    led4->setButtonText (String::empty);
    led4->setRadioGroupId (2);

    addAndMakeVisible (led5 = new ToggleButton (T("led1")));
    led5->setButtonText (String::empty);
    led5->setRadioGroupId (2);

    addAndMakeVisible (led6 = new ToggleButton (T("led1")));
    led6->setButtonText (String::empty);
    led6->setRadioGroupId (2);

    addAndMakeVisible (led7 = new ToggleButton (T("led1")));
    led7->setButtonText (String::empty);
    led7->setRadioGroupId (2);

    addAndMakeVisible (led8 = new ToggleButton (T("led1")));
    led8->setButtonText (String::empty);
    led8->setRadioGroupId (2);

    addAndMakeVisible (led9 = new ToggleButton (T("led1")));
    led9->setButtonText (String::empty);
    led9->setRadioGroupId (2);

    addAndMakeVisible (led10 = new ToggleButton (T("led1")));
    led10->setButtonText (String::empty);
    led10->setRadioGroupId (2);

    addAndMakeVisible (led11 = new ToggleButton (T("led1")));
    led11->setButtonText (String::empty);
    led11->setRadioGroupId (2);

    addAndMakeVisible (led12 = new ToggleButton (T("led1")));
    led12->setButtonText (String::empty);
    led12->setRadioGroupId (2);

    addAndMakeVisible (led13 = new ToggleButton (T("led1")));
    led13->setButtonText (String::empty);
    led13->setRadioGroupId (2);

    addAndMakeVisible (led14 = new ToggleButton (T("led1")));
    led14->setButtonText (String::empty);
    led14->setRadioGroupId (2);

    addAndMakeVisible (led15 = new ToggleButton (T("led1")));
    led15->setButtonText (String::empty);
    led15->setRadioGroupId (2);

    addAndMakeVisible (led16 = new ToggleButton (T("led1")));
    led16->setButtonText (String::empty);
    led16->setRadioGroupId (2);

    addAndMakeVisible (positionInfo = new Label (T("positionInfo"),
                                                 String::empty));
    positionInfo->setFont (Font (Font::getDefaultMonospacedFontName(), 14.0000f, Font::bold));
    positionInfo->setJustificationType (Justification::centred);
    positionInfo->setEditable (false, false, false);
    positionInfo->setColour (Label::textColourId, Colours::white);
    positionInfo->setColour (TextEditor::textColourId, Colours::black);
    positionInfo->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (component = new ShredderPeakSlot (this, shredder));
    addAndMakeVisible (instigatorBtn = new ImageButton (T("instigatorBtn")));
    instigatorBtn->setButtonText (T("new button"));
    instigatorBtn->addButtonListener (this);

    instigatorBtn->setImages (false, true, true,
                              ImageCache::getFromMemory (name_png, name_pngSize), 1.0000f, Colour (0x0),
                              ImageCache::getFromMemory (name_png, name_pngSize), 1.0000f, Colour (0x0),
                              ImageCache::getFromMemory (name_png, name_pngSize), 1.0000f, Colour (0x0));

    //[UserPreSize]
	instigatorBtn->setMouseCursor (MouseCursor::PointingHandCursor);
	leds.add (led1);
	leds.add (led2);
	leds.add (led3);
	leds.add (led4);

	leds.add (led5);
	leds.add (led6);
	leds.add (led7);
	leds.add (led8);

	leds.add (led9);
	leds.add (led10);
	leds.add (led11);
	leds.add (led12);

	leds.add (led13);
	leds.add (led14);
	leds.add (led15);
	leds.add (led16);

	lastBeat = -1;

	shredder->addChangeListener (this);

	slot1->setSlotNumber (1);
	slot2->setSlotNumber (2);
	slot3->setSlotNumber (3);
	slot4->setSlotNumber (4);

	backgroundImage = ImageCache::getFromMemory (ShredderResources::shredder_bg_jpg, ShredderResources::shredder_bg_jpgSize);
	applyLookAndFeelToToggleButtons (this, T("led"), &ledButton);
    //[/UserPreSize]

    setSize (694, 560);

    //[Constructor] You can add your own custom stuff here..
	reloadLists();
    //[/Constructor]
}

ShredderEditor::~ShredderEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	shredder->removeChangeListener (this);
	ImageCache::release (backgroundImage);
    //[/Destructor_pre]

    deleteAndZero (slot1);
    deleteAndZero (slot2);
    deleteAndZero (led1);
    deleteAndZero (optionsButton);
    deleteAndZero (slot3);
    deleteAndZero (slot4);
    deleteAndZero (led2);
    deleteAndZero (led3);
    deleteAndZero (led4);
    deleteAndZero (led5);
    deleteAndZero (led6);
    deleteAndZero (led7);
    deleteAndZero (led8);
    deleteAndZero (led9);
    deleteAndZero (led10);
    deleteAndZero (led11);
    deleteAndZero (led12);
    deleteAndZero (led13);
    deleteAndZero (led14);
    deleteAndZero (led15);
    deleteAndZero (led16);
    deleteAndZero (positionInfo);
    deleteAndZero (component);
    deleteAndZero (instigatorBtn);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ShredderEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
	g.setColour (Colours::black.withAlpha (0.5f));
    g.drawImage (backgroundImage,
                 0, 0, getWidth() - 0, getHeight() - 0,
                 0, 0, backgroundImage->getWidth(), backgroundImage->getHeight());
    //[/UserPaint]
}

void ShredderEditor::resized()
{
    slot1->setBounds (8, 48, 680, 104);
    slot2->setBounds (8, 144, 680, 104);
    led1->setBounds (28, 16, 24, 24);
    optionsButton->setBounds (632, 536, 56, 16);
    slot3->setBounds (8, 240, 680, 104);
    slot4->setBounds (8, 336, 680, 104);
    led2->setBounds (68, 16, 24, 24);
    led3->setBounds (108, 16, 24, 24);
    led4->setBounds (148, 16, 24, 24);
    led5->setBounds (196, 16, 24, 24);
    led6->setBounds (236, 16, 24, 24);
    led7->setBounds (276, 16, 24, 24);
    led8->setBounds (316, 16, 24, 24);
    led9->setBounds (364, 16, 24, 24);
    led10->setBounds (404, 16, 24, 24);
    led11->setBounds (444, 16, 24, 24);
    led12->setBounds (484, 16, 24, 24);
    led13->setBounds (532, 16, 24, 24);
    led14->setBounds (572, 16, 24, 24);
    led15->setBounds (612, 16, 24, 24);
    led16->setBounds (652, 16, 24, 24);
    positionInfo->setBounds (16, 512, 600, 16);
    component->setBounds (8, 432, 680, 96);
    instigatorBtn->setBounds (472, 528, 150, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ShredderEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == optionsButton)
    {
        //[UserButtonCode_optionsButton] -- add your button handler code here..
		DialogWindow::showModalDialog (T("Options"), &shredderOptions, this, Colours::grey, true, false, false);
        //[/UserButtonCode_optionsButton]
    }
    else if (buttonThatWasClicked == instigatorBtn)
    {
        //[UserButtonCode_instigatorBtn] -- add your button handler code here..
		DialogWindow::showModalDialog (T("Instigator"), &instigator, this, Colours::white, true, false, false);
        //[/UserButtonCode_instigatorBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ShredderEditor::reloadLists()
{
	pluginMenu.clear();

	pluginMenu.addItem (1, T("--- Clear slot"));
	for (int i=0; i<shredder->pluginsToUse.size(); i++)
	{
		pluginMenu.addItem (i+2, shredder->pluginsToUse[i]->name);
	}
}

void ShredderEditor::closePluginEditor (ShredderPluginEditor *editorToClose)
{
	if (editors.contains (editorToClose))
	{
		editors.removeObject (editorToClose);
	}
}

void ShredderEditor::changeListenerCallback (void* objectThatHasChanged)
{
	if (objectThatHasChanged == shredder)
	{
		shredder->getCallbackLock().enter();
		AudioPlayHead::CurrentPositionInfo lastPosInfo = shredder->lastPosInfo;
		shredder->getCallbackLock().exit();


		const int ppqPerBar			= (lastPosInfo.timeSigNumerator * 4 / lastPosInfo.timeSigDenominator);
		const double beats			= (fmod (lastPosInfo.ppqPosition, ppqPerBar) / ppqPerBar) * lastPosInfo.timeSigNumerator;
		const int qnote				= ((int) (beats * lastPosInfo.timeSigDenominator)) + 1;

		if (qnote > lastBeat)
		{
			lastBeat++;

			toggleLed (lastBeat);
		}

		if (qnote < lastBeat)
		{
			if (lastBeat >= 16)
			{
				lastBeat = 1;

				toggleLed (lastBeat);
			}
		}

		// const String position = ppqToBarsBeatsString (lastPosInfo.ppqPosition, lastPosInfo.ppqPositionOfLastBarStart, lastPosInfo.timeSigNumerator, lastPosInfo.timeSigDenominator);
		// positionInfo->setText (position, false);
	}
}

void ShredderEditor::toggleLed(const int ledIndex)
{
	if (leds[ledIndex-1])
	{
		leds[ledIndex-1]->setToggleState (true, true);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ShredderEditor" componentName=""
                 parentClasses="public AudioProcessorEditor, public ChangeListener"
                 constructorParams="AudioProcessor *_shredder" variableInitialisers="AudioProcessorEditor (_shredder), shredder((Shredder *)_shredder), shredderOptions(this, (Shredder *)_shredder),  ledButton(Pic(ShredderResources::btn_led_png, ShredderResources::btn_led_pngSize), Font(12))"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="694" initialHeight="560">
  <BACKGROUND backgroundColour="ff000000"/>
  <JUCERCOMP name="" id="20ee16f709cc1227" memberName="slot1" virtualName=""
             explicitFocusOrder="0" pos="8 48 680 104" sourceFile="ShredderSlot.cpp"
             constructorParams="this, shredder"/>
  <JUCERCOMP name="" id="57879a0e1ebb336b" memberName="slot2" virtualName=""
             explicitFocusOrder="0" pos="8 144 680 104" sourceFile="ShredderSlot.cpp"
             constructorParams="this, shredder"/>
  <TOGGLEBUTTON name="led1" id="193b348dc9a4edc8" memberName="led1" virtualName=""
                explicitFocusOrder="0" pos="28 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TEXTBUTTON name="optionsButton" id="b434469d0c406758" memberName="optionsButton"
              virtualName="" explicitFocusOrder="0" pos="632 536 56 16" buttonText="Options"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <JUCERCOMP name="" id="81aa691ce23973a1" memberName="slot3" virtualName=""
             explicitFocusOrder="0" pos="8 240 680 104" sourceFile="ShredderSlot.cpp"
             constructorParams="this, shredder"/>
  <JUCERCOMP name="" id="41db2a1fd82f3df9" memberName="slot4" virtualName=""
             explicitFocusOrder="0" pos="8 336 680 104" sourceFile="ShredderSlot.cpp"
             constructorParams="this, shredder"/>
  <TOGGLEBUTTON name="led1" id="1f6d83f1fd1f4a9e" memberName="led2" virtualName=""
                explicitFocusOrder="0" pos="68 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="efd0e1b9ee8a8fa0" memberName="led3" virtualName=""
                explicitFocusOrder="0" pos="108 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="2817eba8cae577e7" memberName="led4" virtualName=""
                explicitFocusOrder="0" pos="148 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="7ae88231a0ff83b0" memberName="led5" virtualName=""
                explicitFocusOrder="0" pos="196 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="7afc4e04317d1450" memberName="led6" virtualName=""
                explicitFocusOrder="0" pos="236 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="45f90d9d0203ab5a" memberName="led7" virtualName=""
                explicitFocusOrder="0" pos="276 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="361df7b2bfb5371a" memberName="led8" virtualName=""
                explicitFocusOrder="0" pos="316 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="94683ba8e712fbfb" memberName="led9" virtualName=""
                explicitFocusOrder="0" pos="364 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="f89a9547b7db3028" memberName="led10" virtualName=""
                explicitFocusOrder="0" pos="404 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="887de7b09fb22d74" memberName="led11" virtualName=""
                explicitFocusOrder="0" pos="444 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="329c138da8125d7e" memberName="led12" virtualName=""
                explicitFocusOrder="0" pos="484 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="e7157c8b1e0c4410" memberName="led13" virtualName=""
                explicitFocusOrder="0" pos="532 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="7644f2053f124bc7" memberName="led14" virtualName=""
                explicitFocusOrder="0" pos="572 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="d7ecef01bba238f9" memberName="led15" virtualName=""
                explicitFocusOrder="0" pos="612 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="led1" id="19e4655f015866d2" memberName="led16" virtualName=""
                explicitFocusOrder="0" pos="652 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <LABEL name="positionInfo" id="6739761a4ee8528c" memberName="positionInfo"
         virtualName="" explicitFocusOrder="0" pos="16 512 600 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default monospaced font"
         fontsize="14" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="" id="247dadecbd83e3a2" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="8 432 680 96" sourceFile="ShredderPeakSlot.cpp"
             constructorParams="this, shredder"/>
  <IMAGEBUTTON name="instigatorBtn" id="ff9a1c64c500f952" memberName="instigatorBtn"
               virtualName="" explicitFocusOrder="0" pos="472 528 150 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="name_png" opacityNormal="1" colourNormal="0"
               resourceOver="name_png" opacityOver="1" colourOver="0" resourceDown="name_png"
               opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: name_png, 4534, "../../../About/name.png"
static const unsigned char resource_ShredderEditor_name_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,117,0,0,0,30,8,6,0,0,0,18,55,81,37,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,98,
75,71,68,0,0,0,0,0,0,249,67,187,127,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,218,5,19,22,55,42,166,42,84,200,0,0,0,25,116,69,88,116,67,111,109,109,101,110,116,0,
67,114,101,97,116,101,100,32,119,105,116,104,32,71,73,77,80,87,129,14,23,0,0,17,17,73,68,65,84,104,222,189,91,125,84,84,71,150,191,239,117,211,223,136,205,167,98,160,25,18,37,193,160,81,51,73,140,137,
102,163,32,33,142,198,76,212,68,140,158,56,201,113,199,213,201,138,58,49,38,155,232,33,230,156,217,236,184,230,160,115,116,18,77,50,49,31,155,68,141,160,104,190,36,160,168,12,120,176,85,64,17,36,32,208,
192,131,134,166,191,222,119,237,63,175,221,162,120,175,187,205,206,164,206,185,7,120,85,175,234,86,253,238,253,221,91,85,15,10,254,255,133,130,95,190,252,35,199,68,191,160,46,232,23,88,27,68,253,147,38,
65,253,204,201,80,255,100,240,209,47,108,108,232,23,52,244,91,99,209,183,169,48,165,242,183,154,104,189,75,221,206,123,12,195,76,148,36,105,231,205,155,55,83,177,54,180,138,232,118,239,222,109,169,174,
174,78,4,0,29,38,163,218,169,60,143,164,251,173,57,40,250,148,8,130,240,70,79,79,79,134,223,239,95,84,81,81,49,6,235,251,231,140,55,98,204,254,254,254,241,129,64,224,225,225,225,225,73,28,199,61,195,48,
204,164,40,215,139,186,29,167,32,59,210,82,92,7,0,250,127,144,196,4,2,129,231,16,66,30,132,16,26,30,30,126,10,0,12,0,96,16,69,241,75,73,146,90,60,30,79,1,0,24,235,235,235,51,68,81,60,129,16,146,17,66,
72,146,164,6,142,227,254,83,146,164,134,64,32,240,26,0,24,53,196,64,72,76,56,193,245,65,8,33,81,20,127,104,105,105,153,200,178,236,27,68,191,38,76,194,141,55,106,204,27,55,110,56,130,193,224,11,130,32,
28,8,6,131,235,3,129,192,10,65,16,62,209,208,41,180,86,163,12,71,31,14,77,65,16,158,162,40,106,170,78,167,211,125,249,229,151,111,61,246,216,99,9,118,187,253,97,73,146,0,0,196,211,167,79,255,152,155,155,
27,120,243,205,55,99,150,47,95,62,142,101,89,126,234,212,169,125,106,125,53,53,53,165,166,167,167,63,161,215,235,127,5,0,65,81,20,251,124,62,159,115,233,210,165,117,149,149,149,50,0,64,103,103,103,54,
77,211,49,9,9,9,207,27,12,134,245,161,119,245,122,125,118,117,117,117,253,172,89,179,250,100,89,78,212,233,116,177,44,203,154,179,179,179,99,114,114,114,14,235,116,186,105,183,168,135,166,179,13,6,67,
182,242,222,44,0,216,165,162,203,61,169,169,169,115,140,70,163,3,0,108,178,44,183,137,162,216,93,85,85,117,124,193,130,5,131,161,118,109,109,109,217,58,157,46,38,37,37,101,5,174,143,82,18,37,73,178,243,
60,207,3,128,174,190,190,126,210,228,201,147,255,228,241,120,14,33,132,144,201,100,74,209,235,245,14,154,166,199,116,119,119,255,37,51,51,179,22,167,201,25,51,102,80,123,246,236,73,153,62,125,122,177,
36,73,109,52,77,131,94,175,95,230,245,122,223,96,24,102,239,132,9,19,62,1,0,19,66,168,85,1,141,164,89,68,60,195,69,219,67,17,66,67,33,203,28,26,26,186,19,33,84,133,176,194,113,220,127,241,60,255,169,36,
73,183,218,73,146,212,214,215,215,247,28,0,88,0,192,178,101,203,150,4,150,101,15,32,132,68,164,82,36,73,106,109,111,111,207,221,177,99,71,146,86,155,80,241,249,124,37,0,48,70,145,184,142,142,142,194,112,
237,253,126,255,255,0,128,61,36,159,125,246,217,61,28,199,253,24,230,21,158,231,249,239,24,134,121,62,26,125,4,65,184,242,213,87,95,221,205,48,204,198,64,32,112,40,76,83,105,120,120,248,207,118,187,61,
78,209,61,86,20,197,27,97,148,40,15,4,2,123,187,186,186,22,185,221,238,63,36,37,37,217,0,192,138,137,69,17,51,198,2,49,152,231,106,83,46,14,234,156,57,115,244,146,36,213,161,232,138,216,208,208,48,15,
0,198,4,131,193,131,145,26,75,146,228,185,124,249,242,191,68,106,231,241,120,254,42,73,210,0,66,72,188,114,229,74,161,215,235,253,34,92,123,183,219,253,1,0,164,0,64,74,65,65,129,131,231,249,150,104,148,
23,4,161,161,188,188,124,74,164,118,67,67,67,251,222,121,231,157,236,40,215,4,13,14,14,238,5,128,68,0,72,80,230,161,90,56,142,251,190,178,178,242,129,226,226,98,7,110,148,0,48,22,0,226,48,195,182,105,
128,27,29,168,0,160,151,36,169,49,218,9,248,124,190,210,37,75,150,164,35,132,4,252,121,103,103,103,17,195,48,197,8,33,30,127,222,219,219,187,45,82,159,3,3,3,31,132,126,111,106,106,218,200,113,220,117,
98,49,174,126,254,249,231,5,60,207,119,40,70,112,178,188,188,252,25,0,200,168,169,169,121,137,236,143,101,217,75,253,253,253,127,9,6,131,231,71,88,164,40,186,118,237,218,21,17,84,134,97,222,103,24,230,
0,186,141,114,230,204,153,101,0,144,42,138,162,91,171,77,101,101,101,30,0,36,43,146,162,72,232,239,36,0,72,0,128,120,5,228,49,152,247,26,1,192,64,135,73,203,201,76,138,86,94,28,17,118,187,186,186,254,
120,241,226,197,165,44,203,214,224,21,70,163,241,215,113,113,113,177,10,37,220,42,28,199,153,155,155,155,27,120,158,111,115,58,157,47,214,213,213,173,42,43,43,43,40,46,46,62,210,218,218,250,70,127,127,
255,223,72,133,68,81,116,139,162,216,239,114,185,110,132,158,5,131,65,163,78,167,187,3,111,215,213,213,85,241,236,179,207,222,216,185,115,231,239,1,0,204,102,243,175,167,77,155,182,2,0,44,231,207,159,
239,235,239,239,63,201,48,76,89,48,24,188,238,243,249,206,77,157,58,117,73,98,98,226,59,151,46,93,218,63,98,1,40,202,254,237,183,223,10,145,244,113,187,221,3,118,187,253,89,149,122,79,95,95,223,49,65,
16,24,178,46,39,39,103,125,126,126,126,162,2,192,168,34,203,50,191,118,237,218,86,37,209,50,99,9,151,9,243,70,35,145,48,233,176,164,149,10,151,237,210,132,167,154,36,73,234,197,45,170,191,191,127,55,0,
164,2,64,90,73,73,201,99,4,165,10,0,48,201,239,247,95,142,16,247,234,47,93,186,244,102,93,93,221,171,181,181,181,127,188,113,227,198,110,178,205,185,115,231,94,219,180,105,83,222,150,45,91,22,132,158,
157,56,113,98,179,223,239,111,195,219,93,189,122,245,3,0,152,177,108,217,178,60,76,15,105,213,170,85,79,2,192,253,0,48,3,0,166,103,100,100,60,120,228,200,145,181,45,45,45,251,61,30,79,141,154,94,78,167,
115,123,77,77,205,43,45,45,45,123,200,186,234,234,234,215,55,108,216,144,95,87,87,247,39,181,119,15,30,60,248,7,0,120,224,196,137,19,175,171,213,183,183,183,127,38,73,18,167,194,28,29,126,191,191,241,
248,241,227,47,149,150,150,190,112,225,194,133,215,67,82,95,95,255,90,85,85,213,90,0,200,4,128,12,0,72,83,214,62,89,241,218,144,199,154,245,81,122,169,170,167,30,57,114,228,43,197,130,244,39,79,158,12,
172,91,183,238,255,210,49,132,4,0,48,159,58,117,234,253,5,11,22,236,210,226,121,139,197,114,159,195,225,64,89,89,89,107,122,122,122,164,187,239,190,219,216,212,212,244,111,120,155,150,150,150,225,132,
132,132,84,187,221,110,197,250,183,155,76,166,9,120,59,135,195,241,100,97,97,225,137,165,75,151,78,193,178,97,186,164,164,164,132,97,152,77,147,38,77,138,45,42,42,122,62,45,45,109,110,164,125,220,171,
175,190,250,99,121,121,185,39,43,43,203,116,245,234,213,181,120,221,245,235,215,189,73,73,73,227,173,86,107,186,218,187,71,143,30,237,205,207,207,79,175,168,168,232,205,207,207,31,85,95,85,85,85,187,98,
197,138,17,30,46,73,82,112,201,146,37,191,43,43,43,115,3,0,60,241,196,19,113,227,198,141,235,9,213,235,116,58,217,235,245,114,202,122,75,0,32,2,128,16,205,169,213,136,189,40,225,169,54,60,62,10,130,48,
0,0,119,1,64,54,0,76,41,44,44,204,35,172,142,185,239,190,251,230,1,192,195,165,165,165,111,12,14,14,54,72,146,196,107,121,236,201,147,39,223,6,128,217,233,233,233,243,200,186,213,171,87,63,15,0,115,199,
140,25,147,31,122,182,123,247,238,215,175,92,185,114,140,108,27,12,6,71,37,32,129,64,160,127,225,194,133,171,3,129,0,67,214,121,189,222,155,12,195,140,74,0,231,206,157,187,0,0,102,167,165,165,229,146,
117,47,188,240,194,74,0,200,219,184,113,227,90,149,36,199,111,48,24,158,2,128,69,203,151,47,255,87,149,164,80,90,179,102,205,75,28,199,121,240,231,103,207,158,253,43,0,60,166,200,28,69,102,43,242,8,0,
60,12,0,15,0,192,116,0,152,2,0,247,0,192,157,0,144,14,0,227,149,4,44,14,0,108,116,180,71,94,57,57,57,49,120,124,100,89,182,13,223,108,219,108,182,177,120,123,158,231,131,111,191,253,246,111,140,70,99,
236,194,133,11,207,59,28,142,141,78,167,243,208,254,253,251,255,227,244,233,211,7,6,7,7,175,227,237,39,78,156,56,19,0,108,130,32,216,72,69,238,184,227,142,84,101,63,105,195,226,222,216,146,146,146,42,
178,173,201,100,138,87,137,83,244,214,173,91,127,107,54,155,19,67,207,252,126,127,239,186,117,235,254,61,54,54,246,247,101,101,101,39,201,119,130,193,160,21,0,108,162,40,142,210,103,194,132,9,19,0,192,
118,252,248,113,31,233,25,6,131,193,114,224,192,129,223,0,64,236,202,149,43,71,49,130,199,227,233,222,183,111,223,16,66,35,143,104,179,178,178,230,2,64,172,146,209,226,130,111,95,66,49,214,64,196,212,
17,39,86,81,39,74,58,157,78,79,76,186,31,59,45,49,155,205,230,17,160,210,52,109,66,8,217,46,95,190,188,181,167,167,231,191,25,134,57,148,147,147,243,244,167,159,126,218,57,123,246,236,210,182,182,182,
230,17,156,129,144,5,0,108,146,36,89,73,133,54,111,222,188,201,239,247,127,176,106,213,170,236,208,51,155,205,22,191,111,223,62,230,194,133,11,85,17,15,69,17,162,204,102,115,2,113,28,215,191,103,207,30,
38,45,45,45,126,209,162,69,43,200,119,120,158,183,106,233,243,202,43,175,20,249,124,190,253,179,102,205,202,232,232,232,104,34,235,11,11,11,87,187,92,174,183,114,115,115,127,75,214,157,61,123,182,86,97,
61,138,48,60,189,2,106,72,200,125,169,153,72,150,98,84,78,148,40,18,212,176,231,134,107,215,174,77,38,64,245,225,71,99,102,179,57,22,175,183,90,173,73,91,183,110,173,201,200,200,120,48,37,37,37,219,96,
48,88,244,122,189,161,180,180,244,207,110,183,123,247,244,233,211,11,240,246,141,141,141,237,0,96,17,4,97,212,34,218,108,182,68,139,197,98,127,230,153,103,30,9,61,27,24,24,64,0,96,158,51,103,206,225,202,
202,202,31,89,150,13,10,130,192,183,181,181,93,175,174,174,174,38,65,101,89,150,34,226,239,228,246,246,246,109,23,46,92,40,142,143,143,119,168,24,130,13,0,172,130,32,88,212,244,177,90,173,99,243,242,242,
166,20,21,21,29,86,78,149,70,148,113,227,198,57,104,154,30,49,166,203,229,234,88,182,108,217,105,0,176,146,160,90,44,150,177,229,229,229,207,61,253,244,211,119,2,128,245,232,209,163,75,15,30,60,248,36,
0,152,87,174,92,121,215,23,95,124,81,176,125,251,246,105,42,25,239,168,243,96,58,202,195,123,200,201,201,113,16,150,204,43,3,24,0,192,104,50,153,98,201,78,156,78,167,112,246,236,217,10,2,236,120,187,221,
126,7,222,127,95,95,95,215,154,53,107,170,1,192,50,56,56,168,175,171,171,59,175,166,84,86,86,86,86,232,247,220,220,220,7,26,27,27,215,249,124,190,93,51,103,206,124,184,183,183,183,119,201,146,37,187,51,
51,51,223,47,41,41,185,64,178,204,181,107,215,250,201,254,210,211,211,39,38,37,37,169,38,59,249,249,249,19,1,192,60,56,56,104,168,173,173,173,81,107,51,121,242,228,187,15,29,58,52,184,126,253,250,247,
35,177,69,115,115,115,203,67,15,61,116,192,106,181,90,1,192,66,130,58,60,60,236,43,40,40,248,254,240,225,195,195,0,96,89,180,104,209,169,21,43,86,156,7,0,83,69,69,133,119,239,222,189,141,239,189,247,94,
59,113,230,171,118,73,16,253,45,77,67,67,131,203,235,245,126,31,8,4,46,115,28,215,237,118,187,7,66,135,239,102,179,217,104,181,90,109,178,44,75,202,153,49,223,218,218,218,0,0,49,243,230,205,251,250,216,
177,99,71,3,129,128,151,236,115,104,104,104,224,216,177,99,39,166,78,157,186,203,229,114,81,33,175,207,203,203,59,226,116,58,47,18,70,196,253,240,195,15,78,81,41,251,247,239,175,233,235,235,27,86,226,
152,193,225,112,100,188,252,242,203,143,208,52,109,92,188,120,241,189,196,190,81,254,230,155,111,92,239,190,251,110,153,215,235,245,225,117,61,61,61,61,111,189,245,214,223,234,235,235,71,140,55,123,246,
236,201,33,202,155,63,127,254,215,23,47,94,116,18,251,109,190,182,182,246,6,0,24,62,252,240,67,215,246,237,219,63,109,109,109,109,111,110,110,110,115,185,92,189,195,195,195,94,81,20,69,0,128,246,246,246,
174,226,226,226,138,123,239,189,55,41,45,45,109,172,66,163,35,10,203,178,2,113,17,16,138,157,134,155,55,111,74,167,78,157,26,238,236,236,148,84,60,116,84,230,75,105,196,82,10,0,116,221,221,221,15,113,
28,103,65,8,37,101,102,102,126,23,138,159,24,199,91,0,192,156,153,153,105,223,185,115,103,222,230,205,155,207,181,181,181,9,162,40,66,124,124,188,209,237,118,139,216,161,60,245,248,227,143,39,102,102,
102,142,145,36,9,234,234,234,6,235,235,235,125,152,130,163,20,205,206,206,182,141,29,59,86,239,245,122,133,107,215,174,5,120,158,71,216,246,138,218,186,117,107,246,142,29,59,10,241,73,13,14,14,122,236,
118,251,136,248,190,125,251,246,175,183,109,219,214,4,0,16,19,19,131,10,11,11,83,103,205,154,149,202,113,28,191,105,211,166,90,150,101,69,154,166,33,57,57,89,175,44,12,197,178,172,60,52,52,36,17,250,88,
227,226,226,98,188,94,175,208,220,220,28,228,121,94,198,245,33,118,15,20,0,64,98,98,98,76,70,70,134,37,45,45,205,60,126,252,120,115,114,114,178,69,150,101,52,127,254,252,73,141,141,141,221,233,233,233,
246,153,51,103,102,159,57,115,230,114,65,65,193,9,0,144,21,9,109,91,68,0,224,20,9,42,18,80,36,244,55,171,212,243,0,32,132,5,85,81,78,143,93,21,153,176,44,12,207,202,76,201,201,201,177,91,182,108,153,38,
203,178,238,227,143,63,110,117,58,157,62,141,59,63,90,227,10,143,10,99,125,72,237,42,80,175,215,211,77,77,77,171,239,186,235,174,95,105,49,12,195,48,238,251,239,191,255,227,142,142,14,78,229,70,67,194,
22,81,235,150,131,34,110,70,144,198,30,62,220,157,39,5,0,176,109,219,182,236,197,139,23,79,41,42,42,250,94,150,101,57,41,41,201,116,232,208,161,238,125,251,246,61,120,250,244,233,206,143,62,250,168,29,
211,43,4,42,175,0,198,98,32,250,49,112,67,160,242,138,136,250,159,115,197,238,112,56,12,93,93,93,148,194,46,8,0,80,95,95,31,87,84,84,84,71,208,131,90,54,45,43,109,162,185,46,66,42,87,77,183,250,19,69,
17,205,156,57,243,163,79,62,249,100,254,163,143,62,58,205,108,54,223,162,53,183,219,61,244,221,119,223,93,217,176,97,195,223,93,46,151,128,133,26,138,232,55,180,248,178,138,46,40,140,46,100,29,233,169,
163,238,162,3,129,128,144,145,145,49,206,237,118,115,245,245,245,195,161,151,95,124,241,197,115,42,125,35,21,99,147,49,67,36,13,242,86,219,104,61,53,6,243,84,147,197,98,177,201,178,108,102,89,214,168,
114,67,64,19,147,82,187,104,215,169,252,84,139,241,106,192,227,30,112,107,44,189,94,175,155,49,99,134,221,102,179,25,126,250,233,39,182,181,181,149,37,206,67,113,111,194,23,137,20,173,113,241,122,89,67,
39,85,10,14,61,155,63,127,126,242,192,192,128,32,8,130,236,116,58,189,42,115,149,49,79,21,85,60,53,64,8,139,9,175,156,48,137,225,64,197,191,106,24,1,106,92,92,156,197,227,241,24,137,205,176,1,219,8,171,
210,15,65,181,100,246,70,171,80,175,28,198,147,195,81,185,218,167,36,228,97,55,185,136,248,79,210,75,100,194,8,212,12,13,55,202,104,232,152,210,96,1,25,163,95,65,5,84,60,174,178,36,245,70,67,191,72,37,
6,137,74,86,167,83,6,165,177,182,34,225,169,90,12,160,246,147,156,56,190,152,184,46,84,20,70,162,35,152,70,135,233,70,105,128,74,122,172,26,152,106,117,145,190,195,162,85,140,144,92,27,68,232,36,171,196,
84,14,3,143,199,60,89,34,169,88,31,5,152,64,76,92,242,251,253,60,1,94,168,94,167,66,189,16,225,27,39,90,227,29,20,38,238,146,20,71,2,74,19,223,76,209,42,177,158,4,21,143,85,184,215,202,26,130,162,160,
96,42,66,172,213,74,196,36,226,208,158,39,64,21,66,84,27,9,84,164,113,170,164,102,61,58,165,115,188,158,164,83,45,96,105,13,218,165,194,128,170,230,21,36,245,234,8,47,213,171,124,20,71,50,1,34,232,14,
255,93,203,131,229,48,97,129,186,77,81,243,86,181,184,202,169,120,172,128,213,143,96,16,189,6,136,100,50,17,202,14,69,194,226,16,246,92,23,5,160,148,6,32,16,1,84,164,1,42,16,52,78,82,174,94,229,147,81,
60,89,146,9,32,37,108,62,114,4,1,141,184,74,221,6,192,225,216,137,244,86,129,0,84,203,83,65,127,27,241,52,52,121,181,12,82,84,241,210,104,129,141,102,127,138,84,98,42,165,225,169,180,202,231,147,186,48,
244,43,19,64,74,81,120,104,56,79,213,154,47,104,208,48,168,176,7,16,204,33,96,52,44,132,1,85,211,83,213,22,86,214,200,76,73,47,133,40,62,52,14,183,151,139,20,215,35,197,104,50,158,146,160,170,177,140,
154,167,74,81,198,82,20,225,150,75,237,3,248,112,123,120,173,195,17,17,243,88,145,160,94,137,52,52,125,24,234,165,84,6,80,139,181,52,145,193,130,6,168,16,6,88,181,137,105,121,172,218,246,33,220,7,230,
36,168,148,74,82,34,71,145,44,161,48,25,57,68,96,40,8,227,181,84,4,103,146,136,124,70,34,0,149,73,61,163,57,81,194,193,147,84,168,144,198,98,109,184,127,187,8,231,181,145,152,2,34,108,31,34,37,77,164,
225,105,209,92,36,170,149,163,56,50,188,93,112,33,66,38,44,135,73,230,100,21,76,224,127,1,162,95,80,121,123,170,70,91,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ShredderEditor::name_png = (const char*) resource_ShredderEditor_name_png;
const int ShredderEditor::name_pngSize = 4534;
