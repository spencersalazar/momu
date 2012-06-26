/////////////////////////////////////////////////////////
// \class OnePole
//    \brief ATK one-pole filter class.
//
//    This class implements a one-pole digital filter.  A method is
//    provided for setting the pole position along the real axis of the
//    z-plane while maintaining a constant peak filter gain.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////

/*
#import "atk_onePole.h"

namespace atk {

OnePole :: OnePole( AtkFloat thePole )
{
	m_b.resize( 1 );
	m_a.resize( 2 );
	m_inputs.resize( 1, 0.0 );
	m_outputs.resize( 2, 0.0 );
	this->setPole( thePole );
}

OnePole :: ~OnePole()    
{}

void OnePole :: setPole( AtkFloat thePole )
{
	// Normalize coefficients for peak unity gain.
	if ( thePole > 0.0 )
		m_b[0] = (AtkFloat) (1.0 - thePole);
	else
		m_b[0] = (AtkFloat) (1.0 + thePole);

	m_a[1] = -thePole;
}

void OnePole :: setCoefficients( AtkFloat b0, AtkFloat a1, bool clearState )
{
	m_b[0] = b0;
	m_a[1] = a1;

	if ( clearState ) 
		this->clear();
}

} // atk namespace
*/