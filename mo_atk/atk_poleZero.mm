/////////////////////////////////////////////////////////
// \class PoleZero
//    \brief ATK one-pole, one-zero filter class.
//
//    This class implements a one-pole, one-zero digital filter.  A
//    method is provided for creating an allpass filter with a given
//    coefficient.  Another method is provided to create a DC blocking
//    filter.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////
/*
#import "atk_poleZero.h"

namespace atk {

PoleZero :: PoleZero()
{
	// Default setting for pass-through.
	m_b.resize( 2, 0.0 );
	m_a.resize( 2, 0.0 );
	m_b[0] = 1.0;
	m_a[0] = 1.0;
	m_inputs.resize( 2, 0.0 );
	m_outputs.resize( 2, 0.0 );
}

PoleZero :: ~PoleZero()
{}

void PoleZero :: setCoefficients( AtkFloat b0, AtkFloat b1, AtkFloat a1, bool clearState )
{
	m_b[0] = b0;
	m_b[1] = b1;
	m_a[1] = a1;

	if ( clearState ) 
		this->clear();
}

void PoleZero :: setAllpass( AtkFloat coefficient )
{
	m_b[0] = coefficient;
	m_b[1] = 1.0;
	m_a[0] = 1.0; // just in case
	m_a[1] = coefficient;
}

void PoleZero :: setBlockZero( AtkFloat thePole )
{
	m_b[0] = 1.0;
	m_b[1] = -1.0;
	m_a[0] = 1.0; // just in case
	m_a[1] = -thePole;
}

} // atk namespace
*/