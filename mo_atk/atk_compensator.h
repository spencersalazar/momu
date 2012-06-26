//----------------------------------------------------------------------------
//  \class Compensate
//  \brief implementation of scale and bias offset compensation
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		

#ifndef ATK_COMPENSATOR_H
#define ATK_COMPENSATOR_H

#import "atk_atk.h"

namespace atk {
	
	class Compensator : Atk
		{
			
		public:
			
			//Constructor
			Compensator();
			
			//Destructor
			~Compensator();
			
			// Measure the bias values for x, y, z and store them internally
			void tick( AtkFloat & x,  AtkFloat & y, AtkFloat & z);
			
			void setBiasScale(AtkFloat xBias, AtkFloat yBias, AtkFloat zBias, AtkFloat xScale, AtkFloat yScale, AtkFloat zScale);
			
			
		private:
			
			AtkFloat m_xBias, m_yBias, m_zBias;
			AtkFloat m_xScale, m_yScale, m_zScale;

		};
	
	
	
	
}



#endif