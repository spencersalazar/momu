//----------------------------------------------------------------------------
//  \class Compensate
//  \brief implementation of scale and bias offset compensation
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		



#include "atk_compensator.h"

namespace atk {
	
	
	
	//Constructor
	Compensator::Compensator()
	{
		m_xBias = 0.0;
		m_yBias = 0.0;
		m_zBias = 0.0;
		m_xScale = 1.0;
		m_yScale = 1.0;
		m_zScale = 1.0;
	}
	
	//Destructor
	Compensator::~Compensator()
	{
		
	}
	
	void Compensator :: setBiasScale(AtkFloat xBias, AtkFloat yBias, AtkFloat zBias, AtkFloat xScale, AtkFloat yScale, AtkFloat zScale)
	{
		m_xBias = xBias;
		m_yBias = yBias;
		m_zBias = zBias;
		m_xScale = xScale;
		m_yScale = yScale;
		m_zScale = zScale;
	}
	
	
	// Measure the bias values for x, y, z and store them internally
	// TODO don't start right away to give time for the phone to settle down
	void Compensator:: tick( AtkFloat & x,  AtkFloat & y, AtkFloat & z )
	{
		x = (x - m_xBias)/m_xScale;	
		y = (y - m_yBias)/m_yScale;	
		z = (z - m_xBias)/m_zScale;	
	}
		
	
	
	
	
	
	
}