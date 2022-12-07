#include "FSM.h"

void FSM::Update(Agent* agent, float dTime)
{
	FSMState* newState = currentState->Update(agent, dTime);
	
	if (newState != nullptr) ChangeState(agent, dTime, newState);
}

void FSM::ChangeState(Agent* agent, float dTime, FSMState* newState)
{
	currentState->Exit(agent, dTime);
	currentState = newState;
	currentState->Enter(agent, dTime);
}
