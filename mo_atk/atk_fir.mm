/////////////////////////////////////////////////////////
//! \class Fir
//    \brief ATK general finite impulse response filter class.
//
//    This class provides a generic digital filter structure that can be
//    used to implement FIR filters.  For filters with feedback terms,
//    the Iir class should be used.
//
//    In particular, this class implements the standard difference
//    equation:
//
//    y[n] = b[0]*x[n] + ... + b[nb]*x[n-nb]
//
//    The \e gain parameter is applied at the filter input and does not
//    affect the coefficient values.  The default gain value is 1.0.
//    This structure results in one extra multiply per computed sample,
//    but allows easy control of the overall filter gain.
//
//    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
//
/////////////////////////////////////////////////////////
/*
#import "atk_fir.h"

namespace atk {

Fir :: Fir()
{
	// The default constructor should setup for pass-through.
	m_b.push_back( 1.0 );

	m_inputs.resize( 1, 0.0 );
}

Fir :: Fir( std::vector<AtkFloat> &coefficients )
{
	// Check the arguments.
	if ( coefficients.size() == 0 ) 
	{
		m_errorString << "Fir: coefficient vector must have size > 0!";
		handleError( AtkError::FUNCTION_ARGUMENT );
	}

	m_gain = 1.0;
	m_b = coefficients;

	m_inputs.resize( m_b.size(), 0.0 );
	this->clear();
}

Fir :: ~Fir()
{}

void Fir :: setCoefficients( std::vector<AtkFloat> &coefficients, bool clearState )
{
	// Check the argument.
	if ( coefficients.size() == 0 ) 
	{
		m_errorString << "Fir::setCoefficients: coefficient vector must have size > 0!";
		handleError( AtkError::FUNCTION_ARGUMENT );
	}

  if ( m_b.size() != coefficients.size() ) 
  {
	  m_b = coefficients;
	  m_inputs.resize( m_b.size(), 0.0 );
  }
  else 
  {
	  for ( unsigned int i=0; i<m_b.size(); i++ ) m_b[i] = coefficients[i];
  }

  if ( clearState ) 
	  this->clear();
}

} // atk namespace
*/