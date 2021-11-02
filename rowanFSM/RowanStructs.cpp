#include "RowanStructs.h"

#include <map>
#include <vector>
#include <string>

namespace Rowan
{
	//transition functions
	std::string Transition::addCondition(std::string name)
	{
		name = FindUnoccupiedKey<std::string, bool>(conditionMap, name);
		conditionMap.emplace(name, false);
		return name;
	}
	void Transition::removeCondition(std::string name)
	{
		if (conditionMap.find(name) == conditionMap.end()) return;
		conditionMap.erase(name);
	}
	void Transition::setCondition(std::string name, bool status)
	{
		if (conditionMap.find(name) == conditionMap.end()) return;
		conditionMap[name] = status;
	}

	//state functions
	transID State::addTransition(std::string name)
	{
		transID id = FindUnoccupiedKey<transID, Transition>(transitionMap, 1);
		transitionMap.emplace(id, name);
		return id;
	}
	void State::removeTransition(transID id)
	{
		if (transitionMap.find(id) == transitionMap.end()) return;
		transitionMap.erase(id);
	}
	Transition& State::getTransition(transID id) 
	{ 
		return transitionMap[id]; 
	}
}
