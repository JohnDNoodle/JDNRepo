/*
 * Load.h
 *
 *  Created on: 19.12.2015
 *      Author: JohnD_2
 */

#ifndef LOAD_H_
#define LOAD_H_

#include "Component.h"

#include <string>

using namespace std;

class Load : public Component
{
	float m_dPowerOut;
	float m_dEfficiency;

public:
	Load(string name, float power, float efficiency): Component(name), m_dPowerOut(power), m_dEfficiency(efficiency) {}; // A: der name, da aus superclass
	float getPowerOut() const {return m_dPowerOut;};
	float getEfficiency() const {return m_dEfficiency;};
	float consumption() const;
	void collectAllLoads(Component::Collection &);
	virtual ~Load(void) {};
};

bool operator<(const Load &, const Load &);
ostream &operator<<(ostream &, const Component::Collection &);

#endif /* LOAD_H_ */
