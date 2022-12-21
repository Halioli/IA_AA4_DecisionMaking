#include "FSMState_Chase.h"
#include <iostream>
#include "Agent.h"

void FSMState_Chase::Enter(Agent* agent, float dTime)
{
	//TODO
	std::cout << "Entering Chase state..." << std::endl;	
}

FSMState* FSMState_Chase::Update(Agent* agent, float dTime, Grid* _maze, AgentStates& state)
{
	// TODO
	Vector2D temp = Vector2D(-1, -1);

	if (agent->getPosition() == agent->getTarget())
		agent->setTarget(agent->targetAgent->getPosition());

	if (temp.Distance(agent->targetAgent->getPosition(), agent->getPosition()) <= agent->GetDistanceTreshold())
	{
		if (agent->targetAgent->GetHasWeapon())
		{
			agent->agentStates = AgentStates::EVADE;
			return new FSMState_Evade();
		}
		else
		{
			agent->agentStates = AgentStates::NONE;
			return nullptr;
		}
	}

	agent->agentStates = AgentStates::PATROL;
	return new FSMState_Patrol();
}

void FSMState_Chase::Exit(Agent* agent, float dTime)
{
	//TODO
	std::cout << "Exiting Chase state..." << std::endl;
}
