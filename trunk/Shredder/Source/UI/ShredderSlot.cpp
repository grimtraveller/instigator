/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  21 May 2010 4:40:02pm

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

#include "ShredderSlot.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ShredderSlot::ShredderSlot (ShredderEditor *_shredderEditor, Shredder *_shredder)
    : stepButton(Pic(ShredderResources::btn_seq_png, ShredderResources::btn_seq_pngSize), Font(10)), shredderEditor(_shredderEditor), shredder(_shredder), slotNumber(-1), shredderPluginEditor(0), serializedSekuntiaTf(ShredderResources::_60sekuntia_jfont, ShredderResources::_60sekuntia_jfontSize), whiteKnob(Pic(ShredderResources::whiteknob_png, ShredderResources::whiteknob_pngSize), Font(10, Font::bold)), onOffButton(Pic(ShredderResources::onoff_png, ShredderResources::onoff_pngSize), Font(10, Font::bold)),
      groupComponent (0),
      step1 (0),
      step2 (0),
      step3 (0),
      step4 (0),
      step5 (0),
      step6 (0),
      step7 (0),
      step8 (0),
      step9 (0),
      step10 (0),
      step11 (0),
      step12 (0),
      step13 (0),
      step14 (0),
      step15 (0),
      step16 (0),
      pluginMenu (0),
      pluginEditor (0),
      pluginName (0),
      processButton (0),
      attack (0),
      decay (0),
      sustain (0),
      release (0),
      mix (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            String::empty));
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0x66ffffff));

    addAndMakeVisible (step1 = new ToggleButton (T("1")));
    step1->setButtonText (String::empty);
    step1->addButtonListener (this);

    addAndMakeVisible (step2 = new ToggleButton (T("2")));
    step2->setButtonText (String::empty);
    step2->addButtonListener (this);

    addAndMakeVisible (step3 = new ToggleButton (T("3")));
    step3->setButtonText (String::empty);
    step3->addButtonListener (this);

    addAndMakeVisible (step4 = new ToggleButton (T("4")));
    step4->setButtonText (String::empty);
    step4->addButtonListener (this);

    addAndMakeVisible (step5 = new ToggleButton (T("5")));
    step5->setButtonText (String::empty);
    step5->addButtonListener (this);

    addAndMakeVisible (step6 = new ToggleButton (T("6")));
    step6->setButtonText (String::empty);
    step6->addButtonListener (this);

    addAndMakeVisible (step7 = new ToggleButton (T("7")));
    step7->setButtonText (String::empty);
    step7->addButtonListener (this);

    addAndMakeVisible (step8 = new ToggleButton (T("8")));
    step8->setButtonText (String::empty);
    step8->addButtonListener (this);

    addAndMakeVisible (step9 = new ToggleButton (T("9")));
    step9->setButtonText (String::empty);
    step9->addButtonListener (this);

    addAndMakeVisible (step10 = new ToggleButton (T("10")));
    step10->setButtonText (String::empty);
    step10->addButtonListener (this);

    addAndMakeVisible (step11 = new ToggleButton (T("11")));
    step11->setButtonText (String::empty);
    step11->addButtonListener (this);

    addAndMakeVisible (step12 = new ToggleButton (T("12")));
    step12->setButtonText (String::empty);
    step12->addButtonListener (this);

    addAndMakeVisible (step13 = new ToggleButton (T("13")));
    step13->setButtonText (String::empty);
    step13->addButtonListener (this);

    addAndMakeVisible (step14 = new ToggleButton (T("14")));
    step14->setButtonText (String::empty);
    step14->addButtonListener (this);

    addAndMakeVisible (step15 = new ToggleButton (T("15")));
    step15->setButtonText (String::empty);
    step15->addButtonListener (this);

    addAndMakeVisible (step16 = new ToggleButton (T("16")));
    step16->setButtonText (String::empty);
    step16->addButtonListener (this);

    addAndMakeVisible (pluginMenu = new ImageButton (T("pluginMenu")));
    pluginMenu->setButtonText (String::empty);
    pluginMenu->addButtonListener (this);

    pluginMenu->setImages (false, true, true,
                           ImageCache::getFromMemory (plugin_unloaded_png, plugin_unloaded_pngSize), 0.7000f, Colour (0x0),
                           ImageCache::getFromMemory (plugin_unloaded_png, plugin_unloaded_pngSize), 0.8000f, Colour (0x0),
                           ImageCache::getFromMemory (plugin_unloaded_png, plugin_unloaded_pngSize), 1.0000f, Colour (0x0));
    addAndMakeVisible (pluginEditor = new ImageButton (T("pluginEditor")));
    pluginEditor->setButtonText (String::empty);
    pluginEditor->addButtonListener (this);

    pluginEditor->setImages (false, true, true,
                             ImageCache::getFromMemory (plugin_editor_png, plugin_editor_pngSize), 0.7107f, Colour (0x0),
                             ImageCache::getFromMemory (plugin_editor_png, plugin_editor_pngSize), 0.8113f, Colour (0x0),
                             ImageCache::getFromMemory (plugin_editor_png, plugin_editor_pngSize), 1.0000f, Colour (0x0));
    addAndMakeVisible (pluginName = new Label (T("pluginName"),
                                               T("--- No plugin")));
    pluginName->setFont (Font (14.0000f, Font::bold));
    pluginName->setJustificationType (Justification::centredRight);
    pluginName->setEditable (false, false, false);
    pluginName->setColour (Label::textColourId, Colours::white);
    pluginName->setColour (TextEditor::textColourId, Colours::black);
    pluginName->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (processButton = new ToggleButton (T("processButton")));
    processButton->setButtonText (String::empty);
    processButton->addButtonListener (this);
    processButton->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (attack = new Slider (T("attack")));
    attack->setRange (0, 100, 1);
    attack->setSliderStyle (Slider::RotaryVerticalDrag);
    attack->setTextBoxStyle (Slider::TextBoxRight, false, 28, 20);
    attack->setColour (Slider::rotarySliderFillColourId, Colours::white);
    attack->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    attack->setColour (Slider::textBoxTextColourId, Colours::white);
    attack->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    attack->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    attack->addListener (this);

    addAndMakeVisible (decay = new Slider (T("decay")));
    decay->setRange (0, 100, 1);
    decay->setSliderStyle (Slider::RotaryVerticalDrag);
    decay->setTextBoxStyle (Slider::TextBoxRight, false, 28, 20);
    decay->setColour (Slider::rotarySliderFillColourId, Colours::white);
    decay->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    decay->setColour (Slider::textBoxTextColourId, Colours::white);
    decay->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    decay->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    decay->addListener (this);

    addAndMakeVisible (sustain = new Slider (T("sustain")));
    sustain->setRange (0, 100, 1);
    sustain->setSliderStyle (Slider::RotaryVerticalDrag);
    sustain->setTextBoxStyle (Slider::TextBoxRight, false, 28, 20);
    sustain->setColour (Slider::rotarySliderFillColourId, Colours::white);
    sustain->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    sustain->setColour (Slider::textBoxTextColourId, Colours::white);
    sustain->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    sustain->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    sustain->addListener (this);

    addAndMakeVisible (release = new Slider (T("release")));
    release->setRange (0, 100, 1);
    release->setSliderStyle (Slider::RotaryVerticalDrag);
    release->setTextBoxStyle (Slider::TextBoxRight, false, 28, 20);
    release->setColour (Slider::rotarySliderFillColourId, Colours::white);
    release->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    release->setColour (Slider::textBoxTextColourId, Colours::white);
    release->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    release->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    release->addListener (this);

    addAndMakeVisible (mix = new Slider (T("mix")));
    mix->setRange (0, 100, 1);
    mix->setSliderStyle (Slider::RotaryVerticalDrag);
    mix->setTextBoxStyle (Slider::TextBoxRight, false, 28, 20);
    mix->setColour (Slider::rotarySliderFillColourId, Colours::white);
    mix->setColour (Slider::rotarySliderOutlineColourId, Colours::white);
    mix->setColour (Slider::textBoxTextColourId, Colours::white);
    mix->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    mix->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    mix->addListener (this);


    //[UserPreSize]
	steps.add (step1);
	steps.add (step2);
	steps.add (step3);
	steps.add (step4);

	steps.add (step5);
	steps.add (step6);
	steps.add (step7);
	steps.add (step8);

	steps.add (step9);
	steps.add (step10);
	steps.add (step11);
	steps.add (step12);

	steps.add (step13);
	steps.add (step14);
	steps.add (step15);
	steps.add (step16);

	sekuntiaTf = serializedSekuntiaTf.getTypefaceForFlags (Font::plain);
	Font f(sekuntiaTf);
	f.setHeight (18);
	pluginName->setFont (f);

	for (int i=0; i<steps.size(); i++)
	{
		steps[i]->setLookAndFeel (&stepButton);
	}

	attack->setLookAndFeel (&whiteKnob);
	decay->setLookAndFeel (&whiteKnob);
	sustain->setLookAndFeel (&whiteKnob);
	release->setLookAndFeel (&whiteKnob);
	mix->setLookAndFeel (&whiteKnob);
	processButton->setLookAndFeel (&onOffButton);
    //[/UserPreSize]

    setSize (680, 104);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ShredderSlot::~ShredderSlot()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (shredderPluginEditor)
	{
		deleteAndZero (shredderPluginEditor);
	}
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (step1);
    deleteAndZero (step2);
    deleteAndZero (step3);
    deleteAndZero (step4);
    deleteAndZero (step5);
    deleteAndZero (step6);
    deleteAndZero (step7);
    deleteAndZero (step8);
    deleteAndZero (step9);
    deleteAndZero (step10);
    deleteAndZero (step11);
    deleteAndZero (step12);
    deleteAndZero (step13);
    deleteAndZero (step14);
    deleteAndZero (step15);
    deleteAndZero (step16);
    deleteAndZero (pluginMenu);
    deleteAndZero (pluginEditor);
    deleteAndZero (pluginName);
    deleteAndZero (processButton);
    deleteAndZero (attack);
    deleteAndZero (decay);
    deleteAndZero (sustain);
    deleteAndZero (release);
    deleteAndZero (mix);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ShredderSlot::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ShredderSlot::resized()
{
    groupComponent->setBounds (0, 0, 680, 104);
    step1->setBounds (16, 24, 32, 32);
    step2->setBounds (56, 24, 32, 32);
    step3->setBounds (96, 24, 32, 32);
    step4->setBounds (136, 24, 32, 32);
    step5->setBounds (184, 24, 32, 32);
    step6->setBounds (224, 24, 32, 32);
    step7->setBounds (264, 24, 32, 32);
    step8->setBounds (304, 24, 32, 32);
    step9->setBounds (352, 24, 32, 32);
    step10->setBounds (392, 24, 32, 32);
    step11->setBounds (432, 24, 32, 32);
    step12->setBounds (472, 24, 32, 32);
    step13->setBounds (520, 24, 32, 32);
    step14->setBounds (560, 24, 32, 32);
    step15->setBounds (600, 24, 32, 32);
    step16->setBounds (640, 24, 32, 32);
    pluginMenu->setBounds (600, 64, 32, 32);
    pluginEditor->setBounds (632, 64, 32, 32);
    pluginName->setBounds (344, 72, 246, 24);
    processButton->setBounds (8, 72, 24, 24);
    attack->setBounds (160, 72, 52, 24);
    decay->setBounds (216, 72, 52, 24);
    sustain->setBounds (272, 72, 52, 24);
    release->setBounds (328, 72, 52, 24);
    mix->setBounds (40, 72, 52, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ShredderSlot::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == step1)
    {
        //[UserButtonCode_step1] -- add your button handler code here..
        //[/UserButtonCode_step1]
    }
    else if (buttonThatWasClicked == step2)
    {
        //[UserButtonCode_step2] -- add your button handler code here..
        //[/UserButtonCode_step2]
    }
    else if (buttonThatWasClicked == step3)
    {
        //[UserButtonCode_step3] -- add your button handler code here..
        //[/UserButtonCode_step3]
    }
    else if (buttonThatWasClicked == step4)
    {
        //[UserButtonCode_step4] -- add your button handler code here..
        //[/UserButtonCode_step4]
    }
    else if (buttonThatWasClicked == step5)
    {
        //[UserButtonCode_step5] -- add your button handler code here..
        //[/UserButtonCode_step5]
    }
    else if (buttonThatWasClicked == step6)
    {
        //[UserButtonCode_step6] -- add your button handler code here..
        //[/UserButtonCode_step6]
    }
    else if (buttonThatWasClicked == step7)
    {
        //[UserButtonCode_step7] -- add your button handler code here..
        //[/UserButtonCode_step7]
    }
    else if (buttonThatWasClicked == step8)
    {
        //[UserButtonCode_step8] -- add your button handler code here..
        //[/UserButtonCode_step8]
    }
    else if (buttonThatWasClicked == step9)
    {
        //[UserButtonCode_step9] -- add your button handler code here..
        //[/UserButtonCode_step9]
    }
    else if (buttonThatWasClicked == step10)
    {
        //[UserButtonCode_step10] -- add your button handler code here..
        //[/UserButtonCode_step10]
    }
    else if (buttonThatWasClicked == step11)
    {
        //[UserButtonCode_step11] -- add your button handler code here..
        //[/UserButtonCode_step11]
    }
    else if (buttonThatWasClicked == step12)
    {
        //[UserButtonCode_step12] -- add your button handler code here..
        //[/UserButtonCode_step12]
    }
    else if (buttonThatWasClicked == step13)
    {
        //[UserButtonCode_step13] -- add your button handler code here..
        //[/UserButtonCode_step13]
    }
    else if (buttonThatWasClicked == step14)
    {
        //[UserButtonCode_step14] -- add your button handler code here..
        //[/UserButtonCode_step14]
    }
    else if (buttonThatWasClicked == step15)
    {
        //[UserButtonCode_step15] -- add your button handler code here..
        //[/UserButtonCode_step15]
    }
    else if (buttonThatWasClicked == step16)
    {
        //[UserButtonCode_step16] -- add your button handler code here..
        //[/UserButtonCode_step16]
    }
    else if (buttonThatWasClicked == pluginMenu)
    {
        //[UserButtonCode_pluginMenu] -- add your button handler code here..
		PopupMenu p = shredderEditor->getPluginMenu();
		const int ret = p.show();

		if (ret == 1 && slotNumber >= 1)
		{
			shredder->getCallbackLock().enter();
			if (shredderPluginEditor)
			{
				deleteAndZero (shredderPluginEditor);
			}

			shredder->clearPluginOnSlot (slotNumber, false);
			shredder->getCallbackLock().exit();

			reloadState();
		}
		else if (ret >= 2 && slotNumber >= 1)
		{
			shredder->getCallbackLock().enter();
			if (shredderPluginEditor)
			{
				deleteAndZero (shredderPluginEditor);
			}
			shredder->clearPluginOnSlot (slotNumber, false);
			shredder->loadPluginOnSlot (slotNumber, ret-2);
			shredder->getCallbackLock().exit();

			reloadState();
		}

		return;
        //[/UserButtonCode_pluginMenu]
    }
    else if (buttonThatWasClicked == pluginEditor)
    {
        //[UserButtonCode_pluginEditor] -- add your button handler code here..
		if (shredderPluginEditor != 0)
		{
			if (shredderPluginEditor->isVisible())
			{
				shredderPluginEditor->setVisible (false);
			}
			else
			{
				shredderPluginEditor->setVisible (true);
			}
		}
		else if (slotNumber >= 1)
		{
			if (shredder->getPluginOnSlot(slotNumber))
			{
				shredderPluginEditor = new ShredderPluginEditor (shredder->getPluginOnSlot(slotNumber), this);
			}
		}

		return;
        //[/UserButtonCode_pluginEditor]
    }
    else if (buttonThatWasClicked == processButton)
    {
        //[UserButtonCode_processButton] -- add your button handler code here..
		shredder->getCallbackLock().enter();
		if (shredder->getPluginOnSlot(slotNumber))
			shredder->getPluginOnSlot(slotNumber)->setProcessing (buttonThatWasClicked->getToggleState());
		shredder->getCallbackLock().exit();

		return;
        //[/UserButtonCode_processButton]
    }

    //[UserbuttonClicked_Post]
	step (buttonThatWasClicked);
    //[/UserbuttonClicked_Post]
}

void ShredderSlot::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == attack)
    {
        //[UserSliderCode_attack] -- add your slider handling code here..
		shredder->getCallbackLock().enter();
		if (shredder->getPluginOnSlot(slotNumber))
			shredder->getPluginOnSlot(slotNumber)->setAttack ((float)sliderThatWasMoved->getValue());
		shredder->getCallbackLock().exit();
        //[/UserSliderCode_attack]
    }
    else if (sliderThatWasMoved == decay)
    {
        //[UserSliderCode_decay] -- add your slider handling code here..
		shredder->getCallbackLock().enter();
		if (shredder->getPluginOnSlot(slotNumber))
			shredder->getPluginOnSlot(slotNumber)->setDecay ((float)sliderThatWasMoved->getValue());
		shredder->getCallbackLock().exit();
        //[/UserSliderCode_decay]
    }
    else if (sliderThatWasMoved == sustain)
    {
        //[UserSliderCode_sustain] -- add your slider handling code here..
		shredder->getCallbackLock().enter();
		if (shredder->getPluginOnSlot(slotNumber))
			shredder->getPluginOnSlot(slotNumber)->setSustain ((float)sliderThatWasMoved->getValue());
		shredder->getCallbackLock().exit();
        //[/UserSliderCode_sustain]
    }
    else if (sliderThatWasMoved == release)
    {
        //[UserSliderCode_release] -- add your slider handling code here..
		shredder->getCallbackLock().enter();
		if (shredder->getPluginOnSlot(slotNumber))
			shredder->getPluginOnSlot(slotNumber)->setRelease ((float)sliderThatWasMoved->getValue());
		shredder->getCallbackLock().exit();
        //[/UserSliderCode_release]
    }
    else if (sliderThatWasMoved == mix)
    {
        //[UserSliderCode_mix] -- add your slider handling code here..
		shredder->getCallbackLock().enter();
		if (shredder->getPluginOnSlot(slotNumber))
			shredder->getPluginOnSlot(slotNumber)->setMix ((int)sliderThatWasMoved->getValue());
		shredder->getCallbackLock().exit();
        //[/UserSliderCode_mix]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ShredderSlot::setSlotNumber (const int _slotNumber)
{
	slotNumber = _slotNumber;
	reloadState();
}

void ShredderSlot::setLength(const int _length)
{
	Log (T("ShredderSlot::setLength len:") + String(_length) + T(" slot:") + String(slotNumber));

	length = _length;

	if (shredder->getPluginOnSlot(slotNumber))
	{
		shredder->getPluginOnSlot(slotNumber)->setLength (length);
	}
}

void ShredderSlot::reloadState()
{
	if (shredder->getPluginOnSlot(slotNumber))
	{
		shredder->getCallbackLock().enter();

		ShredderPlugin *p		= shredder->getPluginOnSlot(slotNumber);
		const BigInteger steps	= p->getSteps();
		length					= p->getLength();
		const String name		= p->getName();
		const bool process		= p->getProcessing();
		const float _attack		= p->getAttack();
		const float _decay		= p->getDecay();
		const float _sustain	= p->getSustain();
		const float _release	= p->getRelease();
		const int _mix			= p->getMix();

		shredder->getCallbackLock().exit();

		pluginName->setText (name, false);
		processButton->setToggleState (process, false);
		attack->setValue (_attack, false);
		decay->setValue (_decay, false);
		sustain->setValue (_sustain, false);
		release->setValue (_release, false);
		mix->setValue (_mix, false);

		for (int i=0; i<length; i++)
		{
			ToggleButton *btn = dynamic_cast<ToggleButton*>(getComponentByName(this, String(i+1)));
			if (btn == NULL)
				continue;

			btn->setToggleState (steps[i], false);
		}
	}
	else
	{
		processButton->setToggleState (false, false);
		pluginName->setText (T("--- No plugin"), false);
	}
}

void ShredderSlot::step (Button *stepButton)
{
	const int stepNum = stepButton->getName().getIntValue();
	if (stepNum >= 1 && shredder->getPluginOnSlot(slotNumber))
	{
		shredder->getCallbackLock().enter();
		shredder->getPluginOnSlot(slotNumber)->setStep (stepNum, stepButton->getToggleState());
		shredder->getCallbackLock().exit();
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ShredderSlot" componentName=""
                 parentClasses="public Component" constructorParams="ShredderEditor *_shredderEditor, Shredder *_shredder"
                 variableInitialisers="stepButton(Pic(ShredderResources::btn_seq_png, ShredderResources::btn_seq_pngSize), Font(10)), shredderEditor(_shredderEditor), shredder(_shredder), slotNumber(-1), shredderPluginEditor(0), serializedSekuntiaTf(ShredderResources::_60sekuntia_jfont, ShredderResources::_60sekuntia_jfontSize), whiteKnob(Pic(ShredderResources::whiteknob_png, ShredderResources::whiteknob_pngSize), Font(10, Font::bold)), onOffButton(Pic(ShredderResources::onoff_png, ShredderResources::onoff_pngSize), Font(10, Font::bold))"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="680" initialHeight="104">
  <BACKGROUND backgroundColour="0"/>
  <GROUPCOMPONENT name="new group" id="a79a2bb9220771ce" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 0 680 104" outlinecol="66ffffff"
                  title=""/>
  <TOGGLEBUTTON name="1" id="cfb4f3e0e2a015a8" memberName="step1" virtualName=""
                explicitFocusOrder="0" pos="16 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="2" id="65f2541f5403c035" memberName="step2" virtualName=""
                explicitFocusOrder="0" pos="56 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="3" id="b001f0ba8bb02626" memberName="step3" virtualName=""
                explicitFocusOrder="0" pos="96 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="4" id="ebb3d1e5a0247dbf" memberName="step4" virtualName=""
                explicitFocusOrder="0" pos="136 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="5" id="828f82329ce10b82" memberName="step5" virtualName=""
                explicitFocusOrder="0" pos="184 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="6" id="7a2a90bac9521ebd" memberName="step6" virtualName=""
                explicitFocusOrder="0" pos="224 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="7" id="ab6786989e14cbec" memberName="step7" virtualName=""
                explicitFocusOrder="0" pos="264 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="8" id="e6aa3f9b14e2695b" memberName="step8" virtualName=""
                explicitFocusOrder="0" pos="304 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="9" id="b32c9a3602a4b20f" memberName="step9" virtualName=""
                explicitFocusOrder="0" pos="352 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="10" id="1ad9b2bb86eeb2e6" memberName="step10" virtualName=""
                explicitFocusOrder="0" pos="392 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="11" id="e7c51dc8d134e5fd" memberName="step11" virtualName=""
                explicitFocusOrder="0" pos="432 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="12" id="efb6d6013ce12051" memberName="step12" virtualName=""
                explicitFocusOrder="0" pos="472 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="13" id="8c9bd0ffa80535a8" memberName="step13" virtualName=""
                explicitFocusOrder="0" pos="520 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="14" id="69366f87a73976b1" memberName="step14" virtualName=""
                explicitFocusOrder="0" pos="560 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="15" id="7693cfef2626d6a" memberName="step15" virtualName=""
                explicitFocusOrder="0" pos="600 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="16" id="3c29b21cdbeb7bc1" memberName="step16" virtualName=""
                explicitFocusOrder="0" pos="640 24 32 32" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <IMAGEBUTTON name="pluginMenu" id="a8385423cc59fedd" memberName="pluginMenu"
               virtualName="" explicitFocusOrder="0" pos="600 64 32 32" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="plugin_unloaded_png" opacityNormal="0.699999988"
               colourNormal="0" resourceOver="plugin_unloaded_png" opacityOver="0.800000012"
               colourOver="0" resourceDown="plugin_unloaded_png" opacityDown="1"
               colourDown="0"/>
  <IMAGEBUTTON name="pluginEditor" id="8f20947e1ec0f9fa" memberName="pluginEditor"
               virtualName="" explicitFocusOrder="0" pos="632 64 32 32" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="plugin_editor_png" opacityNormal="0.71069181"
               colourNormal="0" resourceOver="plugin_editor_png" opacityOver="0.811320782"
               colourOver="0" resourceDown="plugin_editor_png" opacityDown="1"
               colourDown="0"/>
  <LABEL name="pluginName" id="6aba723e04970405" memberName="pluginName"
         virtualName="" explicitFocusOrder="0" pos="344 72 246 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="--- No plugin" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14" bold="1" italic="0" justification="34"/>
  <TOGGLEBUTTON name="processButton" id="dff9ca9cd9964ab6" memberName="processButton"
                virtualName="" explicitFocusOrder="0" pos="8 72 24 24" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <SLIDER name="attack" id="4786b9b86028837c" memberName="attack" virtualName=""
          explicitFocusOrder="0" pos="160 72 52 24" rotarysliderfill="ffffffff"
          rotaryslideroutline="ffffffff" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="100" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="28"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="decay" id="8ee841ecb4b32b26" memberName="decay" virtualName=""
          explicitFocusOrder="0" pos="216 72 52 24" rotarysliderfill="ffffffff"
          rotaryslideroutline="ffffffff" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="100" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="28"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="sustain" id="c31fce3c0095eed4" memberName="sustain" virtualName=""
          explicitFocusOrder="0" pos="272 72 52 24" rotarysliderfill="ffffffff"
          rotaryslideroutline="ffffffff" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="100" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="28"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="release" id="7ed2af46945d5cd9" memberName="release" virtualName=""
          explicitFocusOrder="0" pos="328 72 52 24" rotarysliderfill="ffffffff"
          rotaryslideroutline="ffffffff" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="100" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="28"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="mix" id="275d54b3a3e29ac1" memberName="mix" virtualName=""
          explicitFocusOrder="0" pos="40 72 52 24" rotarysliderfill="ffffffff"
          rotaryslideroutline="ffffffff" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="100" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="28"
          textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: plugin_editor_png, 2053, "../../../../../Users/atom/Desktop/plugin_editor.png"
static const unsigned char resource_ShredderSlot_plugin_editor_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,25,116,69,88,116,83,111,102,116,
119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,7,167,73,68,65,84,120,218,180,87,125,80,20,231,25,255,237,222,237,125,112,71,0,177,119,124,42,17,80,208,54,
13,104,154,198,161,17,153,201,164,118,28,99,170,105,154,214,25,99,59,105,109,18,42,255,36,53,74,139,141,214,24,154,100,160,105,99,172,26,19,27,59,182,201,116,52,26,99,170,163,92,180,26,4,149,24,130,2,
34,225,75,249,60,229,224,184,219,251,216,183,207,187,187,192,169,40,116,58,236,204,51,187,251,190,239,190,207,239,249,61,95,239,10,24,255,18,143,23,63,180,56,198,34,124,40,74,102,201,104,177,65,246,244,
5,61,50,150,47,220,116,250,32,205,43,152,196,75,60,188,246,193,199,107,94,45,96,254,250,195,140,245,127,69,82,75,207,159,176,154,210,2,182,251,87,57,217,180,70,248,191,20,140,51,111,138,143,18,223,206,
90,250,34,204,193,207,128,19,15,171,98,54,92,198,189,5,43,145,233,180,236,164,53,210,100,2,176,138,96,14,115,234,108,224,235,109,180,218,70,246,70,1,157,7,97,178,59,161,132,149,41,180,198,50,153,0,36,
149,97,255,16,169,73,214,216,22,72,140,209,234,141,156,111,160,65,227,100,2,80,186,7,67,199,186,206,30,0,210,86,3,44,164,73,202,10,116,213,30,67,103,63,247,203,228,6,97,116,172,77,154,123,254,149,124,
198,6,219,24,59,232,208,100,176,149,85,149,60,192,104,126,14,73,212,100,50,224,187,225,13,246,4,253,94,37,212,223,65,110,72,164,33,174,55,48,60,223,79,34,223,250,209,201,13,121,113,19,5,192,253,39,157,
219,188,160,27,225,96,172,162,220,206,38,163,49,107,124,50,140,81,180,52,208,67,144,77,4,171,3,209,73,51,81,85,34,180,9,98,164,13,76,139,220,41,113,56,191,249,123,200,89,119,194,28,137,246,78,0,108,92,
121,206,11,91,129,16,211,73,17,110,222,147,209,123,227,27,20,114,86,109,174,241,85,204,122,170,148,30,217,45,85,128,113,196,234,174,117,59,138,241,204,194,212,196,237,199,219,90,134,83,250,139,210,227,
50,11,7,112,255,75,143,142,0,227,0,76,170,229,161,32,113,183,152,54,36,11,133,97,171,132,81,79,9,180,212,96,209,198,188,87,128,207,31,187,61,254,184,114,70,30,201,59,8,191,187,27,164,92,214,55,145,46,
110,118,201,246,89,153,24,24,26,68,245,250,15,228,121,127,120,66,5,49,202,31,35,0,6,179,166,132,91,106,160,216,50,216,9,226,61,106,218,145,15,244,121,2,104,180,234,99,49,99,8,141,35,60,12,158,243,39,189,
187,103,175,124,196,113,9,254,126,47,252,158,33,12,77,77,197,153,162,93,28,156,201,56,98,169,64,140,164,173,32,135,100,16,27,148,247,3,245,128,251,52,25,25,212,172,159,80,197,37,6,20,74,83,132,70,234,
200,142,191,127,36,63,144,147,133,216,184,104,236,216,189,11,223,23,31,129,223,39,67,10,168,30,176,169,0,68,3,17,17,246,161,171,153,193,211,250,111,136,150,40,196,103,204,65,236,236,133,64,211,95,41,206,
123,73,191,97,2,32,20,173,118,81,173,96,97,134,202,151,178,218,46,211,94,209,247,196,160,177,161,1,206,56,7,246,182,31,192,79,59,211,49,111,219,47,191,59,28,3,180,183,17,95,110,127,13,181,87,122,15,236,
63,215,253,73,118,178,125,90,65,118,237,170,105,223,158,235,156,94,240,115,160,161,140,246,86,34,98,227,78,23,1,20,121,241,12,195,235,29,192,195,207,45,199,119,146,83,240,231,61,159,65,12,122,81,87,87,
143,144,100,37,229,43,169,169,128,242,26,94,14,32,180,255,108,215,234,15,43,175,118,212,182,121,218,233,125,144,155,177,1,56,116,116,173,178,51,38,53,53,51,118,202,60,114,199,25,29,192,93,88,224,41,73,
68,85,20,23,34,255,249,229,64,194,207,128,83,27,240,124,232,3,20,182,252,158,10,134,21,63,17,247,185,124,121,201,190,221,39,59,186,121,16,114,94,89,69,93,239,215,221,30,249,26,61,243,65,183,94,96,252,
41,241,54,207,204,56,252,32,254,190,92,192,83,167,91,103,208,128,220,42,220,141,146,128,138,191,121,72,249,15,129,164,85,192,233,141,64,61,63,50,24,208,90,223,138,151,75,151,193,225,76,72,203,50,15,252,
98,73,174,227,240,158,255,116,180,139,122,37,235,213,149,123,244,119,31,73,159,40,8,237,170,193,68,41,12,134,177,197,72,98,34,49,147,242,247,220,200,127,110,233,168,242,134,3,106,10,151,85,102,97,117,
201,131,64,203,123,176,37,49,204,90,242,24,156,118,201,69,147,102,81,79,149,240,24,77,37,108,145,4,159,150,219,97,205,122,209,120,179,80,236,192,72,34,25,80,177,179,59,66,249,203,186,114,1,101,103,50,
81,180,150,186,118,127,171,86,107,186,142,193,156,146,0,198,24,119,191,245,110,173,84,156,159,17,183,58,58,37,9,8,246,106,10,213,76,136,8,56,254,106,96,168,216,214,74,180,63,30,161,252,35,117,190,252,
204,12,20,173,139,37,78,185,17,162,214,202,69,178,87,25,26,73,83,181,18,214,108,201,151,195,97,214,221,239,11,62,93,176,233,212,167,229,43,191,101,185,47,217,182,206,153,56,117,105,66,206,55,201,65,71,
117,255,71,194,227,231,2,162,125,235,21,93,249,211,163,202,105,238,79,85,233,88,179,125,13,57,211,75,53,133,98,251,198,87,196,41,41,166,128,150,175,118,18,22,49,52,210,11,232,100,131,153,139,242,28,237,
167,47,28,170,42,153,15,163,197,140,184,244,20,76,95,240,16,48,84,67,232,253,4,147,170,159,53,129,238,223,208,218,133,50,128,138,45,31,147,242,101,186,242,141,35,150,115,229,79,61,57,151,26,210,95,32,
144,141,137,185,115,224,156,91,64,221,212,4,239,229,22,92,254,244,8,14,93,232,249,13,207,64,181,27,50,2,96,159,153,138,172,105,122,41,229,213,44,64,201,48,88,77,244,95,167,83,193,52,250,56,19,189,23,175,
192,219,67,185,236,15,160,253,92,45,242,11,35,149,107,62,47,175,156,129,53,59,158,33,229,187,144,251,187,147,139,44,146,40,252,243,215,222,117,201,149,95,228,113,139,3,97,230,126,231,68,251,250,237,199,
90,142,240,96,87,99,128,169,97,72,165,209,93,173,231,185,48,154,239,150,4,4,130,78,212,189,255,47,52,117,14,30,117,93,234,115,253,56,215,190,113,1,79,181,196,85,55,41,47,171,76,71,209,102,42,229,242,16,
20,173,51,55,251,131,138,111,201,235,85,133,244,28,3,45,106,188,122,198,113,145,35,74,91,88,235,245,35,162,71,189,61,9,45,199,171,225,186,216,87,190,252,205,179,235,3,162,127,200,249,232,19,192,244,34,
42,50,37,164,124,191,250,181,170,124,11,29,94,131,76,139,118,237,34,250,112,149,164,137,132,130,0,181,36,13,250,24,143,68,37,34,11,136,1,131,164,69,235,72,160,83,244,74,38,120,218,251,80,244,126,45,63,
130,187,159,252,209,178,77,233,11,95,64,168,153,10,140,236,167,32,98,42,237,69,175,83,105,247,82,25,81,179,235,166,51,8,15,182,1,93,198,60,144,232,237,56,196,187,146,118,248,80,233,103,106,251,149,187,
250,16,102,140,127,124,253,205,103,179,23,221,159,29,101,197,85,162,252,250,37,92,104,246,226,243,154,12,60,187,150,74,123,208,175,125,203,83,149,133,254,215,51,33,255,48,164,90,11,73,210,178,147,223,
121,129,115,90,97,141,146,120,147,23,155,252,105,101,229,251,220,112,215,159,194,187,239,236,245,190,248,150,171,120,126,170,89,54,218,69,45,144,140,146,182,7,111,237,19,252,97,210,218,49,207,105,19,47,
134,113,195,199,186,209,3,145,20,134,99,182,3,251,126,251,136,235,173,47,157,182,25,131,141,193,226,210,198,55,182,30,190,246,241,63,10,231,173,136,207,118,154,133,120,147,214,86,152,254,141,137,105,123,
78,20,128,34,10,131,231,95,115,217,21,133,221,78,145,160,166,47,46,248,102,165,57,66,53,175,188,189,175,250,144,222,59,124,25,137,246,197,125,77,189,232,249,163,139,151,214,136,166,40,240,61,7,18,227,
44,134,107,215,253,227,53,112,80,173,196,189,154,249,119,228,141,239,238,215,59,165,91,15,40,254,79,152,66,50,117,140,255,67,166,103,64,51,201,141,241,0,72,234,201,152,136,27,135,173,144,222,37,229,209,
163,143,250,83,98,190,195,250,128,158,243,193,187,109,250,95,1,6,0,142,200,252,94,154,186,219,12,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ShredderSlot::plugin_editor_png = (const char*) resource_ShredderSlot_plugin_editor_png;
const int ShredderSlot::plugin_editor_pngSize = 2053;

// JUCER_RESOURCE: plugin_loaded_png, 1743, "../../../../../Users/atom/Desktop/plugin_loaded.png"
static const unsigned char resource_ShredderSlot_plugin_loaded_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,25,116,69,88,116,83,111,102,116,
119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,6,113,73,68,65,84,120,218,180,87,107,76,20,87,20,62,51,59,179,179,11,75,151,5,100,97,145,135,169,32,160,180,
18,106,172,74,139,18,211,196,68,139,198,182,73,19,83,53,237,15,250,163,246,87,171,161,26,73,106,108,181,246,149,54,169,45,181,73,173,73,31,154,26,35,241,81,21,31,24,145,162,66,21,73,85,20,129,5,89,100,
65,96,97,119,153,217,185,61,119,230,2,35,32,139,105,152,228,100,103,238,227,156,239,156,251,157,115,238,114,16,254,225,207,110,93,180,210,110,225,14,241,162,36,10,150,72,8,246,121,229,190,32,188,182,108,
71,85,57,206,171,48,141,15,127,98,203,194,53,117,187,10,73,224,214,9,66,122,111,162,212,227,251,113,82,183,187,144,236,127,55,55,11,215,112,255,203,64,152,121,115,108,4,191,55,115,245,135,32,201,23,0,
42,95,214,68,50,53,194,172,194,245,144,238,180,236,195,53,226,116,2,176,242,64,226,165,228,108,128,251,223,227,234,72,244,55,2,160,163,28,204,54,39,168,33,53,6,215,88,166,19,128,168,69,56,48,136,102,146,
244,104,115,40,66,148,246,131,135,111,194,65,97,58,1,168,157,62,165,194,115,245,40,64,90,49,0,81,116,153,185,14,60,245,21,208,209,75,207,101,122,73,24,21,29,41,230,213,126,178,148,16,95,43,33,229,241,
186,248,90,72,205,246,5,4,231,231,162,68,76,103,4,252,143,6,228,135,114,96,64,85,122,219,240,24,18,113,136,218,29,26,158,239,69,9,142,221,116,177,52,223,49,85,0,244,252,196,107,59,11,58,33,36,71,171,234,
248,104,18,28,179,198,38,129,16,129,75,135,30,34,100,51,194,106,131,40,87,6,212,108,231,90,57,222,232,3,209,153,27,227,128,218,157,47,65,110,73,165,100,68,251,36,0,145,212,120,238,7,223,1,40,132,5,133,
123,92,39,193,239,59,95,32,229,172,250,220,157,93,48,231,205,221,248,74,198,84,1,66,17,107,90,27,126,220,6,197,203,211,92,123,79,223,191,31,14,128,89,243,92,145,49,118,43,81,33,122,200,13,123,197,141,
158,20,135,75,77,22,125,108,224,30,192,229,162,241,252,163,198,9,158,72,126,57,248,187,59,1,141,7,152,18,50,25,0,182,25,1,152,48,98,28,21,19,219,103,98,96,88,250,141,0,194,236,36,19,164,191,6,192,143,
18,26,94,75,38,51,110,0,64,13,224,81,165,173,195,3,153,141,209,192,188,239,191,5,208,93,133,78,202,186,247,83,170,184,8,64,197,52,5,197,8,32,44,9,129,55,161,151,33,63,120,154,8,244,181,252,5,188,37,2,
98,103,207,133,232,236,101,0,119,127,64,158,119,25,162,18,6,128,86,153,21,120,154,44,64,221,2,220,40,219,3,245,247,186,142,30,185,214,121,60,43,201,150,82,152,85,191,49,229,249,60,103,106,225,219,0,183,
191,66,221,170,129,27,79,122,56,166,82,126,42,0,202,145,171,158,226,67,213,237,109,245,173,125,110,252,246,81,55,74,1,142,157,222,162,238,179,39,39,167,71,199,188,128,199,241,247,40,31,38,5,96,210,170,
37,81,71,162,111,186,92,154,191,67,224,225,45,14,136,43,68,184,11,30,159,252,206,170,207,170,27,89,126,105,205,196,206,118,15,178,194,66,45,197,148,20,165,175,217,176,42,247,155,244,149,5,0,205,191,225,
10,49,12,0,52,170,34,151,50,55,195,173,223,127,134,254,118,183,182,126,198,188,28,112,229,45,0,209,30,13,189,119,111,67,243,217,51,208,222,61,152,191,98,215,229,75,2,51,216,197,8,99,204,43,47,207,113,
110,205,30,135,172,54,153,166,192,3,162,23,42,247,175,48,103,45,166,180,248,12,171,167,8,164,231,34,64,107,39,216,93,139,97,78,81,17,40,7,15,158,163,165,94,96,134,67,19,104,11,89,68,206,175,167,22,78,
243,226,20,179,129,86,76,244,167,229,128,158,150,218,201,24,142,174,179,2,164,140,98,32,132,80,101,214,201,90,41,191,120,182,163,56,106,166,11,57,133,10,121,129,69,0,198,20,169,9,162,64,231,52,227,196,
176,150,31,125,85,7,71,218,189,86,9,235,62,93,26,12,133,72,103,175,95,222,80,184,227,210,201,175,215,231,88,158,75,138,44,113,38,198,173,78,200,157,135,7,116,154,69,96,34,210,241,227,83,81,192,208,59,
230,163,127,78,252,196,19,30,196,70,214,219,128,49,69,195,72,232,96,123,7,214,53,94,25,233,5,120,179,129,140,21,249,241,238,170,235,199,106,182,47,6,193,34,129,227,217,153,144,90,176,8,55,215,161,35,88,
81,205,216,7,172,9,248,27,167,27,150,177,17,14,182,162,210,224,248,254,49,99,33,184,43,175,67,199,181,195,32,88,37,72,204,155,11,206,188,66,164,187,25,6,26,155,161,241,228,41,56,118,253,225,102,154,129,
90,55,36,8,192,150,145,12,153,41,118,237,182,163,85,179,161,110,76,200,43,104,168,7,169,146,130,155,211,161,171,225,30,12,116,221,6,37,48,4,246,228,4,136,203,66,128,202,3,172,154,141,134,72,96,216,5,51,
116,212,54,192,130,143,171,86,88,68,158,251,99,211,64,73,82,245,63,249,116,118,40,68,186,127,170,116,127,84,86,209,124,138,210,83,227,0,209,104,136,233,211,125,133,121,98,168,251,150,4,24,146,157,112,
243,192,159,208,228,241,157,187,209,230,171,166,51,57,73,182,23,103,37,212,21,100,191,177,28,239,135,105,122,152,135,143,132,147,129,181,233,166,128,172,250,95,253,188,230,61,150,234,148,68,3,148,138,
76,130,6,18,134,244,20,50,26,167,222,216,92,208,124,248,10,84,254,235,253,246,253,95,234,247,227,96,63,155,60,244,250,66,215,252,109,146,88,150,179,241,21,84,213,193,202,10,167,151,98,173,121,1,134,15,
186,217,175,196,194,36,179,122,67,239,9,196,0,0,191,77,180,203,25,72,197,33,161,68,51,244,185,187,0,141,151,225,72,27,219,76,31,233,96,117,187,111,211,242,212,7,65,111,79,162,36,33,241,20,191,126,71,120,
252,14,162,48,208,253,97,218,177,66,187,146,193,11,162,181,231,160,199,75,99,67,203,179,151,121,50,92,172,104,175,23,67,4,122,212,64,32,81,187,25,170,38,29,0,121,202,102,164,183,99,69,243,246,177,6,138,
195,146,211,10,146,85,180,177,208,169,99,18,94,181,73,66,182,20,109,214,219,185,200,82,149,190,79,241,15,147,22,111,158,199,197,102,244,51,210,49,94,132,16,196,101,58,225,252,182,37,95,50,18,141,52,153,
51,91,151,148,198,101,198,3,31,139,0,34,237,163,123,204,68,215,57,213,8,168,60,231,171,221,115,222,166,170,227,239,15,28,146,137,199,86,22,97,21,150,210,210,201,186,165,150,31,246,8,113,109,207,93,47,
120,247,156,167,165,117,212,43,52,142,58,251,19,29,22,211,131,158,64,216,6,30,141,50,11,197,49,73,220,20,214,176,90,12,100,194,130,1,201,180,236,76,240,239,136,48,190,52,161,60,10,7,64,212,110,198,24,
184,48,209,10,178,12,144,71,47,134,26,245,164,39,172,31,98,57,63,233,237,228,63,1,6,0,114,69,96,175,198,186,206,158,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ShredderSlot::plugin_loaded_png = (const char*) resource_ShredderSlot_plugin_loaded_png;
const int ShredderSlot::plugin_loaded_pngSize = 1743;

// JUCER_RESOURCE: plugin_unloaded_png, 1660, "../../../../../Users/atom/Desktop/plugin_unloaded.png"
static const unsigned char resource_ShredderSlot_plugin_unloaded_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,25,116,69,88,116,83,111,102,116,
119,97,114,101,0,65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,0,0,6,30,73,68,65,84,120,218,164,87,107,108,83,101,24,126,219,158,158,245,198,182,118,99,151,18,215,149,64,118,
195,176,13,72,64,49,238,135,38,162,198,41,248,147,24,13,254,216,31,129,63,40,96,66,36,145,127,100,8,10,97,129,65,226,111,98,66,166,27,32,49,181,217,140,147,40,108,162,92,214,118,115,108,237,214,174,151,
109,189,223,142,239,251,237,180,235,74,179,211,177,47,121,211,246,124,61,239,253,125,158,239,147,129,244,146,159,63,127,254,93,173,86,115,67,46,87,226,82,64,52,26,77,132,195,225,15,143,28,57,242,35,238,
167,97,29,75,38,101,252,236,217,179,157,21,21,149,63,180,182,181,129,78,183,129,61,12,6,23,225,193,253,251,96,179,141,53,159,57,115,230,49,62,18,94,212,1,78,98,159,47,45,45,189,76,198,103,102,220,240,
232,177,21,4,65,128,29,59,218,161,161,177,17,34,145,112,47,254,167,3,37,254,162,14,200,37,246,213,50,25,84,233,245,6,248,247,209,99,224,56,142,201,228,228,36,168,213,106,116,38,109,192,255,168,214,83,
2,41,7,148,84,165,100,50,9,90,173,118,169,102,232,17,175,228,217,119,76,134,162,136,44,174,203,129,116,32,16,248,101,114,98,28,154,154,26,32,157,22,80,210,176,101,235,22,112,78,77,129,207,231,179,174,
183,9,165,28,136,157,62,125,250,243,137,137,9,168,55,153,40,229,172,7,54,86,86,194,180,115,10,78,157,58,213,189,158,250,23,227,64,36,24,12,122,18,137,120,58,20,10,131,70,163,101,14,144,136,125,63,79,78,
230,191,116,241,226,69,253,90,166,64,121,245,234,85,55,42,45,103,138,243,23,62,211,226,248,41,149,28,117,61,200,229,114,8,71,34,80,102,208,67,79,79,207,51,234,137,252,165,209,104,160,183,183,23,14,29,
58,84,34,149,33,114,64,75,198,223,120,243,45,22,89,1,125,172,241,70,70,70,129,231,151,154,239,193,200,3,120,101,247,30,40,228,240,146,14,25,12,13,90,161,179,179,211,120,243,230,205,9,41,7,248,76,90,127,
234,239,7,133,66,177,2,163,50,14,81,228,8,131,236,251,226,66,8,6,110,221,97,248,35,228,160,25,233,72,165,210,240,206,219,251,0,145,18,208,120,84,220,22,138,0,34,1,35,84,50,67,20,65,174,100,178,144,31,
105,161,232,83,169,84,110,22,5,41,148,204,58,32,224,75,13,13,13,128,200,7,73,84,50,31,8,32,250,205,176,177,35,167,138,89,153,244,195,74,7,164,167,128,94,18,208,80,50,17,3,219,216,19,112,62,155,4,141,90,
5,59,119,238,192,6,212,161,62,25,40,228,138,162,69,88,43,23,80,132,131,86,43,216,237,182,190,161,161,193,1,147,169,190,174,189,189,253,147,122,179,185,186,165,185,25,70,70,71,17,110,4,40,212,241,207,151,
69,198,38,103,45,14,36,7,7,7,187,126,181,88,166,29,227,227,83,68,118,52,154,215,175,95,239,239,238,238,238,69,30,216,90,93,93,13,158,89,183,100,41,50,37,160,214,204,233,17,197,165,75,151,190,70,14,249,
8,183,140,136,166,86,191,223,255,233,241,227,199,109,98,229,25,153,148,137,221,26,22,129,133,44,25,14,30,60,248,193,123,157,157,223,54,52,53,129,237,169,189,168,94,160,38,108,107,111,133,123,127,12,179,
62,162,101,220,180,9,234,76,245,140,192,220,179,179,240,244,201,19,240,122,231,246,30,59,118,236,55,78,52,56,39,54,76,46,174,123,209,224,84,166,67,105,60,139,113,128,50,96,183,59,96,123,107,91,22,55,66,
161,16,120,220,30,136,68,163,64,217,220,222,218,10,127,253,121,207,130,91,27,56,209,112,170,80,48,56,150,17,74,167,28,149,42,184,226,28,192,54,132,88,44,6,99,99,246,236,16,228,246,142,203,229,130,109,
45,219,168,77,200,182,122,53,42,149,183,180,108,235,50,232,43,32,26,143,23,157,129,76,83,231,227,68,198,9,122,158,78,103,227,85,50,36,188,118,237,90,12,231,221,141,196,243,241,209,163,71,111,31,62,124,
88,101,54,155,79,86,85,85,191,95,87,87,7,83,211,78,118,16,41,148,238,66,141,200,35,98,86,84,84,48,242,34,99,161,96,8,124,1,63,36,18,9,168,68,38,93,152,159,167,134,75,102,185,128,192,166,165,229,229,170,
113,135,163,191,167,231,50,70,203,195,198,170,74,104,108,108,2,191,63,192,104,152,234,73,36,163,82,45,29,128,226,152,230,32,214,54,149,74,174,112,132,28,168,169,169,1,135,221,134,39,167,255,48,68,37,152,
204,102,48,153,234,152,94,143,103,22,254,121,248,16,126,31,30,254,130,38,144,177,33,57,80,141,47,149,25,202,129,231,120,166,4,79,190,224,245,249,88,61,9,29,203,81,166,157,78,152,113,77,35,96,37,65,111,
48,128,209,104,68,204,143,192,252,194,252,138,20,19,103,144,241,174,174,174,125,232,184,12,207,20,39,209,161,189,180,143,167,43,223,192,192,192,151,125,125,125,63,19,221,115,25,202,165,211,206,156,103,
238,185,212,234,52,58,70,197,86,4,42,151,203,105,113,56,28,195,244,124,243,230,205,187,107,107,141,175,239,220,181,11,202,202,202,177,211,131,43,56,66,190,164,99,60,30,143,71,78,156,56,241,153,56,234,
196,116,33,20,183,40,49,46,247,128,78,117,206,175,171,174,116,3,252,61,114,31,70,71,71,190,187,112,225,194,247,68,134,226,214,141,142,142,142,86,188,39,92,217,243,234,107,152,177,200,50,251,44,171,240,
163,248,196,207,18,17,95,18,34,222,208,57,65,224,150,25,67,40,216,104,20,61,34,23,160,241,43,248,115,90,124,153,86,137,197,98,9,30,216,191,223,21,10,7,107,121,94,133,253,144,200,30,98,114,102,32,41,58,
189,184,58,27,82,126,178,103,129,204,56,41,96,1,235,139,61,66,249,245,138,145,100,192,138,184,94,153,74,167,253,201,120,178,150,47,41,17,51,12,107,39,35,153,40,133,50,160,209,150,1,42,215,137,169,203,
69,74,134,156,8,175,205,42,132,88,200,121,95,86,196,149,107,37,29,203,9,106,57,118,246,167,81,203,10,254,86,32,168,208,88,225,253,240,92,54,68,17,244,190,57,119,238,171,26,156,4,162,108,194,121,122,135,
116,144,46,210,185,134,171,153,44,120,247,206,45,29,157,9,132,252,139,35,193,48,58,129,6,232,10,166,22,217,146,150,10,141,29,152,115,187,225,238,237,91,217,186,179,232,25,98,202,22,17,140,20,94,175,87,
242,114,90,142,98,70,209,175,146,185,164,72,88,147,57,205,68,55,213,151,80,54,22,184,29,9,98,191,140,163,4,164,28,160,147,38,221,187,120,169,75,138,56,1,137,229,107,27,104,196,241,42,180,226,226,204,39,
86,83,250,191,0,3,0,82,125,152,137,47,19,79,153,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ShredderSlot::plugin_unloaded_png = (const char*) resource_ShredderSlot_plugin_unloaded_png;
const int ShredderSlot::plugin_unloaded_pngSize = 1660;
