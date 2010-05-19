#include "ShredderRMSMeter.h"

ShredderRMSMeter::ShredderRMSMeter()
{
}

void ShredderRMSMeter::paint (Graphics &g)
{
	int width	= getWidth();
	int height	= getHeight();

	/*g.setColour (Colours::white.withAlpha (0.7f));
    g.fillRoundedRectangle (0.0f, 0.0f, (float) width, (float) height, 3.0f);

    g.setColour (Colours::black.withAlpha (0.2f));
    g.drawRoundedRectangle (1.0f, 1.0f, width - 2.0f, height - 2.0f, 3.0f, 1.0f);
	*/

    const int totalBlocks = 32;
    const int numBlocks = roundToInt (totalBlocks * rmsLevel);
    const float w = (width) / (float) totalBlocks;

    for (int i = 0; i < totalBlocks; ++i)
    {
        if (i >= numBlocks)
		{
			g.setColour (Colours::black.withAlpha (0.6f));
		}
        else
		{
			g.setColour (cg.getColourAtPosition ( (3.0f + i * w + w * 0.1f)/width));
		}

        g.fillRoundedRectangle (3.0f + i * w + w * 0.1f, 3.0f, w * 0.8f, height - 6.0f, w * 0.4f);
    }
}

void ShredderRMSMeter::setLevel (const float _rmsLevel)
{
	if (rmsLevel != _rmsLevel)
	{		
		rmsLevel = _rmsLevel;
		repaint();
	}
}

void ShredderRMSMeter::resized()
{
	cg = ColourGradient (Colours::yellow, (float)getX(), (float)(getY()+getHeight())/2, Colours::red, (float)getX()+getWidth(), (float)(getY()+getHeight())/2, false);
}