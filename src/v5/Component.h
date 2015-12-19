// Component.h: Schnittstelle für die Klasse Component.
//////////////////////////////////////////////////////////////////////
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
	
#include <string>
#include <vector>
using namespace std;
	
class Component
{
	string m_sName;
public:
	typedef vector<const Component *> Collection;  // Typdefinition fuer
                                                   // collectAllLoads()
    Component(const string &name) : m_sName(name) { }

	virtual float consumption() const = 0;
	virtual void collectAllLoads(Collection &) = 0;

	string getName() const       { return m_sName;  }

	virtual ~Component(void) { };
};

#endif
