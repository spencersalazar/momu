//----------------------------------------------------------------------------
//  \class SimpleCalibrate
//  \brief implementation of bias offset calibration (assumes a scale factor of 1 for each axis)
//		   The class assumes the phone will be on a flat surface for the required calibration time
//		   as either set up via the constructor or default to 1 second.
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		



#ifndef ATK_CALIBRATE_H
#define ATK_CALIBRATE_H

#import "atk_atk.h"

namespace atk {

	class SimpleCalibrate : Atk
	{
	
	public:
		
		//Constructor
		SimpleCalibrate(AtkFloat time = 1.0);
		
		//Destructor
		~SimpleCalibrate();
		
		// Measure the bias values for x, y, z and store them internally
		bool tick(const AtkFloat & xBias, const AtkFloat & yBias, const AtkFloat & zBias);
		
		//Get the bias
		void getBias(AtkFloat & x, AtkFloat & y, AtkFloat & z);
		
		//Reset the calibrater
		void reset();		
		
		bool isDone();

		
	private:
		
		AtkFloat m_xBias, m_yBias, m_zBias;
		AtkFloat m_xScale, m_yScale, m_zScale;
		bool m_isDone;
		AtkFloat m_maxTime, m_timer;
		

		
	};




}



#endif