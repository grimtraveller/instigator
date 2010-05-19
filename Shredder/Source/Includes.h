#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#if JUCE_DEBUG
#include <amalgamation/juce_amalgamated_template.h>
#else
#include <juce_amalgamated.h>
#endif

#include "JucePluginCharacteristics.h"

#define Log(x)			Logger::writeToLog(x)
#define Pic(x,y)		ImageCache::getFromMemory (x,y)


void applyLookAndFeelToToggleButtons (Component *parentComponent, const String &buttonPrefix, LookAndFeel *lookAndFeelToApply);
void applyLookAndFeelToToggleButtons (Component *parentComponent, LookAndFeel *lookAndFeelToApply);
Array <ToggleButton *> getToggleButtonsByPrefix(Component *parentComponent, const String &prefix);
Array <ToggleButton *> getToggleButtons (Component *parentComponent);
Array <ComboBox *> getCombosByPrefix(Component *parentComponent, const String &prefix);
Component *getComponentByName(Component *parentComponent, const String &componentName);
Array <Slider *> getSlidersByPrefix(Component *parentComponent, const String &prefix);
void applyLookAndFeelToSliders (Component *parentComponent, const String &sliderPrefix, LookAndFeel *lookAndFeelToApply);
void applyLookAndFeelToSliders (Component *parentComponent, LookAndFeel *lookAndFeelToApply);

const String timeToTimecodeString (const double seconds);
const String ppqToBarsBeatsString (const double ppq, const double lastBarPPQ, const int numerator, const int denominator);
#endif