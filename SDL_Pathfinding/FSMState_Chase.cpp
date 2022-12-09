#include "FSMState_Chase.h"
#include <iostream>

void FSMState_Chase::Enter(Agent* agent, float dTime)
{
	//TODO

		//Guardar target(agent)
		
}

FSMState* FSMState_Chase::Update(Agent* agent, float dTime)
{
	// TODO

	//if(!enemy->hasGun())
		//Calculate target position
		

	// Agent deploy state actions/movement
	// ...
	// Transitions between states are checked here!
	// ...
	//if (timeToChange) return newState;
	//else return nullptr;
	return nullptr;
}

void FSMState_Chase::Exit(Agent* agent, float dTime)
{
	//TODO
	std::cout << "Exiting Chasé state..." << std::endl;

}
