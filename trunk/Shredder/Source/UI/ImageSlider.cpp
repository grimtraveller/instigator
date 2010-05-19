#include "ImageSlider.h"

ImageSlider::ImageSlider(Image *rotarySliderImage, Font _textBoxFont) 
	: knobStrip(rotarySliderImage), textBoxFont(_textBoxFont)
{
}

ImageSlider::~ImageSlider()
{
}

void ImageSlider::drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPosProportional, const float rotaryStartAngle, const float rotaryEndAngle, Slider &slider)
{
	knobStrip.drawFrame (g, x, y, width, height, slider);
}

Label *ImageSlider::createSliderTextBox (Slider &slider)
{
	Label *l = new Label (slider.getName(), slider.getTextFromValue (slider.getValue()));
	l->setColour (Label::backgroundColourId, slider.findColour (Slider::textBoxBackgroundColourId));
	l->setColour (Label::textColourId, slider.findColour (Slider::textBoxTextColourId));
	l->setJustificationType (Justification::centred);
	l->setColour (Label::outlineColourId, slider.findColour (Slider::textBoxOutlineColourId));
    l->setColour (TextEditor::textColourId, slider.findColour (Slider::textBoxTextColourId));
    l->setColour (TextEditor::backgroundColourId, slider.findColour (Slider::textBoxBackgroundColourId));
    l->setColour (TextEditor::outlineColourId, slider.findColour (Slider::textBoxOutlineColourId));
	l->setColour (TextEditor::highlightColourId, slider.findColour (Slider::textBoxHighlightColourId));
	l->setFont (textBoxFont);

	return (l);
}
