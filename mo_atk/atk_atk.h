//----------------------------------------------------------------------------
//  \class Atk
//    \brief ATK base class
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//----------------------------------------------------------------------------		
//	General filtering including biquad, filter, fir, iir, 
//	onepole, onezero, polezero, twopole, and twozero
//	come from the STK (Synthesis ToolKit)
//	http://ccrma.stanford.edu/software/stk/
//
//----------------------------------------------------------------------------


#ifndef ATK_ATK_H
#define ATK_ATK_H

#import <string.h>
#import <sstream>
#import <vector>
#import <stdlib.h>
#import "atk_def.h"

using namespace std;

namespace atk {

//----------------------------------------------------------------------------
//  \class Atk
//    \brief ATK base class
// 
//	ATK (Accelerometer ToolKit) 
//	authors: Nicholas J. Bryan
//
//		
//	General filtering including biquad, filter, fir, iir, 
//	onepole, onezero, polezero, twopole, and twozero
//	come from the STK (Synthesis ToolKit)
//	http://ccrma.stanford.edu/software/stk/
//
//----------------------------------------------------------------------------

//#define _ATK_DEBUG_

//! ATK error handling class.
/*!
  This is a fairly abstract exception handling class.  There could
  be sub-classes to take care of more specific error conditions ... or
  not.
*/
class AtkError
{
public:
	
	enum Type { STATUS, WARNING, DEBUG_WARNING, MEMORY_ALLOCATION, MEMORY_ACCESS, FUNCTION_ARGUMENT, UNSPECIFIED};

protected:
	
	std::string message_;
	Type type_;

public:
	//! The constructor.
	AtkError(const std::string& message, Type type = AtkError::UNSPECIFIED): message_(message), type_(type) {}

	//! The destructor.
	virtual ~AtkError(void) {};

	//! Prints thrown error message to stderr.
	virtual void printMessage(void) { NSLog(@"\n %@ \n\n", [NSString stringWithUTF8String: message_.c_str()] ); }

	//! Returns the thrown error message type.
	virtual const Type& getType(void) { return type_; }

	//! Returns the thrown error message string.
	virtual const std::string& getMessage(void) { return message_; }

};


class Atk
{
public:

	typedef unsigned long AtkFormat;
	static const AtkFormat ATK_SINT8;   /*!< -128 to +127 */
	static const AtkFormat ATK_SINT16;  /*!< -32768 to +32767 */
	static const AtkFormat ATK_SINT24;  /*!< Upper 3 bytes of 32-bit signed integer. */
	static const AtkFormat ATK_SINT32;  /*!< -2147483648 to +2147483647. */
	static const AtkFormat ATK_FLOAT32; /*!< Normalized between plus/minus 1.0. */
	static const AtkFormat ATK_FLOAT64; /*!< Normalized between plus/minus 1.0. */

	//! Static method that returns the current ATK sample rate.
	static AtkFloat sampleRate( void ) { return m_srate; }

	//! Static method that sets the ATK sample rate.
	/*!
    The sample rate set using this method is queried by all ATK
    classes that depend on its value.  It is initialized to the
    default SRATE set in Atk.h.  Many ATK classes use the sample rate
    during instantiation.  Therefore, if you wish to use a rate that
    is different from the default rate, it is imperative that it be
    set \e BEFORE ATK objects are instantiated.  A few classes that
    make use of the global ATK sample rate are automatically notified
    when the rate changes so that internal class data can be
    appropriately updated.  However, this has not been fully
    implemented.  Specifically, classes that appropriately update
    their own data when either a setFrequency() or noteOn() function
    is called do not currently receive the automatic notification of
    rate change.  If the user wants a specific class instance to
    ignore such notifications, perhaps in a multi-rate context, the
    function Atk::ignoreSampleRateChange() should be called.
	 */
	static void setSampleRate( AtkFloat rate );

	//! A function to enable/disable the automatic updating of class data when the ATK sample rate changes.
	/*!
	This function allows the user to enable or disable class data
    updates in response to global sample rate changes on a class by
    class basis.
	 */
	void ignoreSampleRateChange( bool ignore = true ) { m_ignoreSampleRateChange = ignore; };

	//! Static method that byte-swaps a 16-bit data type.
	static void swap16( unsigned char *ptr );

	//! Static method that byte-swaps a 32-bit data type.
	static void swap32( unsigned char *ptr );

	//! Static method that byte-swaps a 64-bit data type.
	static void swap64( unsigned char *ptr );

	//! Static function for error reporting and handling using c-strings.
	static void handleError( const char *message, AtkError::Type type );

	//! Static function for error reporting and handling using c++ strings.
	static void handleError( std::string message, AtkError::Type type );

	//! Toggle display of WARNING and STATUS messages.
	static void showWarnings( bool status ) { m_showWarnings = status; }

	//! Toggle display of error messages before throwing exceptions.
	static void printErrors( bool status ) { m_printErrors = status; }

private:
	static AtkFloat m_srate;
	static bool m_showWarnings;
	static bool m_printErrors;
	static std::vector<Atk *> m_alertList;

protected:

	std::ostringstream m_errorString;
	bool m_ignoreSampleRateChange;

	//! Default constructor.
	Atk( void );

	//! Class destructor.
	virtual ~Atk( void );

	//! This function should be implemented in subclasses that depend on the sample rate.
	virtual void sampleRateChanged( AtkFloat newRate, AtkFloat oldRate );

	//! Add class pointer to list for sample rate change notification.
	void addSampleRateAlert( Atk *ptr );

	//! Remove class pointer from list for sample rate change notification.
	void removeSampleRateAlert( Atk *ptr );

	//! Internal function for error reporting that assumes message in \c m_errorString variable.
	void handleError( AtkError::Type type );
};

} // atk namespace

#endif
