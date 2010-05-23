/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  24 May 2010 12:57:22am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDERSHUFFLEBUTTON_SHREDDERSHUFFLEBUTTON_328E3165__
#define __JUCER_HEADER_SHREDDERSHUFFLEBUTTON_SHREDDERSHUFFLEBUTTON_328E3165__

//[Headers]     -- You can add your own extra header files here --
#include "Includes.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ShredderShuffleButton  : public Button
{
public:
    //==============================================================================
    ShredderShuffleButton ();
    ~ShredderShuffleButton();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void resized();
    void paintButton (Graphics& g, bool isMouseOverButton, bool isButtonDown);

    // Binary resources:
    static const char* btn_violet_png;
    static const int btn_violet_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    Image* cachedImage_btn_violet_png;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ShredderShuffleButton (const ShredderShuffleButton&);
    const ShredderShuffleButton& operator= (const ShredderShuffleButton&);
};


#endif   // __JUCER_HEADER_SHREDDERSHUFFLEBUTTON_SHREDDERSHUFFLEBUTTON_328E3165__
