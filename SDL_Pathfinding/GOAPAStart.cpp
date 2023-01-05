#include "GOAPAStart.h"

GOAPAStar::GOAPAStar(std::vector<GOAPAction*> actions)
{
	//neighbourWorldStates = std::vector<GOAPWorldState*>();
	neighbourActions = std::vector<GOAPAction*>();
	goapActions = actions;
}

void GOAPAStar::FindPath(Agent* agent, float dt)
{
}

float GOAPAStar::Heuristic(GOAPAction* goal, GOAPAction* curr)
{
	float h;

	// [h(n) = sqrt(pow(n.x - goal.x, 2) + pow(n.y - goal.y, 2))] EUCLIDEA!!!
	h = sqrt(pow(curr->GetElementPosition().x - goal->GetElementPosition().x, 2) + pow(curr->GetElementPosition().y - goal->GetElementPosition().y, 2));

	return h;
}

void GOAPAStar::SetGoalPosition(Vector2D coinPos)
{
	//goal->position = coinPos;
}

void GOAPAStar::AStarAlgorithm(PathFindingGraph* graph)
{
	int exploredNodes = 0;

	costSoFar.clear();
	cameFrom.clear();
	planToGoal.clear();

	std::queue<GOAPWorldState*> tempActionsFrontier;
	tempActionsFrontier.push(startingWorldState);
	
	// TODO
}

std::vector<std::pair<GOAPWorldState*, GOAPAction*>> GOAPAStar::GetWorldStateNeighbours(GOAPWorldState* _worldState)
{
	std::vector<std::pair<GOAPWorldState*, GOAPAction*>> result = std::vector<std::pair<GOAPWorldState*, GOAPAction*>>();

	for (int i = 0; i < goapActions.size(); i++)
	{
		bool isSameState = true;

		for (auto it = goapActions[i]->GetPreconditions().value.begin(); it != goapActions[i]->GetPreconditions().value.end(); ++it)
		{
			auto iterator = _worldState->value.find(it->first);

			if (iterator == goapActions[i]->GetPreconditions().value.end())
			{
				isSameState = false;
				break;
			}
		}

		if (isSameState)
		{
			// Creem nou WorldState:
			GOAPWorldState* tempWorldState = new GOAPWorldState();

			for (auto it = _worldState->value.begin(); it != _worldState->value.end(); ++it)
			{
				tempWorldState->value[it->first] = true;
			}

			for (auto it = goapActions[i]->GetEffect().value.begin(); it != goapActions[i]->GetEffect().value.end(); ++it)
			{
				tempWorldState->value[it->first] = true;
			}

			result.push_back(std::pair<GOAPWorldState*, GOAPAction*>(tempWorldState, goapActions[i]));
		}
	}

	return result;
}
