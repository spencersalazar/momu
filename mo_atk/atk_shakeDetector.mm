//----------------------------------------------------------------------------
//  \class ShakeDetector
//  \brief Detects a shake based on an energy envelope  
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		



#include "atk_shakeDetector.h"

 
namespace atk {
	
	ShakeDetector :: ShakeDetector( AtkFloat threshold  )
	{
		 
		
		//Set the shake state
		m_shakeState = false;
		m_firstShake = false;
		
		//Set the threshold
		m_threshold = threshold;
		
		//set the filter coeffs using a decay rate
		energyEnvelope.setDecayRate(20.0);
		
	}
	
	//Set the threshold
	void ShakeDetector :: setThreshold(AtkFloat threshold)
	{
		m_threshold = threshold;
	}
	
	//Get the threshold
	AtkFloat ShakeDetector :: getThreshold()
	{
		return m_threshold;
	}
	
	void ShakeDetector :: setDecayRate(AtkFloat decayRate)
	{
		energyEnvelope.setDecayRate(decayRate);
	}
	
	AtkFloat ShakeDetector :: getDecayRate()
	{
		return energyEnvelope.getDecayRate();
	}
	
	ShakeDetector :: ~ShakeDetector()    
	{}

	
} // atk namespace