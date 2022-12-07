#pragma once
#include <vector>
#include <string>
#include <map>
#include "Agent.h"
#include "GOAPAction.h"
#include "GOAPWorldState.h"

class GOAP
{
	std::vector<std::string> atomNames;
	std::map<std::string, GOAPAction> actions;
	std::vector<GOAPAction*> plan;
	int currentActionIndex = 0;

	GOAPWorldState start; // hardcoded
	GOAPWorldState goal;  // hardcoded

	void Update(Agent* agent, float dTime);
	void AStar(GOAPWorldState start, GOAPWorldState end);
};

