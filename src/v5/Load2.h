#ifndef _LOAD2_H_
#define _LOAD2_H_

#include "Load.h"

#include <set>
using namespace std;
 
typedef set<Load> LoadSet;
	
LoadSet transferCollection(const Component::Collection &coll);
ostream &operator<<(ostream &, const LoadSet &);

#endif

