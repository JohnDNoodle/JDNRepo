/*
 * Assembly.cpp
 *
 *  Created on: 19.12.2015
 *      Author: JohnD_2
 */

#include "Assembly.h"

#include <stdexcept>

using namespace std;

void Assembly::addComponent(Component *comp)
{
	if (comp != NULL)
	{
		m_list.push_back(comp);
	}
	else
	{
		throw logic_error("Nullpointer cannot be added");
	}
}

ComponentList::size_type Assembly::removeComponent(Component *comp)
{
	if (comp != NULL)
	{
		m_list.remove(comp);
	}
	else
	{
		m_list.clear();
	}
	return m_list.size();
}

float Assembly::consumption() const
{
	float ret = 0.0;
	for(list<Component *>::const_iterator it = m_list.begin(); it != m_list.end(); ++it)
	{
		ret += (**it).consumption();
	}
	return ret;
}

void Assembly::collectAllLoads(Component::Collection &coll)
{
	for(list<Component *>::const_iterator it = m_list.begin(); it != m_list.end(); ++it)
	{
		(**it).collectAllLoads(coll);
	}
}
