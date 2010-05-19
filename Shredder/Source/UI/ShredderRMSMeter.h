#ifndef __SHREDDER_RMS_METER_F3B1C8C4__
#define __SHREDDER_RMS_METER_F3B1C8C4__

#include "Includes.h"

class ShredderRMSMeter : public Component
{
	public:
		ShredderRMSMeter();
		void setLevel (const float _rmsLevel);
		void paint (Graphics &g);
		void resized();

	private:
		float rmsLevel;
		ColourGradient cg;
};

#endif