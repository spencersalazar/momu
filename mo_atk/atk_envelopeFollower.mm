//----------------------------------------------------------------------------
//  \class EnvelopeFollower
//  \brief Enevelope follower on each of the acceleration signals (x, y, z)
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		

#import "atk_envelopeFollower.h"

namespace atk {
	
	EnvelopeFollower :: EnvelopeFollower( AtkFloat decayRate)
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

		
		//set the filter coeffs using a decay rate
		this->setDecayRate(decayRate);
		 
	}
	
	void EnvelopeFollower :: setDecayRate(AtkFloat decayRate)
	{
		AtkFloat a1 = -pow(10, -decayRate/(20*sampleRate()));
		AtkFloat b0 = 1+a1;
		this->setCoefficients( b0, a1, true );
	}
	
	EnvelopeFollower :: ~EnvelopeFollower()    
	{}
	
	
	void EnvelopeFollower :: setCoefficients( AtkFloat b0, AtkFloat a1, bool clearState )
	{
		m_b[0] = b0;
		m_a[1] = a1;
		
		if ( clearState ) 
			this->clear();
	}
	

	
	

} // atk namespace
