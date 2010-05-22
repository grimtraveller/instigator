/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  21 May 2010 11:03:54pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SHREDDERRESOURCES_SHREDDERRESOURCES_43E099F0__
#define __JUCER_HEADER_SHREDDERRESOURCES_SHREDDERRESOURCES_43E099F0__

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
    static const char* whiteknob_png;
    static const int whiteknob_pngSize;
    static const char* btn_blue_png;
    static const int btn_blue_pngSize;
    static const char* btn_green_png;
    static const int btn_green_pngSize;
    static const char* btn_yellow_png;
    static const int btn_yellow_pngSize;
    static const char* btn_white_png;
    static const int btn_white_pngSize;

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


#endif   // __JUCER_HEADER_SHREDDERRESOURCES_SHREDDERRESOURCES_43E099F0__
