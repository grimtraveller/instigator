#ifndef __IMAGE_TOGGLEBUTTON_8605BE1B__
#define __IMAGE_TOGGLEBUTTON_8605BE1B__

#include "Includes.h"
#include "FilmStrip.h"

class ImageToggleButton  : public LookAndFeel
{
	public:
		ImageToggleButton(Image *toggleButtonImage, Font _toggleButtonFont);
		~ImageToggleButton();
		void drawToggleButton (Graphics &g, ToggleButton &button, bool isMouseOverButton, bool isButtonDown);

	private:
		FilmStripComponent toggleStrip;
		Font toggleFont;
};

#endif
