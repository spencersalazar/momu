//----------------------------------------------------------------------------
//  \class Atk
//    \brief ATK base class
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		

#import "atk_atk.h"
#import <unistd.h>

namespace atk {

AtkFloat Atk :: m_srate = (AtkFloat) 100;
const Atk::AtkFormat Atk :: ATK_SINT8   = 0x1;
const Atk::AtkFormat Atk :: ATK_SINT16  = 0x2;
const Atk::AtkFormat Atk :: ATK_SINT24  = 0x4;
const Atk::AtkFormat Atk :: ATK_SINT32  = 0x8;
const Atk::AtkFormat Atk :: ATK_FLOAT32 = 0x10;
const Atk::AtkFormat Atk :: ATK_FLOAT64 = 0x20;
bool Atk :: m_showWarnings = true;
bool Atk :: m_printErrors = true;
std::vector<Atk *> Atk :: m_alertList;

Atk :: Atk( void ) : m_ignoreSampleRateChange(false)
{}

Atk :: ~Atk( void )
{}

void Atk :: setSampleRate( AtkFloat rate )
{
	if ( rate > 0.0 && rate != m_srate ) 
	{
		AtkFloat oldRate = m_srate;
		m_srate = rate;

		for ( unsigned int i=0; i<m_alertList.size(); i++ )
			m_alertList[i]->sampleRateChanged( m_srate, oldRate );
	}
}

void Atk :: sampleRateChanged( AtkFloat newRate, AtkFloat oldRate )
{
  // This function should be reimplemented in classes that need to
  // make internal variable adjustments in response to a global sample
  // rate change.
}

void Atk :: addSampleRateAlert( Atk *ptr )
{
	for ( unsigned int i=0; i<m_alertList.size(); i++ )
		if ( m_alertList[i] == ptr ) return;

	m_alertList.push_back( ptr );
}

void Atk :: removeSampleRateAlert( Atk *ptr )
{
	for ( unsigned int i=0; i<m_alertList.size(); i++ ) 
	{
		if ( m_alertList[i] == ptr )
		{
			m_alertList.erase( m_alertList.begin() + i );
			return;
		}
	}
}


void Atk :: swap16(unsigned char *ptr)
{
	register unsigned char val;

	// Swap 1st and 2nd bytes
	val = *(ptr);
	*(ptr) = *(ptr+1);
	*(ptr+1) = val;
}

void Atk :: swap32(unsigned char *ptr)
{
	register unsigned char val;

	// Swap 1st and 4th bytes
	val = *(ptr);
	*(ptr) = *(ptr+3);
	*(ptr+3) = val;

	//Swap 2nd and 3rd bytes
	ptr += 1;
	val = *(ptr);
	*(ptr) = *(ptr+1);
	*(ptr+1) = val;
}

void Atk :: swap64(unsigned char *ptr)
{
	register unsigned char val;

	// Swap 1st and 8th bytes
	val = *(ptr);
	*(ptr) = *(ptr+7);
	*(ptr+7) = val;

	// Swap 2nd and 7th bytes
	ptr += 1;
	val = *(ptr);
	*(ptr) = *(ptr+5);
	*(ptr+5) = val;

	// Swap 3rd and 6th bytes
	ptr += 1;
	val = *(ptr);
	*(ptr) = *(ptr+3);
	*(ptr+3) = val;

	// Swap 4th and 5th bytes
	ptr += 1;
	val = *(ptr);
	*(ptr) = *(ptr+1);
	*(ptr+1) = val;
}



void Atk :: handleError( AtkError::Type type )
{
	handleError( m_errorString.str(), type );
	m_errorString.str( std::string() ); // reset the ostringstream buffer
}

void Atk :: handleError( const char *message, AtkError::Type type )
{
	std::string msg( message );
	handleError( msg, type );
}

void Atk :: handleError( std::string message, AtkError::Type type )
{
	if ( type == AtkError::WARNING || type == AtkError::STATUS ) 
	{
		if ( !m_showWarnings ) return;
	  
		NSLog(@"\n %@ \n\n", [NSString stringWithUTF8String: message.c_str()] );  
	}
	else if (type == AtkError::DEBUG_WARNING) 
	{
		#if defined(_ATK_DEBUG_)
			std::cerr << '\n' << message << '\n' << std::endl;
		#endif
	}
	else 
	{
		if ( m_printErrors ) 
		{
			// Print error message before throwing.
			NSLog(@"\n %@ \n\n", [NSString stringWithUTF8String: message.c_str()] );
		}
		throw AtkError(message, type);
	}
}


} // atk namespace
