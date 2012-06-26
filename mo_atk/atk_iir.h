/*#ifndef ATK_IIR_H
#define ATK_IIR_H

#import "atk_filter.h"

namespace atk {

/////////////////////////////////////////////////////////
//	 \class Iir
//    \brief ATK general infinite impulse response filter class.
//
//    This class provides a generic digital filter structure that can be
//    used to implement IIR filters.  For filters containing only
//    feedforward terms, the Fir class is slightly more efficient.
//
//    In particular, this class implements the standard difference
//    equation:

//    a[0]*y[n] = b[0]*x[n] + ... + b[nb]*x[n-nb] -
//                a[1]*y[n-1] - ... - a[na]*y[n-na]

//    If a[0] is not equal to 1, the filter coeffcients are normalized
//    by a[0].

//    The \e gain parameter is applied at the filter input and does not
//    affect the coefficient values.  The default gain value is 1.0.
//    This structure results in one extra multiply per computed sample,
//    but allows easy control of the overall filter gain.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////
	
class Iir : public Filter
{
public:
	
	//! Default constructor creates a zero-order pass-through "filter".
	Iir( void );

	//! Overloaded constructor which takes filter coefficients.
	
	//An AtkError can be thrown if either of the coefficient vector
    //sizes is zero, or if the a[0] coefficient is equal to zero.
  
	Iir( std::vector<AtkFloat> &bCoefficients, std::vector<AtkFloat> &aCoefficients );

	//! Class destructor.
	~Iir( void );

	//! Set filter coefficients.
   
    //An AtkError can be thrown if either of the coefficient vector
    //sizes is zero, or if the a[0] coefficient is equal to zero.  If
    //a[0] is not equal to 1, the filter coeffcients are normalized by
    //a[0].  The internal state of the filter is not cleared unless the
    //\e clearState flag is \c true.
  
	void setCoefficients( std::vector<AtkFloat> &bCoefficients, std::vector<AtkFloat> &aCoefficients, bool clearState = false );

	//! Set numerator coefficients.
  
    //An AtkError can be thrown if coefficient vector is empty.  Any
    //previously set denominator coefficients are left unaffected.  Note
    //that the default constructor sets the single denominator
    //coefficient a[0] to 1.0.  The internal state of the filter is not
    //cleared unless the \e clearState flag is \c true.
  
	void setNumerator( std::vector<AtkFloat> &bCoefficients, bool clearState = false );

	//! Set denominator coefficients.
   
    //An AtkError can be thrown if the coefficient vector is empty or
    //if the a[0] coefficient is equal to zero.  Previously set
    //numerator coefficients are unaffected unless a[0] is not equal to
    //1, in which case all coeffcients are normalized by a[0].  Note
    //that the default constructor sets the single numerator coefficient
    //b[0] to 1.0.  The internal state of the filter is not cleared
    //unless the \e clearState flag is \c true.
  
	void setDenominator( std::vector<AtkFloat> &aCoefficients, bool clearState = false );

    //! Return the last computed output value.
	AtkFloat lastOut( void ) const { return m_lastValue; };

	//! Input one sample to the filter and return one output.
	AtkFloat tick( AtkFloat input );

protected:

};

inline AtkFloat Iir :: tick( AtkFloat input )
{
	unsigned int i;

	m_outputs[0] = 0.0;
	m_inputs[0] = m_gain * input;
	for ( i=m_b.size()-1; i>0; i-- ) 
	{
		m_outputs[0] += m_b[i] * m_inputs[i];
		m_inputs[i] = m_inputs[i-1];
	}
	m_outputs[0] += m_b[0] * m_inputs[0];

	for ( i=m_a.size()-1; i>0; i-- ) 
	{
		m_outputs[0] += -m_a[i] * m_outputs[i];
		m_outputs[i] = m_outputs[i-1];
	}

	m_lastValue = m_outputs[0];
	return m_lastValue;
}

} // atk namespace

#endif
*/