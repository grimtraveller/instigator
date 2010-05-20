/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  20 May 2010 9:45:20pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDERRESOURCES_SHREDDERRESOURCES_18F4633C__
#define __JUCER_HEADER_SHREDDERRESOURCES_SHREDDERRESOURCES_18F4633C__

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
class ShredderResources  : public Component
{
public:
    //==============================================================================
    ShredderResources ();
    ~ShredderResources();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* btn_seq_png;
    static const int btn_seq_pngSize;
    static const char* btn_led_png;
    static const int btn_led_pngSize;
    static const char* shredder_bg_jpg;
    static const int shredder_bg_jpgSize;
    static const char* _60sekuntia_jfont;
    static const int _60sekuntia_jfontSize;
    static const char* knob0_png;
    static const int knob0_pngSize;
    static const char* onoff_png;
    static const int onoff_pngSize;
    static const char* whiteknob_png;
    static const int whiteknob_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ShredderResources (const ShredderResources&);
    const ShredderResources& operator= (const ShredderResources&);
};


#endif   // __JUCER_HEADER_SHREDDERRESOURCES_SHREDDERRESOURCES_18F4633C__
