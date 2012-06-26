//----------------------------------------------------------------------------
//  \class Tilt
//  \brief Computes the tilt (pitch and roll)
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		



#ifndef ATK_TILT_H
#define ATK_TILT_H

#import "atk_atk.h"
#import <math.h>

namespace atk {
	
class Tilt : public Atk
{

public:
	
	//Constructor
	Tilt();
	
	//Destructor
	~Tilt();
	
	//Get the pitch angle
	//AtkFloat getPitch();
	
	//Get the roll angle
	//AtkFloat getRoll();
	
	//Get both pitch and roll inline
	inline void tick(AtkFloat x, AtkFloat y, AtkFloat z, AtkFloat & pitch, AtkFloat & roll);
	
private:
	
	AtkFloat m_pitch;
	AtkFloat m_roll;
	
};
	
	
inline void Tilt :: tick(AtkFloat x, AtkFloat y, AtkFloat z, AtkFloat & pitch, AtkFloat & roll)
{
	
	//Make a unit norm vector
	float invmag = 1/sqrt(x*x + y*y + z*z);
	x = x*invmag; y = y*invmag; z = z*invmag;
	
	roll =  180*atan2(x, sqrt(y*y + z*z))/ATK_PI;
	pitch = -180*atan2(y, sqrt(x*x + z*z))/ATK_PI;
	
	m_pitch = pitch;
	m_roll = roll;
	
}

}


#endif