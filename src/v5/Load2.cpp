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
	for(Component::Collection::const_iterator it = coll.begin(); it != coll.end(); ++it)
	{
		Load tempLoad = (dynamic_cast<const Load &>(**it));
		if(&tempLoad != NULL)
		{
			retSet.insert(tempLoad);
		}
		else
		{
			cerr << "Problem trying to cast to Load-subclass! Please check component " << (*it)->getName() << endl;
		}

	}
	return retSet;
}

ostream &operator<<(ostream &stream, const LoadSet &lSet)
{
	for(LoadSet::const_iterator it = lSet.begin(); it != lSet.end(); ++it)
	{
		stream << (*it).getName() << ":\tVerbrauch: " << (*it).consumption() << " W" << endl;
	}
	return stream;
}



