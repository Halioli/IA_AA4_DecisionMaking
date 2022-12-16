#include "FSMState_Evade.h"

void FSMState_Evade::Enter(Agent* agent, float dTime)
{
	// Define Enemy Target Pos
}

FSMState* FSMState_Evade::Update(Agent* agent, float dTime, Vector2D _randomPos, AgentStates& state)
{
	// TODO

	//if(enemy->hasGun())
		// if(enemy->inRange())
			// Calculate new position out of range
			// return nullptr
			
		// else
			// return FSMState Wander 
	//else
		//return FSMState chasé;


	// Agent deploy state actions/movement
	// ...
	// Transitions between states are checked here!
	// ...
	//if (timeToChange) return newState;
	//else return nullptr;
	return nullptr;
}

void FSMState_Evade::Exit(Agent* agent, float dTime)
{
}
