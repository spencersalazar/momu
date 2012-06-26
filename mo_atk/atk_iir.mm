/////////////////////////////////////////////////////////
// \class Iir
//    \brief ATK general infinite impulse response filter class.
//
//   This class provides a generic digital filter structure that can be
//    used to implement IIR filters.  For filters containing only
//    feedforward terms, the Fir class is slightly more efficient.

//    In particular, this class implements the standard difference
//    equation:

 //   a[0]*y[n] = b[0]*x[n] + ... + b[nb]*x[n-nb] -
 //               a[1]*y[n-1] - ... - a[na]*y[n-na]

//    If a[0] is not equal to 1, the filter coeffcients are normalized
//    by a[0].

//    The \e gain parameter is applied at the filter input and does not
//    affect the coefficient values.  The default gain value is 1.0.
//    This structure results in one extra multiply per computed sample,
//    but allows easy control of the overall filter gain.

//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////
/*
#import "atk_iir.h"

namespace atk {

Iir :: Iir()
{
	// The default constructor should setup for pass-through.
	m_b.push_back( 1.0 );
	m_a.push_back( 1.0 );

	m_inputs.resize( 1, 0.0 );
	m_outputs.resize( 1, 0.0 );
}

Iir :: Iir( std::vector<AtkFloat> &bCoefficients, std::vector<AtkFloat> &aCoefficients )
{
	// Check the arguments.
	if ( bCoefficients.size() == 0 || aCoefficients.size() == 0 ) 
	{
		m_errorString << "Iir: a and b coefficient vectors must both have size > 0!";
		handleError( AtkError::FUNCTION_ARGUMENT );
	}

	if ( aCoefficients[0] == 0.0 ) {
		m_errorString << "Iir: a[0] coefficient cannot == 0!";
		handleError( AtkError::FUNCTION_ARGUMENT );
	}

	m_gain = 1.0;
	m_b = bCoefficients;
	m_a = aCoefficients;

	m_inputs.resize( m_b.size(), 0.0 );
	m_outputs.resize( m_a.size(), 0.0 );
	this->clear();
}

Iir :: ~Iir()
{}

void Iir :: setCoefficients( std::vector<AtkFloat> &bCoefficients, std::vector<AtkFloat> &aCoefficients, bool clearState )
{
	this->setNumerator( bCoefficients, false );
	this->setDenominator( aCoefficients, false );

	if ( clearState ) 
		this->clear();
}

void Iir :: setNumerator( std::vector<AtkFloat> &bCoefficients, bool clearState )
{
	// Check the argument.
	if ( bCoefficients.size() == 0 ) 
	{
		m_errorString << "Iir::setNumerator: coefficient vector must have size > 0!";
		handleError( AtkError::FUNCTION_ARGUMENT );
	}

	if ( m_b.size() != bCoefficients.size() ) 
	{
		m_b = bCoefficients;
		m_inputs.resize( m_b.size(), 0.0 );
	}
	else 
	{
		for ( unsigned int i=0; i<m_b.size(); i++ ) m_b[i] = bCoefficients[i];
	}

	if ( clearState ) this->clear();
}

void Iir :: setDenominator( std::vector<AtkFloat> &aCoefficients, bool clearState )
{
	// Check the argument.
	if ( aCoefficients.size() == 0 )
	{
		m_errorString << "Iir::setDenominator: coefficient vector must have size > 0!";
		handleError( AtkError::FUNCTION_ARGUMENT );
	}

	if ( aCoefficients[0] == 0.0 ) 
	{
		m_errorString << "Iir::setDenominator: a[0] coefficient cannot == 0!";
		handleError( AtkError::FUNCTION_ARGUMENT );
	}

	if ( m_a.size() != aCoefficients.size() )
	{
		m_a = aCoefficients;
		m_outputs.resize( m_a.size(), 0.0 );
	}
	else 
	{
		for ( unsigned int i=0; i<m_a.size(); i++ ) m_a[i] = aCoefficients[i];
	}

	if ( clearState ) this->clear();

	// Scale coefficients by a[0] if necessary
	if ( m_a[0] != 1.0 ) 
	{
		unsigned int i;
		for ( i=0; i<m_b.size(); i++ ) m_b[i] /= m_a[0];
		for ( i=1; i<m_a.size(); i++ )  m_a[i] /= m_a[0];
	}
}

} // atk namespace
*/