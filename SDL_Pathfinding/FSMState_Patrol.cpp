#include "FSMState_Patrol.h"
#include <iostream>
#include "Agent.h"

void FSMState_Patrol::Enter(Agent* agent, float dTime)
{
	//TODO 

	 // 1. Define first position to wander
	 // 2. Reset pathfinding
}

FSMState* FSMState_Patrol::Update(Agent* agent, float dTime, Vector2D _randomPos, AgentStates& state)
{
	// TODO
	Vector2D temp = Vector2D(-1, -1);

	if (agent->getPosition() == agent->getTarget())
		agent->setTarget(_randomPos);
		
	if (temp.Distance(agent->targetAgent->getPosition(), agent->getPosition()) <= agent->GetDistanceTreshold())
	{
		if (agent->targetAgent->GetHasWeapon())
		{
			state = AgentStates::EVADE;
			return new FSMState_Evade();
		}
		else
		{
			state = AgentStates::CHASE;
			return new FSMState_Chase();
		}
	}

	state = AgentStates::NONE;
	return nullptr;
}

void FSMState_Patrol::Exit(Agent* agent, float dTime)
{
	//TODO
	std::cout << "Exiting Patrol state..." << std::endl;
}
