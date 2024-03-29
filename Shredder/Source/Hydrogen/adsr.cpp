/*
 * Hydrogen
 * Copyright(c) 2002-2008 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "adsr.h"
#include "getTableValue.h"
#include "TableExponential.h"

inline static float linear_interpolation( float fVal_A, float fVal_B, double fVal )
{
	return (float)(fVal_A * ( 1 - fVal ) + fVal_B * fVal);
}


ADSR::ADSR (float attack, float decay, float sustain, float release) :	__attack( attack ),
																		__decay( decay ), 
																		__sustain( sustain ), 
																		__release( release ), 
																		__state( ATTACK ), 
																		__ticks( 0.0 ),
																		___value( 0.0 )
{
}



ADSR::ADSR (const ADSR& orig) : __attack( orig.__attack )
								, __decay( orig.__decay )
								, __sustain( orig.__sustain )
								, __release( orig.__release )
								, __state( orig.__state )
								, __ticks( orig.__ticks )
								, ___value( orig.___value )
{
}



ADSR::~ADSR()
{
}


float ADSR::process (float step)
{
	switch ( __state )
	{
		case ATTACK:
			if ( __attack == 0 ) 
			{
			___value = 1.0;
			} 
			else 
			{
				___value = getTableValue ( linear_interpolation( 0.0, 1.0, ( __ticks * 1.0 / __attack ) ), tableExponentConvex, tableExponentConvexSize );
			}

			__ticks += step;
			if ( __ticks > __attack ) 
			{
				__state = DECAY;
				__ticks = 0;
			}
			break;

		case DECAY:
			if ( __decay == 0 )
			{
				___value = __sustain;
			}
			else
			{
				___value = getTableValue ( linear_interpolation( 1.0, __sustain, ( __ticks * 1.0 / __decay ) ), tableExponentConcave, tableExponentConcaveSize );
			}

			__ticks += step;
			if ( __ticks > __decay )
			{
				__state = SUSTAIN;
				__ticks = 0;
			}
			break;

		case SUSTAIN:
			___value = __sustain;
			break;

		case RELEASE:
			if ( __release < 256 )
			{
				__release = 256;
			}
			___value = getTableValue ( linear_interpolation( __release_value, 0.0, ( __ticks * 1.0 / __release ) ), tableExponentConcave, tableExponentConcaveSize );

			__ticks += step;
			if ( __ticks > __release )
			{
				__state = IDLE;
				__ticks = 0;
			}
			break;

		case IDLE:
		default:
			___value = 0;
	};

	return ___value;
}

float ADSR::release()
{
	if ( __state == IDLE )
	{
		return 0;
	}

	if ( __state != RELEASE ) 
	{
		__release_value = ___value;
		__state = RELEASE;
		__ticks = 0;
		return __release_value;
	}

	return 1;
}

XmlElement *ADSR::createXml()
{
	XmlElement *e = new XmlElement (T("adsr"));
	e->setAttribute (T("attack"),	__attack);
	e->setAttribute (T("decay"),	__decay);
	e->setAttribute (T("sustain"),	__sustain);
	e->setAttribute (T("release"),	__release);

	return (e);
}

void ADSR::loadXml(XmlElement *xmlState)
{
	if (xmlState)
	{
		__attack	= (float)xmlState->getDoubleAttribute (T("attack"), 0.0);
		__decay		= (float)xmlState->getDoubleAttribute (T("decay"), 0.0);
		__sustain	= (float)xmlState->getDoubleAttribute (T("sustain"), 1.0);
		__release	= (float)xmlState->getDoubleAttribute (T("release"), 0.0);
	}
}