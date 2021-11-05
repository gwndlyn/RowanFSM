//#include "RowanDeclarations.h"
//#include "RowanStructs.h"
#include "RowanController.h"
#include "RowanStructs.h"

#include <iostream>
#include <string>

//test driver vroom vroom
int main()
{
	//create a controller (acts as a component in a GO)
	std::cout << "=== Test Create Controller ===" << std::endl;
	Rowan::Controller ct{};

	//add states to the controller
	std::cout << "=== Test Add State ===" << std::endl;
	Rowan::stateID s1 = ct.addState("State01");
	Rowan::stateID s2 = ct.addState("State02");
	Rowan::stateID s3 = ct.addState("State03");

	//add random transitions (made circular for now)
	std::cout << "=== Test Add Transitions ===" << std::endl;
	auto& sMap = ct.stateMap;
	Rowan::transID t1 = sMap[s1].addTransition("TransS1ToS2", s1, s2);
	Rowan::transID t2 = sMap[s2].addTransition("TransS2ToS3", s2, s3);
	Rowan::transID t3 = sMap[s3].addTransition("TransS3ToS1", s3, s1);

	std::cout << "=== Test Add Conditions ===" << std::endl;
	//auto& tMap = ct.stateMap[ct.currState].transitionMap;
	//std::string c1 = tMap[t1].addCondition("Cond1");
	//std::string c2 = tMap[t2].addCondition("Cond2");
	//std::string c3 = tMap[t3].addCondition("Cond3");

	std::string c1 = ct.stateMap[s1].transitionMap[t1].addCondition("Cond1");
	std::string c2 = ct.stateMap[s2].transitionMap[t2].addCondition("Cond2");
	std::string c3 = ct.stateMap[s3].transitionMap[t3].addCondition("Cond3");


	std::cout << "=== Test Set Start and Curr State ===" << std::endl;
	ct.currState = ct.startState = s1;

	//test state changes
	while (1)
	{
		std::cout << "=== Test Condition Changing ===" << std::endl;
		for (auto& t : ct.stateMap[ct.currState].transitionMap)
		{
			if (ct.currState == s1)
			{
				t.second.setCondition(c1, true);
				std::cout << "State Name: " << ct.stateMap[s1].name << std::endl;
				std::cout << "Curr State: " << ct.stateMap[ct.currState].name << std::endl;
			}
			if (ct.currState == s2)
			{
				t.second.setCondition(c2, true);
				std::cout << "State Name: " << ct.stateMap[s2].name << std::endl;
				std::cout << "Curr State: " << ct.stateMap[ct.currState].name << std::endl;
			}
			if (ct.currState == s3)
			{
				t.second.setCondition(c3, true);
				std::cout << "State Name: " << ct.stateMap[s3].name << std::endl;
				std::cout << "Curr State: " << ct.stateMap[ct.currState].name << std::endl;
			}
		}

		//test run update
		ct.update();
	}

	//remove transitions
	//maybe it will all delete itself here?

	return 0;
}