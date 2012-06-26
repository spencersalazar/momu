//----------------------------------------------------------------------------
//  \class Tilt
//  \brief Computes the tilt (pitch and roll)
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		


#import "atk_tilt.h"

namespace atk {


	//Constructor
	Tilt :: Tilt()
	{
		m_pitch = 0; 
		m_roll = 0;
	}
	
	
	//Destructor
	Tilt :: ~Tilt()    
	{
	
	}


}