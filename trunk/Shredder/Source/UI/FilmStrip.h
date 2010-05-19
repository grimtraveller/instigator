#ifndef __FILM_STIP_8605BE1B__
#define __FILM_STIP_8605BE1B__

#include "Includes.h"

class FilmStripComponent
{
	public:
		FilmStripComponent (Image *_componentStrip);
		void drawFrame (Graphics &g, int x, int y, int width, int height, Slider &slider);
		void drawFrame (Graphics &g, int x, int y, int width, int height, const bool isMouseOverButton, const bool isButtonDown, ToggleButton &button);
		const int getImageWidth();

	private:
		Image *componentStrip;
		int frameCount;
		int frameSize;
		bool isVerticalStrip;
};

#endif
