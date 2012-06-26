/////////////////////////////////////////////////////////
// \class OneZero
//    \brief ATK one-zero filter class.
//
//    This class implements a one-zero digital filter.  A method is
//    provided for setting the zero position along the real axis of the
//    z-plane while maintaining a constant filter gain.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////
/*
#import "atk_oneZero.h"

namespace atk {

OneZero :: OneZero( AtkFloat theZero )
{
	m_b.resize( 2 );
	m_inputs.resize( 2, 0.0 );
	this->setZero( theZero );
}

OneZero :: ~OneZero( void )
{}

void OneZero :: setZero( AtkFloat theZero )
{
	// Normalize coefficients for unity gain.
	if ( theZero > 0.0 )
		m_b[0] = 1.0 / ((AtkFloat) 1.0 + theZero);
	else
		m_b[0] = 1.0 / ((AtkFloat) 1.0 - theZero);

	m_b[1] = -theZero * m_b[0];
}

void OneZero :: setCoefficients( AtkFloat b0, AtkFloat b1, bool clearState )
{
	m_b[0] = b0;
	m_b[1] = b1;

	if ( clearState ) 
		this->clear();
}

} // atk namespace
*/