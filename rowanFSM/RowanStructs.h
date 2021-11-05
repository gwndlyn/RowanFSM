#pragma once

#include "RowanDeclarations.h"

#include <map>
#include <vector>
#include <string>

namespace Rowan
{
	//for sprite animation 
	struct AnimationState
	{
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
		std::map<std::string, bool> conditionMap; //name, trigger

		//methods
		Transition(transID id, std::string nm, stateID from, stateID to)
			: uid{ id }, name{ nm }, fromState{ from }, toState{ to } {}

		//default methods
		Transition() = default;
		~Transition() = default;
		Transition(const Transition& rhs) = default;
		Transition(Transition&& rhs) noexcept = default;
		Transition& operator= (const Transition& rhs) = default;
		Transition& operator= (Transition&& rhs) noexcept = default;

		//helper functions
		std::string addCondition(const std::string& name); //all states by default false
		void removeCondition(const std::string& name);
		void setCondition(const std::string& name, bool status);
	};

	struct State
	{
		//info of the transition
		stateID uid{ undefState };
		std::string name{ "" };

		bool isDirty{ false };
		std::map<transID, Transition> transitionMap{};

		//extra state info, TODO template this later
		AnimationState animStateInfo{};

		//methods
		State(stateID id, std::string nm)
			: uid{ id }, name{ nm }
		{}

		//default methods
		State() = default;
		~State() = default;
		State(const State& rhs) = default;
		State(State&& rhs) noexcept = default;
		State& operator= (const State& rhs) = default;
		State& operator= (State&& rhs) noexcept = default;

		//helper functions
		transID addTransition(const std::string& name, stateID from, stateID to);
		void removeTransition(transID id);
		Transition& getTransition(transID id);
	};

	//template to reference from 
	//avoid repeatable state creation, references instead
	//struct Diagram
	//{
	//};

}