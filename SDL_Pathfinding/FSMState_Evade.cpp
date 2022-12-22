#include "FSMState_Evade.h"
#include "Grid.h"

void FSMState_Evade::Enter(Agent* agent, float dTime)
{
	// Define Enemy Target Pos
	std::cout << "Entering Evade state..." << std::endl;
}

FSMState* FSMState_Evade::Update(Agent* agent, float dTime, Grid* _maze, AgentStates& state)
{
	// TODO
	Vector2D tempPos = Vector2D(-1, -1);

	agent->setTarget(CalculateFarthestCell(agent, _maze));

	if (Vector2D::Distance(agent->targetAgent->getPosition(), agent->getPosition()) <= agent->GetDistanceTreshold())
	{
		if (agent->targetAgent->GetHasWeapon())
		{
			agent->agentStates = AgentStates::NONE;
			return nullptr;
		}
		else
		{
			agent->agentStates = AgentStates::CHASE;
			return new FSMState_Chase();
		}
	}

	agent->agentStates = AgentStates::PATROL;
	return new FSMState_Patrol();
}

void FSMState_Evade::Exit(Agent* agent, float dTime)
{
	std::cout << "Exit Evade state..." << std::endl;
}

Vector2D FSMState_Evade::CalculateFarthestCell(Agent* agent, Grid* _maze)
{
	Vector2D agentPos = agent->getPosition();
	std::vector<Vector2D> positions;

	positions.push_back(Vector2D(agentPos.x - 1, agentPos.y));
	positions.push_back(Vector2D(agentPos.x + 1, agentPos.y));
	positions.push_back(Vector2D(agentPos.x, agentPos.y - 1));
	positions.push_back(Vector2D(agentPos.x, agentPos.y + 1));

	float farthestDistance = 0.0f;
	int farthestIndex = 0;

	for (int i = 0; i < positions.size(); i++)
	{
		if (Vector2D::Distance(agentPos, positions[i]) > farthestDistance)
		{
			farthestDistance = Vector2D::Distance(agentPos, positions[i]);
			farthestIndex = i;
		}
	}

	return positions[farthestIndex];
}
