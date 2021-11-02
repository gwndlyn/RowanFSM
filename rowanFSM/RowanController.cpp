#include "RowanDeclarations.h"
#include "RowanStructs.h"
#include "RowanController.h"


namespace Rowan
{
	void Controller::changeState(stateID nextState)
	{
		prevState = currState;
		currState = nextState;
	}
	stateID Controller::addState(std::string name)
	{
		stateID id = FindUnoccupiedKey<stateID, State>(stateMap, 1);
		stateMap.emplace(id, name);
		return id;
	}
	void Controller::removeState(stateID id)
	{
		//error handling
		if (stateMap.find(id) == stateMap.end()) return; //check if it exists
		if (id == startState) startState = undefState;

		//remove from the map
		stateMap.erase(id);
	}

	void Controller::init()
	{
	}
	void Controller::update()
	{
		for (const auto& t : stateMap[currState].transitionMap)
		{
			int i = 0;
			for (const auto& c : t.second.conditionMap)
			{
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