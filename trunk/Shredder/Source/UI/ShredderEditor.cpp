/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  19 May 2010 2:50:11pm

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
      component (0)
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

    //[UserPreSize]
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

    setSize (694, 536);

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
    slot1->setBounds (8, 48, 680, 96);
    slot2->setBounds (8, 136, 680, 96);
    led1->setBounds (28, 16, 24, 24);
    optionsButton->setBounds (632, 512, 56, 16);
    slot3->setBounds (8, 224, 680, 96);
    slot4->setBounds (8, 312, 680, 96);
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
    component->setBounds (8, 400, 680, 96);
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

		const String position = ppqToBarsBeatsString (lastPosInfo.ppqPosition, lastPosInfo.ppqPositionOfLastBarStart, lastPosInfo.timeSigNumerator, lastPosInfo.timeSigDenominator);
		positionInfo->setText (position, false);
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
                 fixedSize="1" initialWidth="694" initialHeight="536">
  <BACKGROUND backgroundColour="ff000000"/>
  <JUCERCOMP name="" id="20ee16f709cc1227" memberName="slot1" virtualName=""
             explicitFocusOrder="0" pos="8 48 680 96" sourceFile="ShredderSlot.cpp"
             constructorParams="this, shredder"/>
  <JUCERCOMP name="" id="57879a0e1ebb336b" memberName="slot2" virtualName=""
             explicitFocusOrder="0" pos="8 136 680 96" sourceFile="ShredderSlot.cpp"
             constructorParams="this, shredder"/>
  <TOGGLEBUTTON name="led1" id="193b348dc9a4edc8" memberName="led1" virtualName=""
                explicitFocusOrder="0" pos="28 16 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="2" state="0"/>
  <TEXTBUTTON name="optionsButton" id="b434469d0c406758" memberName="optionsButton"
              virtualName="" explicitFocusOrder="0" pos="632 512 56 16" buttonText="Options"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <JUCERCOMP name="" id="81aa691ce23973a1" memberName="slot3" virtualName=""
             explicitFocusOrder="0" pos="8 224 680 96" sourceFile="ShredderSlot.cpp"
             constructorParams="this, shredder"/>
  <JUCERCOMP name="" id="41db2a1fd82f3df9" memberName="slot4" virtualName=""
             explicitFocusOrder="0" pos="8 312 680 96" sourceFile="ShredderSlot.cpp"
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
             explicitFocusOrder="0" pos="8 400 680 96" sourceFile="ShredderPeakSlot.cpp"
             constructorParams="this, shredder"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
