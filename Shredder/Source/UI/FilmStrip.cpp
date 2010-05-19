#include "FilmStrip.h"

FilmStripComponent::FilmStripComponent (Image *_componentStrip) : componentStrip(_componentStrip)
{
	if (componentStrip == 0)
		return;

	if (componentStrip->getWidth() > componentStrip->getHeight())
	{
		frameCount		= componentStrip->getWidth() / componentStrip->getHeight();
		frameSize		= componentStrip->getHeight();
		isVerticalStrip	= false;
	}
	else
	{
		frameCount		= componentStrip->getHeight() / componentStrip->getWidth();
		frameSize		= componentStrip->getWidth();
		isVerticalStrip	= true;
	}
}

/* thanks to anita for the math */

void FilmStripComponent::drawFrame (Graphics &g, int x, int y, int width, int height, Slider &slider)
{
	double pos;
	const double r		= abs(slider.getMaximum()) + abs(slider.getMinimum());
	const double div	= r / frameCount;
	const double v		= slider.getValue();

	if (slider.getMinimum() < 0 && slider.getMaximum() > 0)
	{
		if (v < 0)
		{
			pos			= (int)( ((r/2) - abs(v)) / div );
		}
		else
		{
			pos			= (int)( ((r/2) + v) / div );
		}
	}
	else if (slider.getMinimum() <= 0 && slider.getMaximum() > 0)
	{
		pos			= abs((int)(v / div));
	}
	else if (slider.getMinimum() < 0 && slider.getMaximum() == 0)
	{
		pos			= (int)( (r + v) / div);
	}
	else if (slider.getMinimum() >= 0 && slider.getMaximum() > 0)
	{
		pos			= (int)(v / div);
	}
	else if (slider.getMinimum() > 0 && slider.getMaximum() == 0)
	{
		pos			= (int)( abs(v-r) / div);
	}

	if (pos > 0)
		pos = pos - 1;

	if (width != height) /* scale */
	{
		x		= (width / 2) - (height / 2);
		width	= height;
	}

	if (isVerticalStrip)
	{
		g.drawImage (componentStrip, x, y, width, height, 0, (int)(pos*frameSize), frameSize, frameSize, false);
	}
	else
	{
		g.drawImage (componentStrip, x, y, width, height, (int)(pos*frameSize), 0, frameSize, frameSize, false);
	}
}

void FilmStripComponent::drawFrame (Graphics &g, int x, int y, int width, int height, const bool isMouseOverButton, const bool isButtonDown, ToggleButton &button)
{
	int pos = 0;

	if (button.getToggleState())
		pos = 1;
	else
		pos = 0;

	g.drawImage (componentStrip, x, y, width, height, 0, (int)(pos*frameSize), frameSize, frameSize, false); 
}

const int FilmStripComponent::getImageWidth()
{
	if (componentStrip)
	{
		return (componentStrip->getWidth());
	}
	else
	{
		return (0);
	}
}
