/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  9 May 2010 7:29:09pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_IMAGESELECTBUTTON_IMAGESELECTBUTTON_E13949A2__
#define __JUCER_HEADER_IMAGESELECTBUTTON_IMAGESELECTBUTTON_E13949A2__

//[Headers]     -- You can add your own extra header files here --
#include "Includes.h"

class SelectionItem
{
	public:
		Image *icon;
		String name;
		double value;
};

class ImageSelectButtonListener : public ButtonListener, public ChangeBroadcaster
{
	public:
		void buttonClicked (Button *buttonThatWasClicked) { sendChangeMessage (buttonThatWasClicked); }
};

class ImageSelectButtonLook : public LookAndFeel
{
	public:
		void drawPopupMenuBackground  (Graphics &g, int width, int height)
		{
			Colour bg = findColour (PopupMenu::backgroundColourId);
			ColourGradient cg(bg, 0.0f, 0.0f, bg.brighter (0.2f), 0.0f, (float)height, false);
			g.setGradientFill (cg);
			g.fillRect (0.0f, 0.0f, (float)width, (float)height);
		}

		const Font getPopupMenuFont()
		{
			return (Font (14, Font::bold));
		}
};
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ImageSelectButton  : public Slider,
                           public ChangeListener
{
public:
    //==============================================================================
    ImageSelectButton (const String &name);
    ~ImageSelectButton();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void addItem (Image *itemIcon, const String &itemName, const double itemValue);
	int compareElements(SelectionItem *first, SelectionItem *second);
	SelectionItem *getItem (const double _value);
	void buttonValueChanged();
	void valueChanged();
	void setButtonValue (double newValue, bool sendUpdateMessage=true, bool sendMessageSynchronously=false);
	void createMenu();
	void lookAndFeelChanged ();
	void changeListenerCallback (void* objectThatHasChanged);
	PopupMenu *getPopupMenu() { return (&internalMenu); }
	LookAndFeel *getPopupMenuLookAndFeel() { return (&menuLookAndFeel); }
	void mouseWheelMove (const MouseEvent  &e, float wheelIncrementX, float wheelIncrementY);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* empty_png;
    static const int empty_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	OwnedArray <SelectionItem> items;
	PopupMenu internalMenu;
	ImageSelectButtonListener buttonListener;
	ImageSelectButtonLook menuLookAndFeel;
    //[/UserVariables]

    //==============================================================================
    ImageButton* button;
    Label* label;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ImageSelectButton (const ImageSelectButton&);
    const ImageSelectButton& operator= (const ImageSelectButton&);
};


#endif   // __JUCER_HEADER_IMAGESELECTBUTTON_IMAGESELECTBUTTON_E13949A2__
