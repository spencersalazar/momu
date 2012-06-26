/*#ifndef ATK_BIQUAD_H
#define ATK_BIQUAD_H

#import "atk_filter.h"

namespace atk {

/////////////////////////////////////////////////////////
//! \class BiQuad
//    \brief ATK biquad (two-pole, two-zero) filter class.
//
//    This class implements a two-pole, two-zero digital filter.
//    Methods are provided for creating a resonance or notch in the
//    frequency response while maintaining a constant filter gain.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////

class BiQuad : public Filter
{
public:

	//! Default constructor creates a second-order pass-through filter.
	BiQuad();

	//! Class destructor.
	~BiQuad();

	//! A function to enable/disable the automatic updating of class data when the ATK sample rate changes.
	void ignoreSampleRateChange( bool ignore = true ) { m_ignoreSampleRateChange = ignore; };

	//! Set all filter coefficients.
	void setCoefficients( AtkFloat b0, AtkFloat b1, AtkFloat b2, AtkFloat a1, AtkFloat a2, bool clearState = false );

	//! Set the b[0] coefficient value.
	void setB0( AtkFloat b0 ) { m_b[0] = b0; };

	//! Set the b[1] coefficient value.
	void setB1( AtkFloat b1 ) { m_b[1] = b1; };

	//! Set the b[2] coefficient value.
	void setB2( AtkFloat b2 ) { m_b[2] = b2; };

	//! Set the a[1] coefficient value.
	void setA1( AtkFloat a1 ) { m_a[1] = a1; };

	//! Set the a[2] coefficient value.
	void setA2( AtkFloat a2 ) { m_a[2] = a2; };

	//! Sets the filter coefficients for a resonance at \e frequency (in Hz).
   
    //This method determines the filter coefficients corresponding to
    //two complex-conjugate poles with the given \e frequency (in Hz)
    //and \e radius from the z-plane origin.  If \e normalize is true,
    //the filter zeros are placed at z = 1, z = -1, and the coefficients
    //are then normalized to produce a constant unity peak gain
    //(independent of the filter \e gain parameter).  The resulting
    //filter frequency response has a resonance at the given \e
    //frequency.  The closer the poles are to the unit-circle (\e radius
    //close to one), the narrower the resulting resonance width.
  
	void setResonance( AtkFloat frequency, AtkFloat radius, bool normalize = false );

	//! Set the filter coefficients for a notch at \e frequency (in Hz).
   
    //This method determines the filter coefficients corresponding to
    //two complex-conjugate zeros with the given \e frequency (in Hz)
    //and \e radius from the z-plane origin.  No filter normalization
    //is attempted.
  
	void setNotch( AtkFloat frequency, AtkFloat radius );

	//! Sets the filter zeroes for equal resonance gain.
  
    //When using the filter as a resonator, zeroes places at z = 1, z
    //= -1 will result in a constant gain at resonance of 1 / (1 - R),
    //where R is the pole radius setting.

  
	void setEqualGainZeroes( void );

	//! Return the last computed output value.
	AtkFloat lastOut( void ) const { return m_lastValue; };

	//! Input one sample to the filter and return a reference to one output.
	AtkFloat tick( AtkFloat input );

 protected:

	virtual void sampleRateChanged( AtkFloat newRate, AtkFloat oldRate );

};



} // atk namespace

#endif
*/
