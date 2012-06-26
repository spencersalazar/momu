#ifndef ATK_ONEZERO_H
#define ATK_ONEZERO_H

#import "atk_filter.h"

namespace atk {

/***************************************************/
/*! \class OneZero
  \brief ATK one-zero filter class.

  This class implements a one-zero digital filter.  A method is
  provided for setting the zero position along the real axis of the
  z-plane while maintaining a constant filter gain.

  by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
*/
/***************************************************/

class OneZero : public Filter
{
	
public:

	//! The default constructor creates a low-pass filter (zero at z = -1.0).
	OneZero( AtkFloat theZero = -1.0 );

	//! Class destructor.
	~OneZero();

	//! Set the b[0] coefficient value.
	void setB0( AtkFloat b0 ) { m_b[0] = b0; };

	//! Set the b[1] coefficient value.
	void setB1( AtkFloat b1 ) { m_b[1] = b1; };

	//! Set all filter coefficients.
	void setCoefficients( AtkFloat b0, AtkFloat b1, bool clearState = false );

	//! Set the zero position in the z-plane.
  
    //This method sets the zero position along the real-axis of the
    //z-plane and normalizes the coefficients for a maximum gain of one.
    //A positive zero value produces a high-pass filter, while a
    //negative zero value produces a low-pass filter.  This method does
    //not affect the filter \e gain value.
  
	void setZero( AtkFloat theZero );

	//! Return the last computed output value.
	AtkFloat lastOut( void ) const { return m_lastValue; };

	//! Input one sample to the filter and return one output.
	AtkFloat tick( AtkFloat input );

};

inline AtkFloat OneZero :: tick( AtkFloat input )
{
	m_inputs[0] = m_gain * input;
	m_lastValue = m_b[1] * m_inputs[1] + m_b[0] * m_inputs[0];
	m_inputs[1] = m_inputs[0];

	return m_lastValue;
}

} // atk namespace

#endif

