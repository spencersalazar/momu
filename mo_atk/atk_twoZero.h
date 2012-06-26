/***************************************************/
/*! \class TwoZero
 \brief ATK two-zero filter class.
 
 This class implements a two-zero digital filter.  A method is
 provided for creating a "notch" in the frequency response while
 maintaining a constant filter gain.
 
 by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
 */
/***************************************************/

#ifndef ATK_TWOZERO_H
#define ATK_TWOZERO_H

#import "atk_filter.h"

namespace atk {

class TwoZero : public Filter
{
 public:
	//! Default constructor creates a second-order pass-through filter.
	TwoZero();

	//! Class destructor.
	~TwoZero();

	//! A function to enable/disable the automatic updating of class data when the ATK sample rate changes.
	void ignoreSampleRateChange( bool ignore = true ) { m_ignoreSampleRateChange = ignore; };

	//! Set the b[0] coefficient value.
	void setB0( AtkFloat b0 ) { m_b[0] = b0; };

	//! Set the b[1] coefficient value.
	void setB1( AtkFloat b1 ) { m_b[1] = b1; };

	//! Set the b[2] coefficient value.
	void setB2( AtkFloat b2 ) { m_b[2] = b2; };

	//! Set all filter coefficients.
	void setCoefficients( AtkFloat b0, AtkFloat b1, AtkFloat b2, bool clearState = false );

	//! Input one sample to the filter and return one output.
	inline void tick( AtkFloat & x, AtkFloat & y, AtkFloat & z );
	inline void tick(const  AtkFloat & xin, const  AtkFloat & yin, const AtkFloat & zin, AtkFloat & xout, AtkFloat & yout, AtkFloat & zout );


protected:
	
	void sampleRateChanged( AtkFloat newRate, AtkFloat oldRate );

};

inline void TwoZero :: tick( AtkFloat & x, AtkFloat & y, AtkFloat & z )
{
	//Temporary fix, figure out a better way to pass the x,y,z values in and out.
	m_inputs[0][0] = x;
	m_inputs[1][0] = y;
	m_inputs[2][0] = z;
	
	// Processing loop
	for(int i=0; i < m_numChannels; i++)
	{
		m_inputs[i][0]  = m_gain * m_inputs[i][0];
		m_outputs[i][0] = m_b[2] * m_inputs[i][2] + m_b[1] * m_inputs[i][1] + m_b[0] * m_inputs[i][0];
		m_inputs[i][2]  = m_inputs[i][1];
		m_inputs[i][1]  = m_inputs[i][0];
	}
		
	x = m_outputs[0][0];
	y = m_outputs[1][0];
	z = m_outputs[2][0];
		
}
	
inline void TwoZero :: tick(const  AtkFloat & xin, const  AtkFloat & yin, const AtkFloat & zin, AtkFloat & xout, AtkFloat & yout, AtkFloat & zout )
{
	//Temporary fix, figure out a better way to pass the x,y,z values in and out.
	m_inputs[0][0] = xin;
	m_inputs[1][0] = yin;
	m_inputs[2][0] = zin;
	
	// Processing loop
	for(int i=0; i < m_numChannels; i++)
	{
		m_inputs[i][0]  = m_gain * m_inputs[i][0];
		m_outputs[i][0] = m_b[2] * m_inputs[i][2] + m_b[1] * m_inputs[i][1] + m_b[0] * m_inputs[i][0];
		m_inputs[i][2] = m_inputs[i][1];
		m_inputs[i][1] = m_inputs[i][0];
	}
	
	xout = m_outputs[0][0];
	yout = m_outputs[1][0];
	zout = m_outputs[2][0];
	
}

	
} // atk namespace

#endif
