#include "ImageToggleButton.h"

ImageToggleButton::ImageToggleButton(Image *toggleButtonImage, Font _toggleButtonFont) 
	: toggleStrip(toggleButtonImage), toggleFont(_toggleButtonFont)
{
}

ImageToggleButton::~ImageToggleButton()
{
}

void ImageToggleButton::drawToggleButton (Graphics &g, ToggleButton &button, bool isMouseOverButton, bool isButtonDown)
{
	toggleStrip.drawFrame (g, 0, 0, button.getHeight(), button.getHeight(), isMouseOverButton, isButtonDown, button);
	
	g.setColour (button.findColour (ToggleButton::textColourId));
	g.setFont (toggleFont);
	
	g.drawFittedText (button.getButtonText(), toggleStrip.getImageWidth()+2, 0, button.getWidth() - toggleStrip.getImageWidth() - 2, button.getHeight(), Justification::centred, 3);
}
