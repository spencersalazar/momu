/*#ifndef ATK_ONEPOLE_H
#define ATK_ONEPOLE_H

#import "atk_filter.h"

namespace atk {

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

class OnePole : public Filter
{
	
public:

	//! The default constructor creates a low-pass filter (pole at z = 0.9).
	OnePole( AtkFloat thePole = 0.9 );

	//! Class destructor.
	~OnePole();

	//! Set the b[0] coefficient value.
	void setB0( AtkFloat b0 ) { m_b[0] = b0; };

	//! Set the a[1] coefficient value.
	void setA1( AtkFloat a1 ) { m_a[1] = a1; };

	//! Set all filter coefficients.
	void setCoefficients( AtkFloat b0, AtkFloat a1, bool clearState = false );

	//! Set the pole position in the z-plane.
  
    //This method sets the pole position along the real-axis of the
    //z-plane and normalizes the coefficients for a maximum gain of one.
    //A positive pole value produces a low-pass filter, while a negative
    //pole value produces a high-pass filter.  This method does not
    //affect the filter \e gain value.
  
	void setPole( AtkFloat thePole );

	//! Return the last computed output value.
	AtkFloat lastOut( void ) const { return m_lastValue; };

	//! Input one sample to the filter and return one output.
	AtkFloat tick( AtkFloat input );

};

inline AtkFloat OnePole :: tick( AtkFloat input )
{
	m_inputs[0] = m_gain * input;
	m_lastValue = m_b[0] * m_inputs[0] - m_a[1] * m_outputs[1];
	m_outputs[1] = m_lastValue;

	return m_lastValue;
}

} // atk namespace

#endif
*/