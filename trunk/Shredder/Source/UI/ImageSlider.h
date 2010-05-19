#ifndef __IMAGE_SLIDER_8605BE1B__
#define __IMAGE_SLIDER_8605BE1B__

#include "Includes.h"
#include "FilmStrip.h"

class ImageSlider  : public LookAndFeel
{
	public:
		ImageSlider(Image *rotarySliderImage, Font _textBoxFont);
		~ImageSlider();
		void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &slider);
		Label *createSliderTextBox (Slider &slider);

	private:
		FilmStripComponent knobStrip;
		Font textBoxFont;
};

#endif
