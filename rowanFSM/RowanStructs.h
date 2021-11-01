#pragma once

#include "RowanDeclarations.h"

#include <vector>
#include <map>
#include <string>

namespace Rowan
{
	//for sprite animation 
	struct AnimationState
	{
		//std::string stateName{ "" };
		//std::vector<Transition> conditions{};

		int startFrame{ 0 };
		int endFrame{ 0 };
		float frameDelay{ 0.0f };

		bool isLooping{ false }; //does it loop
		bool isFinished{ false }; //if it doesnt loop, is it finished playing
	};

	// in increasing order 
	struct Transition
	{
		//info of the transition
		transID uid{ undefTrans };
		std::string name{ "" };

		//from and to states
		stateID fromState{ undefState };
		stateID toState{ undefState };

		//conditions for transition
		std::map<std::string, bool> conditions; //name, trigger

		//methods
		Transition(transID id, std::string nm, stateID from, stateID to)
			: uid{ id }, name{ nm }, fromState{ from }, toState{ to } {}

		//default methods
		Transition(const Transition& rhs) = default;
		Transition(Transition&& rhs) noexcept = default;
		Transition& operator= (const Transition& rhs) = default;
		Transition& operator= (Transition&& rhs) noexcept = default;
	};

	struct State
	{
		//info of the transition
		stateID uid{ undefState };
		std::string name{ "" };

		bool isDirty{ false };
		std::vector<transID> transitions{};
		AnimationState animStateInfo{};

		//methods
		State(stateID id, std::string nm)
			: uid{ id }, name{ nm } {}

		//default methods
		State(const State& rhs) = default;
		State(State&& rhs) noexcept = default;
		State& operator= (const State& rhs) = default;
		State& operator= (State&& rhs) noexcept = default;
	};

	//template to reference from 
	//avoid repeatable state creation, references instead
	struct Diagram
	{

	};

	//maintains the curr obj's state
	//acts like a component //similar to Hekate's Agent
	struct Controller
	{
		//give access to diagram
		friend Diagram;

		//FSM states
		stateID currState{ undefState };
		stateID prevState{ undefState };

		Diagram* m_diagram; //might change to const ref
	};

	//acts like a system
	struct Manager
	{
		std::vector<Controller> controllers;
	};
}