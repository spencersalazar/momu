/////////////////////////////////////////////////////////
// \class BiQuad
//    \brief ATK biquad (two-pole, two-zero) filter class.
//
//    This class implements a two-pole, two-zero digital filter.
//    Methods are provided for creating a resonance or notch in the
//    frequency response while maintaining a constant filter gain.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////
/*
#import "atk_biquad.h"
#import <cmath>

namespace atk {

BiQuad :: BiQuad() : Filter()
{
	m_b.resize( 3, 0.0 );
	m_a.resize( 3, 0.0 );
	m_b[0] = 1.0;
	m_a[0] = 1.0;
	
	m_inputs.resize( 3, 0.0 );
	m_outputs.resize( 3, 0.0 );

	Atk::addSampleRateAlert( this );
}

BiQuad :: ~BiQuad()
{
	Atk::removeSampleRateAlert( this );
}

void BiQuad :: setCoefficients( AtkFloat b0, AtkFloat b1, AtkFloat b2, AtkFloat a1, AtkFloat a2, bool clearState )
{
	m_b[0] = b0;
	m_b[1] = b1;
	m_b[2] = b2;
	m_a[1] = a1;
	m_a[2] = a2;

	if ( clearState ) 
		this->clear();
}

void BiQuad :: sampleRateChanged( AtkFloat newRate, AtkFloat oldRate )
{
	if ( !m_ignoreSampleRateChange ) {
		m_errorString << "BiQuad::sampleRateChanged: you may need to recompute filter coefficients!";
		handleError( AtkError::WARNING );
	}
}

void BiQuad :: setResonance(AtkFloat frequency, AtkFloat radius, bool normalize)
{
	m_a[2] = radius * radius;
	m_a[1] = -2.0 * radius * cos( ATK_TWO_PI * frequency / Atk::sampleRate() );

	if ( normalize )
	{
		// Use zeros at +- 1 and normalize the filter peak gain.
		m_b[0] = 0.5 - 0.5 * m_a[2];
		m_b[1] = 0.0;
		m_b[2] = -m_b[0];
	}
}

void BiQuad :: setNotch(AtkFloat frequency, AtkFloat radius)
{
	// This method does not attempt to normalize the filter gain.
	m_b[2] = radius * radius;
	m_b[1] = (AtkFloat) -2.0 * radius * cos( ATK_TWO_PI * (double) frequency / Atk::sampleRate() );
}

void BiQuad :: setEqualGainZeroes()
{
	m_b[0] = 1.0;
	m_b[1] = 0.0;
	m_b[2] = -1.0;
}
	
inline AtkFloat BiQuad :: tick( AtkFloat input )
{
	m_inputs[0] = m_gain * input;
	m_lastValue = m_b[0] * m_inputs[0] + m_b[1] * m_inputs[1] + m_b[2] * m_inputs[2];
	m_lastValue -= m_a[2] * m_outputs[2] + m_a[1] * m_outputs[1];
	m_inputs[2] = m_inputs[1];
	m_inputs[1] = m_inputs[0];
	m_outputs[2] = m_outputs[1];
	m_outputs[1] = m_lastValue;
		
	return m_lastValue;
}
	

} // atk namespace
*/