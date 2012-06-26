//----------------------------------------------------------------------------
//  \class TapDetector
//  \brief Detects a tap based on a high passed energy signal  
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		


#include "atk_tapDetector.h"

namespace atk {
	
	//Init static variables
	
	TapDetector :: TapDetector( AtkFloat threshold  )
	{
		//Resize the 2D vectors to the correct size
		m_inputs.resize(3);
		m_outputs.resize(3);
		for(int i=0; i < m_numChannels; i++)
		{
			m_inputs[i].resize(1, 0.0);
			m_outputs[i].resize(2, 0.0);
		}
		
		//Resize the coeff vectors
		m_b.resize( 1, 1.0 );
		m_a.resize( 2, 1.0 );
		
		//Set the shake state
		m_tapState = false;
		
		//Set the threshold
		m_threshold = threshold;
		
		//set the high pass filter coefficients
		m_highPass.setCoefficients( 1.0, -2.0, 1.0, true );
		
	}
	
	//Set the threshold
	void TapDetector :: setThreshold(AtkFloat threshold)
	{
		m_threshold = threshold;
	}
	
	//Get the threshold
	AtkFloat TapDetector :: getThreshold()
	{
		return m_threshold;
	}
	
	
	TapDetector :: ~TapDetector()    
	{}
	
	
	
	
	
} // atk namespace