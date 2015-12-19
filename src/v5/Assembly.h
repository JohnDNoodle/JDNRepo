/*
 * Assembly.h
 *
 *  Created on: 19.12.2015
 *      Author: JohnD_2
 */

#ifndef ASSEMBLY_H_
#define ASSEMBLY_H_

#include "Component.h"

#include <list>


using namespace std;

typedef std::list<Component *> ComponentList;

class Assembly : public Component
{
	ComponentList m_list;
public:
	Assembly(const string &name) : Component(name) {};
	void addComponent(Component *comp);
	ComponentList::size_type removeComponent(Component *comp);
	float consumption() const;
	void collectAllLoads(Component::Collection &coll);
	virtual ~Assembly() {};
};

#endif /* ASSEMBLY_H_ */
