//----------------------------------------------------------------------------
//  \class ShakeDetector
//  \brief Detects a shake based on an energy envelope  
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		

#ifndef ATK_SHAKEDETECTOR_H
#define ATK_SHAKEDETECTOR_H

#import "atk_filter.h"
#import "atk_energyEnvelope.h"
#import <math.h>

namespace atk {
	
	
class ShakeDetector : public Atk
{
		
	public:
		
		//! The default constructor
		ShakeDetector( AtkFloat threshold = 5.0 );
			
		//! Class destructor.
		~ShakeDetector();
			
		//Set the threshold
		void setThreshold(AtkFloat threshold);
			
		//Get the threshold
		AtkFloat getThreshold();
	
		//Set the decay rate of the follower in dB
		void setDecayRate(AtkFloat decayRate);
	
		AtkFloat getDecayRate();
			
		//! Input one sample to the filter and return one output.
		inline void tick( const AtkFloat & x, const AtkFloat & y, const AtkFloat & z, bool & shakeState, bool & firstShake );
			
	private:
			
		bool m_shakeState;
		bool m_firstShake;
		AtkFloat m_threshold;
		EnergyEnvelope energyEnvelope;
	
		
		//! Set all filter coefficients.
		void setCoefficients( AtkFloat b0, AtkFloat a1, bool clearState = false );
			

			
	};
	
	
inline void ShakeDetector :: tick( const AtkFloat & x, const AtkFloat & y, const AtkFloat & z, bool & shakeState, bool & firstShake )
{

	double energy = energyEnvelope.tick(x, y, z);
	
	//Determine the shake state
	if(energy > m_threshold)
	{
		if(m_firstShake==false)
			m_firstShake = true;
		
		m_shakeState = true;
	
	}
	else
	{
		m_shakeState = false;
		m_firstShake = false;
	}
		
	shakeState = m_shakeState;
	firstShake = m_firstShake;
}
	
	
	
} // atk namespace

#endif
