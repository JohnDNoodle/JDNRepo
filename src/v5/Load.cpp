/*
 * Load.cpp
 *
 *  Created on: 19.12.2015
 *      Author: JohnD_2
 */

#include "Load.h"
#include "Component.h"

#include <iostream>
#include <stdexcept>


using namespace std;


float Load::consumption() const
{
	if ((m_dEfficiency == 0.0))
	{
		throw logic_error("Efficiency must not be 0.");
	}
	return (m_dPowerOut/m_dEfficiency);
}

void Load::collectAllLoads(Component::Collection &coll)
{
	coll.push_back(this);
}

bool operator<(const Load &load1, const Load &load2)
{
	return (load1.consumption()<load2.consumption());
}

ostream &operator<<(ostream &stream, const Component::Collection &coll)
{
	for(vector<const Component *>::const_iterator it = coll.begin(); it != coll.end(); ++it)
	{
		stream << (*it)->getName() << ":\tVerbrauch: " << (*it)->consumption() << " W" << endl;
	}
	return stream;
}
