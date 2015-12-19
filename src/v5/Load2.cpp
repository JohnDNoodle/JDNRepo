/*
 * Load2.cpp
 *
 *  Created on: 19.12.2015
 *      Author: JohnD_2
 */

#include "Load2.h"

#include <iostream>
#include <typeinfo>

using namespace std;

LoadSet transferCollection(const Component::Collection &coll)
{
	LoadSet retSet;
	for(vector<const Component *>::const_iterator it = coll.begin(); it != coll.end(); ++it)
	{
		try
		{
			retSet.insert(dynamic_cast<const Load &>(**it));
		}
		catch (bad_cast & ex)
		{
			cerr << ex.what() << endl;
		}

	}
	return retSet;
}

ostream &operator<<(ostream &stream, const LoadSet &lSet)
{
	for(set<Load>::const_iterator it = lSet.begin(); it != lSet.end(); ++it)
	{
		stream << (*it).getName() << ":\tVerbrauch: " << (*it).consumption() << " W" << endl;
	}
	return stream;
}



