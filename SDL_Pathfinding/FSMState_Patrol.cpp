#include "FSMState_Patrol.h"
#include <iostream>
#include "Agent.h"

void FSMState_Patrol::Enter(Agent* agent, float dTime)
{
	//TODO 

	 // 1. Define first position to wander
	 // 2. Reset pathfinding
}

FSMState* FSMState_Patrol::Update(Agent* agent, float dTime)
{
	// TODO

	if (agent->getPosition() == agent->getTarget())
		agent->setTarget(rand()*);
	else
	{
		int i = 0;
	}
		//	Calculate new random pos
		
	// if(target->inRange())
		// if(target->hasGun())
			//return FSMState_Evade;
		//else 
			//return FSMState_Chas�;
	// else
	return nullptr;
}

void FSMState_Patrol::Exit(Agent* agent, float dTime)
{
	//TODO
	std::cout << "Exiting Patrol state..." << std::endl;
}
