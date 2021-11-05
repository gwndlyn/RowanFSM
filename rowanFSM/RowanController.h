#pragma once

#include "RowanStructs.h"

#include <map>
#include <string>

namespace Rowan
{
	//maintains the curr obj's state
	//acts like a component
	struct Controller
	{
		//FSM states
		stateID currState{ undefState };
		stateID prevState{ undefState };
		stateID startState{ undefState };

		//map of states to iterate through
		std::map<stateID, State> stateMap{};

		//helper functions
		void changeState(stateID nextState);
		stateID addState(std::string name);
		void removeState(stateID id);

		//main methods
		void init();
		void update();

		Controller() = default;
		~Controller() = default;
	};

	//acts like a system
	struct Manager
	{
		std::vector<Controller> controllers;

		//main methods
		void init();
		void update();
	};
}
