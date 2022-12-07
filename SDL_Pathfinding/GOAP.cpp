#include "GOAP.h"

void GOAP::Update(Agent* agent, float dTime)
{
	// ...
	if (plan.empty()) AStar(start, goal);
	else
	{
		// Deploy existing plan
		plan[currentActionIndex]->Update(agent, dTime);
		// ...
		// Check currAction effects and currAction precond!
		//		- time for next action?
		//		- reset plan?
		// ...
	}
}

void GOAP::AStar(GOAPWorldState start, GOAPWorldState end)
{
	// TODO
}
