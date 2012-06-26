//----------------------------------------------------------------------------
//  \class EnergyEnvelope
//  \brief Enevelope follower on the total energy of the accelerometer signal
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		



#include "atk_energyEnvelope.h"


namespace atk {
	
	//Init static variables
	
	EnergyEnvelope :: EnergyEnvelope( AtkFloat decayRate  )
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
		
		m_decayRate = decayRate;
		
		//set the filter coeffs using a decay rate
		this->setDecayRate(m_decayRate);
		
	}
	
	AtkFloat EnergyEnvelope :: getDecayRate()
	{
		return m_decayRate;
	}
	
	void EnergyEnvelope :: setDecayRate(AtkFloat decayRate)
	{
		AtkFloat a1 = -pow(10, -decayRate/(20*sampleRate()));
		AtkFloat b0 = 1+a1;
		this->setCoefficients( b0, a1, true );
	}
	
	EnergyEnvelope :: ~EnergyEnvelope()    
	{}
	
	
	void EnergyEnvelope :: setCoefficients( AtkFloat b0, AtkFloat a1, bool clearState )
	{
		m_b[0] = b0;
		m_a[1] = a1;
		
		if ( clearState ) 
			this->clear();
	}
	
	
	
} // atk namespace