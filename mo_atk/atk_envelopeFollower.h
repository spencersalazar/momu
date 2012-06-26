//----------------------------------------------------------------------------
//  \class EnvelopeFollower
//  \brief Enevelope follower on each of the acceleration signals (x, y, z)
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		



#ifndef ATK_ENVELOPEFOLLOWER_H
#define ATK_ENVELOPEFOLLOWER_H

#import "atk_filter.h"
#import <math.h>

namespace atk {
	
	
class EnvelopeFollower : public Filter
{
			
	public:
			
		//! The default constructor
		//EnvelopeFollower(void);
	
		// Overloaded Constructor
		EnvelopeFollower( AtkFloat decayRate = 60.0 );
			
		//! Class destructor.
		~EnvelopeFollower();
		
		//Set the decay rate of the follower in dB
		void setDecayRate(AtkFloat decayRate);
		
		//! Input one sample to the filter and return one output.
		inline void tick(  AtkFloat & x,  AtkFloat & y,  AtkFloat & z);
		inline void tick( const AtkFloat & xin, const AtkFloat & yin,  const AtkFloat & zin, AtkFloat & xout,  AtkFloat & yout,  AtkFloat & zout);
			
	private:
			
		AtkFloat m_decayRate;
			
		//! Set all filter coefficients.
		void setCoefficients( AtkFloat b0, AtkFloat a1, bool clearState = false );
		
};
	
	inline void EnvelopeFollower :: tick(  AtkFloat & x,  AtkFloat & y,  AtkFloat & z)
	{
		//Temporary fix, figure out a better way to pass the x,y,z values in and out.
		m_inputs[0][0] = x;
		m_inputs[1][0] = y;
		m_inputs[2][0] = z;
		
		// Processing loop
		for(int i=0; i < m_numChannels; i++)
		{
			m_inputs[i][0]  = m_gain * m_inputs[i][0];
			m_outputs[i][0] = m_b[0] * m_inputs[i][0] - m_a[1] * m_outputs[i][1];
			m_outputs[i][1] = m_outputs[i][0];
		}
		
		x = m_outputs[0][0];
		y = m_outputs[1][0];
		z = m_outputs[2][0];
		
}
	
	
	inline void EnvelopeFollower :: tick( const AtkFloat & xin, const AtkFloat & yin,  const AtkFloat & zin, AtkFloat & xout,  AtkFloat & yout,  AtkFloat & zout)
	{
		//Temporary fix, figure out a better way to pass the x,y,z values in and out.
		m_inputs[0][0] = xin;
		m_inputs[1][0] = yin;
		m_inputs[2][0] = zin;
		
		// Processing loop
		for(int i=0; i < m_numChannels; i++)
		{
			m_inputs[i][0]  = m_gain * m_inputs[i][0];
			m_outputs[i][0] = m_b[0] * m_inputs[i][0] - m_a[1] * m_outputs[i][1];
			m_outputs[i][1] = m_outputs[i][0];
		}
		
		xout = m_outputs[0][0];
		yout = m_outputs[1][0];
		zout = m_outputs[2][0];
}
	
	

} // atk namespace

#endif
