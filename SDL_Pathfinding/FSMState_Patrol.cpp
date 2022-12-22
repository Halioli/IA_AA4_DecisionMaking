#include <iostream>

#include "FSMState_Patrol.h"
#include "Agent.h"
#include "Grid.h"

void FSMState_Patrol::Enter(Agent* agent, float dTime)
{
	//TODO 
	std::cout << "Entering Patrol state..." << std::endl;

	 // 1. Define first position to wander
	 // 2. Reset pathfinding
}

FSMState* FSMState_Patrol::Update(Agent* agent, float dTime, Grid* _maze, AgentStates& state)
{
	Vector2D tempPos = Vector2D(-1, -1);

	if (agent->getCurrentTargetIndex() == -1)
	{
		while (!_maze->isValidCell(tempPos) || (Vector2D::Distance(tempPos, _maze->pix2cell(tempPos))) < 3)
			tempPos = Vector2D((float)(rand() % _maze->getNumCellX()), (float)(rand() % _maze->getNumCellY()));

		agent->setTarget(tempPos);

		//std::cout << tempPos.x << " / " << tempPos.y << std::endl;
	}
		
	if (Vector2D::Distance(agent->targetAgent->getPosition(), agent->getPosition()) <= agent->GetDistanceTreshold())
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
