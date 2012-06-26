//----------------------------------------------------------------------------
//  \class TapDetector
//  \brief Detects a tap based on a high passed energy signal  
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		



#ifndef ATK_TAPDETECTOR_H
#define ATK_TAPDETECTOR_H

#import "atk_filter.h"
#import "atk_twoZero.h"
#import <math.h>

namespace atk {
	
	//TODO make better
	//TODO figure out way it detects a tap at start up
	
	
class TapDetector : public Filter
{
			
	public:
		
		//! The default constructor
		TapDetector( AtkFloat threshold = .450 );
		
		//! Class destructor.
		~TapDetector();
		
		//Set the threshold
		void setThreshold(AtkFloat threshold);
		
		//Get the threshold
		AtkFloat getThreshold();
		
		//! Input one sample to the filter and return one output.
		inline bool tick( const AtkFloat & x, const AtkFloat & y, const AtkFloat & z);
		
	private:
		
		AtkFloat m_threshold;
		TwoZero m_highPass;
		bool m_tapState;
		
};
	
inline bool TapDetector :: tick( const AtkFloat & x, const AtkFloat & y, const AtkFloat & z)
{

	static bool isTimerOff = true, isTimerOff_z1 = true;
	static const AtkFloat maxTime = .1;
	static const AtkFloat inc = 1 / sampleRate();
	static AtkFloat timer = 0;
	
	//High pass filter/corelate the signal is [1 -1] b all together
	double xHighPass, yHighPass, zHighPass;
	
	m_highPass.tick(x, y, z, xHighPass, yHighPass, zHighPass);
	
	//Compute the detecting signal (totalEnergy of the highpassed signal)
	double totalEnergy = zHighPass*zHighPass + xHighPass*xHighPass + yHighPass*yHighPass;
	
	if(totalEnergy > m_threshold )
	{
		if(isTimerOff)
		{
			isTimerOff = false;
			timer = 0;
		}
	}
	
	//TODO Clean the timer logic up
	
	//If timer is on, increment the count
	if(!isTimerOff)
		timer += inc;
	
	//Turn the timer off if maxCount is reached
	if(timer > maxTime)
		isTimerOff = true;
	 
		
	//detect the off -> on state of the timer
	if( (isTimerOff_z1 == true) && (isTimerOff == false) )
		m_tapState = true;
	else
		m_tapState = false;
	
	//Update the timer 
	isTimerOff_z1 = isTimerOff;
 	
	
	//TODO
	return m_tapState;
}
	
	
}

#endif