#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <string>
#include <map>
#include <vector>

namespace GSEngine
{
	// primitive type aliases
	using stateID = long;
	//using transid = size_t;

	constexpr stateID undefinedState = 0; // entry/undef state

	struct TransitionCondition
	{
		std::string nextState{ "" };


	};

	struct AnimationState
	{
		std::string stateName{ "" };

		std::vector<TransitionCondition> conditions{};

		int startFrame{ 0 };
		int endFrame{ 0 };
		float frameDelay{ 0.0f };

		bool isLooping{ false }; //does it loop
		bool isFinished{ false }; //if it doesnt loop, is it finished playing
	};

	class AnimationController
	{
	private:
		std::map<std::string, AnimationState> stateMap{};

	public:
		//class variables
		std::string currState{};
		std::string prevState{};

		//class methods
		void Init();
		void update(float dt);

		//helper functions
		void setNewState(std::string&& state);
		//returns true for success, false for failure
		bool addNewState(std::string state);
		bool removeState(std::string state);
	};
}

#endif