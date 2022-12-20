#include "FSMState_Patrol.h"
#include <iostream>
#include "Agent.h"

void FSMState_Patrol::Enter(Agent* agent, float dTime)
{
	//TODO 
	std::cout << "Entering Patrol state..." << std::endl;

	 // 1. Define first position to wander
	 // 2. Reset pathfinding
}

FSMState* FSMState_Patrol::Update(Agent* agent, float dTime, Vector2D _randomPos, AgentStates& state)
{
	Vector2D temp = Vector2D(-1, -1);

	if (agent->getPosition() == agent->getTarget())
		agent->setTarget(_randomPos);
		
	if (temp.Distance(agent->targetAgent->getPosition(), agent->getPosition()) <= agent->GetDistanceTreshold())
	{
		if (agent->targetAgent->GetHasWeapon())
		{
			agent->agentStates = AgentStates::EVADE;

			return new FSMState_Evade();
		}
		else
		{
			agent->agentStates = AgentStates::CHASE;

			return new FSMState_Chase();
		}
	}

	agent->agentStates = AgentStates::NONE;
	return nullptr;
}

void FSMState_Patrol::Exit(Agent* agent, float dTime)
{
	//TODO
	std::cout << "Exiting Patrol state..." << std::endl;
}
