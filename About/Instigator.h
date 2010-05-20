/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  21 May 2010 12:31:12am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_INSTIGATOR_INSTIGATOR_2BFE15DE__
#define __JUCER_HEADER_INSTIGATOR_INSTIGATOR_2BFE15DE__

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
class Instigator  : public Component
{
public:
    //==============================================================================
    Instigator ();
    ~Instigator();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* instigator_logo_png;
    static const int instigator_logo_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    HyperlinkButton* hyperlinkButton;
    Image* cachedImage_instigator_logo_png;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    Instigator (const Instigator&);
    const Instigator& operator= (const Instigator&);
};


#endif   // __JUCER_HEADER_INSTIGATOR_INSTIGATOR_2BFE15DE__
