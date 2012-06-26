/***************************************************/
/*! \class TwoZero
    \brief ATK two-zero filter class.

    This class implements a two-zero digital filter.  A method is
    provided for creating a "notch" in the frequency response while
    maintaining a constant filter gain.

    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
*/
/***************************************************/

#import "atk_twoZero.h"
#import <cmath>

namespace atk {

TwoZero :: TwoZero( void )
{
		//Resize the 2D vectors to the correct size
		m_inputs.resize(3);
		m_outputs.resize(3);
		 
		for(int i=0; i < m_numChannels; i++)
		{
			m_inputs[i].resize(3, 0.0);
			m_outputs[i].resize(1, 0.0);
		}
 
		//Resize the coeff vectors
		m_b.resize( 3, 0.0 );
		m_b[0] = 1.0;
		

		Atk::addSampleRateAlert( this );
}

TwoZero :: ~TwoZero()
{
	Atk::removeSampleRateAlert( this );
}

void TwoZero :: sampleRateChanged( AtkFloat newRate, AtkFloat oldRate )
{
	if ( !m_ignoreSampleRateChange ) 
	{
		m_errorString << "TwoZero::sampleRateChanged: you may need to recompute filter coefficients!";
		handleError( AtkError::WARNING );
	}
}

void TwoZero :: setCoefficients( AtkFloat b0, AtkFloat b1, AtkFloat b2, bool clearState )
{
	m_b[0] = b0;
	m_b[1] = b1;
	m_b[2] = b2;

	if ( clearState ) 
		this->clear();
}


} // atk namespace
