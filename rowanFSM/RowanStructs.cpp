#include "RowanStructs.h"

#include <map>
#include <vector>
#include <string>
#include <iostream>

namespace Rowan
{
	//transition functions
	std::string Transition::addCondition(const std::string& name)
	{
		std::cout << __FUNCTION__ << std::endl;
		std::string temp = FindUnoccupiedKey<std::string, bool>(conditionMap, name);
		conditionMap.emplace(temp, false);
		return temp;
	}
	void Transition::removeCondition(const std::string& name)
	{
		std::cout << __FUNCTION__ << std::endl;
		if (conditionMap.find(name) == conditionMap.end()) return;
		conditionMap.erase(name);
	}
	void Transition::setCondition(const std::string& name, bool status)
	{
		std::cout << __FUNCTION__ << std::endl;
		if (conditionMap.find(name) == conditionMap.end()) return;
		conditionMap[name] = status;
	}

	//state functions
	transID State::addTransition(const std::string& name, stateID from, stateID to)
	{
		std::cout << __FUNCTION__ << std::endl;
		transID id = FindUnoccupiedKey<transID, Transition>(transitionMap, 1);
		transitionMap.emplace(id, Transition{id, name, from, to});
		return id;
	}
	void State::removeTransition(transID id)
	{
		std::cout << __FUNCTION__ << std::endl;
		if (transitionMap.find(id) == transitionMap.end()) return;
		transitionMap.erase(id);
	}
	Transition& State::getTransition(transID id) 
	{ 
		std::cout << __FUNCTION__ << std::endl;
		return transitionMap[id];
	}
}
