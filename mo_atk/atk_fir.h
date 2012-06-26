/*#ifndef ATK_FIR_H
#define ATK_FIR_H

#import "atk_filter.h"

namespace atk {

/////////////////////////////////////////////////////////
// \class Fir
//    \brief ATK general finite impulse response filter class.
//
//    This class provides a generic digital filter structure that can be
//    used to implement FIR filters.  For filters with feedback terms,
//    the Iir class should be used.
//
//    In particular, this class implements the standard difference
//    equation:
//
//    y[n] = b[0]*x[n] + ... + b[nb]*x[n-nb]
//
//    The \e gain parameter is applied at the filter input and does not
//    affect the coefficient values.  The default gain value is 1.0.
//    This structure results in one extra multiply per computed sample,
//    but allows easy control of the overall filter gain.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////
class Fir : public Filter
{
public:
	//! Default constructor creates a zero-order pass-through "filter".
	Fir( void );

	//! Overloaded constructor which takes filter coefficients.
	 
	//An AtkError can be thrown if the coefficient vector size is
	//zero.
	 
	Fir( std::vector<AtkFloat> &coefficients );

	//! Class destructor.
	~Fir( void );

	//! Set filter coefficients.
	 
	//An AtkError can be thrown if the coefficient vector size is
	//zero.  The internal state of the filter is not cleared unless the
	//\e clearState flag is \c true.
	 
	void setCoefficients( std::vector<AtkFloat> &coefficients, bool clearState = false );

	//! Return the last computed output value.
	AtkFloat lastOut( void ) const { return m_lastValue; };

	//! Input one sample to the filter and return one output.
	AtkFloat tick( AtkFloat input );

protected:

};

inline AtkFloat Fir :: tick( AtkFloat input )
{
	m_lastValue = 0.0;
	m_inputs[0] = m_gain * input;

	for ( unsigned int i=m_b.size()-1; i>0; i-- ) 
	{
		m_lastValue += m_b[i] * m_inputs[i];
		m_inputs[i] = m_inputs[i-1];
	}
	m_lastValue += m_b[0] * m_inputs[0];

	return m_lastValue;
}

} // atk namespace

#endif
*/