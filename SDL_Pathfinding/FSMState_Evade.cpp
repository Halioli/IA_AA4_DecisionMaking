#include "FSMState_Evade.h"
#include "Grid.h"

void FSMState_Evade::Enter(Agent* agent, float dTime)
{
	// Define Enemy Target Pos
}

FSMState* FSMState_Evade::Update(Agent* agent, float dTime, Grid* _maze, AgentStates& state)
{
	// TODO
	Vector2D tempPos = Vector2D(-1, -1);

	agent->setTarget(CalculateFarthestCell(agent, _maze));

	if (tempPos.Distance(agent->targetAgent->getPosition(), agent->getPosition()) <= agent->GetDistanceTreshold())
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
}

Vector2D FSMState_Evade::CalculateFarthestCell(Agent* agent, Grid* _maze)
{
	Vector2D result;

	// tempPos ha de valer la posició del neighbour més llunyà al Monke
	Vector2D agentPos = agent->getPosition();

	Vector2D upPos = Vector2D(agentPos.x - 1, agentPos.y);
	Vector2D downPos = Vector2D(agentPos.x + 1, agentPos.y);
	Vector2D leftPos = Vector2D(agentPos.x, agentPos.y - 1);
	Vector2D rightPos = Vector2D(agentPos.x, agentPos.y + 1);

	float upDistance = upPos.Distance(agent->getPosition(), upPos);
	std::cout << "> Up Distance: " << upDistance << std::endl;

	float downDistance = downPos.Distance(agent->getPosition(), downPos);
	std::cout << "> Down Distance: " << downDistance << std::endl;

	float leftDistance = leftPos.Distance(agent->getPosition(), leftPos);
	std::cout << "> Left Distance: " << leftDistance << std::endl;

	float rightDistance = rightPos.Distance(agent->getPosition(), rightPos);
	std::cout << "> Right Distance: " << rightDistance << std::endl;

	float farthestDistance = 0.0f;

	for (int i = 0; i < 3; i++)
	{
		// Falta agrupar les distàncies en un array (i poder iterar-lo dins el for).
	}

	return result;
}
