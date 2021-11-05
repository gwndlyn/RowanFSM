#include "RowanDeclarations.h"
#include "RowanStructs.h"
#include "RowanController.h"

#include <iostream>


namespace Rowan
{
	void Controller::changeState(stateID nextState)
	{
		std::cout << __FUNCTION__ << std::endl;
		prevState = currState;
		currState = nextState;
	}
	stateID Controller::addState(std::string name)
	{
		std::cout << __FUNCTION__ << std::endl;
		stateID id = FindUnoccupiedKey<stateID, State>(stateMap, 1);
		stateMap.emplace(id, State{id, name});
		return id;
	}
	void Controller::removeState(stateID id)
	{
		std::cout << __FUNCTION__ << std::endl;
		//error handling
		if (stateMap.find(id) == stateMap.end()) return; //check if it exists
		if (id == startState) startState = undefState;

		//remove from transitions
		for (auto& s : stateMap)
		{
			for (auto& t : s.second.transitionMap)
			{
				if (t.second.fromState == id || t.second.toState == id)
				{
					//remove that transition
					s.second.transitionMap.erase(t.first);
				}
			}
		}

		//remove from the map
		stateMap.erase(id);
	}

	void Controller::init()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	void Controller::update()
	{
		std::cout << __FUNCTION__ << std::endl;
		
		stateID pState = currState;
		for (auto& t : stateMap[currState].transitionMap)
		{
			if (currState != pState) break;

			int i = 0;
			for (auto& c : t.second.conditionMap)
			{
				//c.second = true; //remove later (testing only)
				if (c.second) ++i;
			}
			//if all conditions for changing state met
			if (i == t.second.conditionMap.size())
			{
				changeState(t.second.toState);
			}
		}
		
	}


}