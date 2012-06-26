#ifndef ATK_FILTER_H
#define ATK_FILTER_H

#import "atk_atk.h"
#import <vector>

namespace atk {

/***************************************************/
/*! \class Filter
    \brief ATK abstract filter class.

    This class provides limited common functionality for ATK digital
    filter subclasses.  It is general enough to support both
    monophonic and polyphonic input/output classes.

    by Perry R. Cook and Gary P. Scavone, 1995 - 2009.
*/
/***************************************************/

class Filter : public Atk
{

public:
	//! Class constructor.
	Filter( void )
	{ m_gain = 1.0; };

	//! Return the number of input channels for the class.
	unsigned int numChannels( void ) const { return m_numChannels; };

	//! Clears all internal states of the filter.
	virtual void clear( void );

	//! Set the filter gain.
    //The gain is applied at the filter input and does not affect the
    //coefficient values.  The default gain value is 1.0.
	void setGain( AtkFloat gain ) { m_gain = gain; };

	//! Return the current filter gain.
	AtkFloat getGain( void ) const { return m_gain; };

protected:
	
	//2D vectors of the inputs and outputs
	std::vector< std::vector< AtkFloat > > m_outputs;
	std::vector< std::vector< AtkFloat > > m_inputs;

	AtkFloat m_gain;
	std::vector< AtkFloat > m_b;
	std::vector< AtkFloat > m_a;

	static const unsigned int m_numChannels = 3.0;

};

inline void Filter :: clear( void )
{
	for(int i=0; i < m_numChannels; i++)
	{
		m_inputs[i].resize(m_inputs[i].size(), 0.0);
		m_outputs[i].resize(m_outputs[i].size(), 0.0);
	
	}
}

} // atk namespace

#endif
