/////////////////////////////////////////////////////////
// \class TwoPole
//    \brief ATK two-pole filter class.
//
//    This class implements a two-pole digital filter.  A method is
//    provided for creating a resonance in the frequency response while
//    maintaining a nearly constant filter gain.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////

/*
#import "atk_twoPole.h"
#import <cmath>

namespace atk {

TwoPole :: TwoPole( void )
{
	m_b.resize( 1 );
	m_a.resize( 3 );
	m_inputs.resize( 1, 0.0 );
	
	m_outputs.resize( 3, 0.0 );
	m_b[0] = 1.0;
	m_a[0] = 1.0;

	Atk::addSampleRateAlert( this );
}

TwoPole :: ~TwoPole()
{
	Atk::removeSampleRateAlert( this );
}

void TwoPole :: sampleRateChanged( AtkFloat newRate, AtkFloat oldRate )
{
	if ( !m_ignoreSampleRateChange ) 
	{
		m_errorString << "TwoPole::sampleRateChanged: you may need to recompute filter coefficients!";
		handleError( AtkError::WARNING );
	}
}

void TwoPole :: setResonance( AtkFloat frequency, AtkFloat radius, bool normalize )
{
	m_a[2] = radius * radius;
	m_a[1] = (AtkFloat) -2.0 * radius * cos(ATK_TWO_PI * frequency / Atk::sampleRate());

	if ( normalize ) 
	{
		// Normalize the filter gain ... not terribly efficient.
		AtkFloat real = 1 - radius + (m_a[2] - radius) * cos(ATK_TWO_PI * 2 * frequency / Atk::sampleRate());
		AtkFloat imag = (m_a[2] - radius) * sin(ATK_TWO_PI * 2 * frequency / Atk::sampleRate());
		m_b[0] = sqrt( pow(real, 2) + pow(imag, 2) );
	}
}

void TwoPole :: setCoefficients( AtkFloat b0, AtkFloat a1, AtkFloat a2, bool clearState )
{
	m_b[0] = b0;
	m_a[1] = a1;
	m_a[2] = a2;

	if ( clearState ) this->clear();
}

} // atk namespace
*/