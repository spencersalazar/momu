#ifndef ATK_TWOPOLE_H
#define ATK_TWOPOLE_H

#import "atk_filter.h"

namespace atk {

/***************************************************/
/*! \class TwoPole
    \brief ATK two-pole filter class.

    This class implements a two-pole digital filter.  A method is
    provided for creating a resonance in the frequency response while
    maintaining a nearly constant filter gain.

    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
*/
/***************************************************/

class TwoPole : public Filter
{

public:

	//! Default constructor creates a second-order pass-through filter.
	TwoPole( void );

	//! Class destructor.
	~TwoPole();

	//! A function to enable/disable the automatic updating of class data when the ATK sample rate changes.
	void ignoreSampleRateChange( bool ignore = true ) { m_ignoreSampleRateChange = ignore; };

	//! Set the b[0] coefficient value.
	void setB0( AtkFloat b0 ) { m_b[0] = b0; };

	//! Set the a[1] coefficient value.
	void setA1( AtkFloat a1 ) { m_a[1] = a1; };

	//! Set the a[2] coefficient value.
	void setA2( AtkFloat a2 ) { m_a[2] = a2; };

	//! Set all filter coefficients.
	void setCoefficients( AtkFloat b0, AtkFloat a1, AtkFloat a2, bool clearState = false );

	//! Sets the filter coefficients for a resonance at \e frequency (in Hz).
	 
    //This method determines the filter coefficients corresponding to
	//two complex-conjugate poles with the given \e frequency (in Hz)
    //and \e radius from the z-plane origin.  If \e normalize is true,
    //the coefficients are then normalized to produce unity gain at \e
    //frequency (the actual maximum filter gain tends to be slightly
    //greater than unity when \e radius is not close to one).  The
    //resulting filter frequency response has a resonance at the given
    //\e frequency.  The closer the poles are to the unit-circle (\e
    //radius close to one), the narrower the resulting resonance width.
    //An unstable filter will result for \e radius >= 1.0.  For a better
    //resonance filter, use a BiQuad filter. \sa BiQuad filter class
  
	void setResonance(AtkFloat frequency, AtkFloat radius, bool normalize = false);

	//! Return the last computed output value.
	AtkFloat lastOut( void ) const { return m_lastValue; };

	//! Input one sample to the filter and return one output.
	AtkFloat tick( AtkFloat input );

 protected:

	virtual void sampleRateChanged( AtkFloat newRate, AtkFloat oldRate );

};

inline AtkFloat TwoPole :: tick( AtkFloat input )
{
	m_inputs[0] = m_gain * input;
	m_lastValue = m_b[0] * m_inputs[0] - m_a[1] * m_outputs[1] - m_a[2] * m_outputs[2];
	m_outputs[2] = m_outputs[1];
	m_outputs[1] = m_lastValue;

	return m_lastValue;
}


} // atk namespace

#endif
