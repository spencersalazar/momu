/*#ifndef ATK_POLEZERO_H
#define ATK_POLEZERO_H

#import "atk_filter.h"

namespace atk {

/////////////////////////////////////////////////////////
//  \class PoleZero
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

class PoleZero : public Filter
{

public:

	//! Default constructor creates a first-order pass-through filter.
	PoleZero();

	//! Class destructor.
	~PoleZero();

	//! Set the b[0] coefficient value.
	void setB0( AtkFloat b0 ) { m_b[0] = b0; };

	//! Set the b[1] coefficient value.
	void setB1( AtkFloat b1 ) { m_b[1] = b1; };

	//! Set the a[1] coefficient value.
	void setA1( AtkFloat a1 ) { m_a[1] = a1; };

	//! Set all filter coefficients.
	void setCoefficients( AtkFloat b0, AtkFloat b1, AtkFloat a1, bool clearState = false );

	//! Set the filter for allpass behavior using \e coefficient.
	 
    //This method uses \e coefficient to create an allpass filter,
    //which has unity gain at all frequencies.  Note that the \e
    //coefficient magnitude must be less than one to maintain stability.
  
	void setAllpass( AtkFloat coefficient );

	//! Create a DC blocking filter with the given pole position in the z-plane.
  
    //This method sets the given pole position, together with a zero
    //at z=1, to create a DC blocking filter.  \e thePole should be
    //close to one to minimize low-frequency attenuation.

	void setBlockZero( AtkFloat thePole = 0.99 );

	//! Return the last computed output value.
	AtkFloat lastOut( void ) const { return m_lastValue; };

	//! Input one sample to the filter and return one output.
	AtkFloat tick( AtkFloat input );

};

inline AtkFloat PoleZero :: tick( AtkFloat input )
{
	m_inputs[0] = m_gain * input;
	m_lastValue = m_b[0] * m_inputs[0] + m_b[1] * m_inputs[1] - m_a[1] * m_outputs[1];
	m_inputs[1] = m_inputs[0];
	m_outputs[1] = m_lastValue;

  return m_lastValue;
}



} // atk namespace

#endif
*/