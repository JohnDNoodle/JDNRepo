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
	if (comp == NULL)
	{
		throw logic_error("Nullpointer cannot be added");
	}
	m_list.push_back(comp);
}

ComponentList::size_type Assembly::removeComponent(Component *comp)
{
	ComponentList::size_type retAmount = m_list.size();
	if (comp != NULL)
	{
		m_list.remove(comp);
	}
	else
	{
		m_list.clear();
	}
	retAmount -= m_list.size();
	return retAmount;
}

float Assembly::consumption() const
{
	float ret = 0.0;
	for(ComponentList::const_iterator it = m_list.begin(); it != m_list.end(); ++it)
	{
		ret += (*it)->consumption();
	}
	return ret;
}

void Assembly::collectAllLoads(Component::Collection &coll)
{
	for(ComponentList::const_iterator it = m_list.begin(); it != m_list.end(); ++it)
	{
		(*it)->collectAllLoads(coll);
	}
}
