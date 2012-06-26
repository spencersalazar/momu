//----------------------------------------------------------------------------
//  \class EnergyEnvelope
//  \brief Enevelope follower on the total energy of the accelerometer signal
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		





#ifndef ATK_ENERGYENVELOPE_H
#define ATK_ENERGYENVELOPE_H

#import "atk_filter.h"
#import <math.h>

namespace atk {
	
	
	class EnergyEnvelope : public Filter
		{
			
		public:
			
			//! The default constructor
			EnergyEnvelope( AtkFloat decayRate = 60.0 );
			
			//! Class destructor.
			~EnergyEnvelope();

			void setDecayRate(AtkFloat decayRate);
			
			AtkFloat getDecayRate();
			
			//! Input one sample to the filter and return one output.
			inline AtkFloat tick( const AtkFloat & x, const AtkFloat & y, const AtkFloat & z );
			
		private:
			
			AtkFloat m_decayRate;
			
			//! Set all filter coefficients.
			void setCoefficients( AtkFloat b0, AtkFloat a1, bool clearState = false );
		
		};
	
	
	inline AtkFloat EnergyEnvelope :: tick( const AtkFloat & x, const AtkFloat & y, const AtkFloat & z)
	{
		//Put energy in the first channel
		m_inputs[0][0] = x*x + y*y + z*z;
		
		// Processing loop
		m_inputs[0][0]  = m_gain * m_inputs[0][0];
		m_outputs[0][0] = m_b[0] * m_inputs[0][0] - m_a[1] * m_outputs[0][1];
		m_outputs[0][1] = m_outputs[0][0];
		
		return m_outputs[0][0];
	}
	
	
	
} // atk namespace

#endif
