#include "FSMState_Patrol.h"
#include <iostream>

void FSMState_Patrol::Enter(Agent* agent, float dTime)
{
	//TODO 

	 // 1. Define first position to wander
	 // 2. Reset pathfinding
}

FSMState* FSMState_Patrol::Update(Agent* agent, float dTime)
{
	// TODO
	 
		// if (currentPos == targetPos)
			// New position code
		//else
			//	Calculate new random pos
		
	 // if(target->inRange())
		// if(target->hasGun())
			//return FSMState_Evade;
		//else 
			//return FSMState_Chasé;
	// else
		//return nullptr;


	// Agent deploy state actions/movement
	// ...
	// Transitions between states are checked here!
	// ...
	//if (timeToChange) return newState;
	//else return nullptr;
	return nullptr;
}

void FSMState_Patrol::Exit(Agent* agent, float dTime)
{
	//TODO
	std::cout << "Exiting Patrol state..." << std::endl;
}
