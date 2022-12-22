#include "FSMState.h"
#include "Agent.h"

void FSMState::Enter(Agent* agent, float dTime)
{
	// Overriden in childs
}

FSMState* FSMState::Update(Agent* agent, float dTime, Grid* _maze, AgentStates& state)
{
	return nullptr;
}

void FSMState::Exit(Agent* agent, float dTime)
{
	// Overriden in childs
}
