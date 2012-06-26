//----------------------------------------------------------------------------
//  \class SimpleCalibrate
//  \brief implementation of scale and bias offset calibration
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		


#include "atk_simpleCalibrate.h"

namespace atk {
	
	
	
	//Constructor
	SimpleCalibrate::SimpleCalibrate(AtkFloat maxTime)
	{
		reset();
		m_maxTime = maxTime; //one second
	}
	
	//Destructor
	SimpleCalibrate::~SimpleCalibrate()
	{
		
	}
	
	void SimpleCalibrate :: reset (void)
	{
		m_isDone = false;
		m_timer  = 0; 
		m_xBias = 0;
		m_yBias = 0; 
		m_zBias = 0;
		m_xScale = 1;
		m_yScale = 1;
		m_zScale = 1;
	}
	
	// Measure the bias values for x, y, z and store them internally
	// TODO don't start right away to give time for the phone to settle down
	bool SimpleCalibrate:: tick(const AtkFloat & x, const AtkFloat & y, const AtkFloat & z )
	{
		static AtkFloat fs = sampleRate();
		static AtkFloat timeInc = 1/fs;
		
		m_xBias += x;
		m_yBias += y;
		m_zBias += z;
		
		//Increment the timer
		m_timer += timeInc;

		if(m_timer > m_maxTime)
		{
			m_xBias /= (m_maxTime*fs);
			m_yBias /= (m_maxTime*fs);
			m_zBias /= (m_maxTime*fs);
			m_zBias = m_zBias + 1.0;
			
			m_isDone = true;
		}
	 		
		return m_isDone;
		
	}
	
	void SimpleCalibrate :: getBias(AtkFloat & x, AtkFloat & y, AtkFloat & z)
	{
		x = m_xBias;
		y = m_yBias;
		z = m_zBias;
	}
	
	bool SimpleCalibrate :: isDone()
	{
		return m_isDone;
	}
	
	


	
	
	
	
}