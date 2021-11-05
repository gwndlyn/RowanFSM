//#include "RowanDiagram.h"
//
//namespace Rowan
//{
	//void AnimationController::Init()
	//{	}
	//void AnimationController::update(float dt)
	//{	}
	//void AnimationController::setNewState(std::string&& state)
	//{
	//	prevState = std::move(currState);
	//	currState = std::move(state);
	//}
	//bool AnimationController::addNewState(std::string state)
	//{
	//	//if a state of the same name exists, don't allow it to be created
	//	//assertgs(stateMap.find(state) == stateMap.end());
	//	if (stateMap.find(state) == stateMap.end()) return false;
	//	stateMap.insert(std::pair<std::string, AnimationState>(state, AnimationState{}));
	//	return true;
	//}
	//bool AnimationController::removeState(std::string state)
	//{
	//	//if state does not exist, prevent out of bound
	//	if (stateMap.find(state) != stateMap.end()) return false;
	//	if (prevState == state) prevState = "";
	//	if (currState == state) currState = "";
	//	stateMap.erase(stateMap.find(state));
	//	return true;
	//}

//}