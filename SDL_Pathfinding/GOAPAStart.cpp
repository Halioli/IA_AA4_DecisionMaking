#include "GOAPAStart.h"

GOAPAStar::GOAPAStar(std::vector<GOAPAction*> actions, GOAPWorldState* worldState)
{
	//neighbourWorldStates = std::vector<GOAPWorldState*>();
	neighbourActions = std::vector<GOAPAction*>();
	goapActions = actions;

	startingAction = new GOAPAction();
	startingWorldState = new GOAPWorldState();
	startingWorldState = worldState;

	startingAction->SetEffect(*startingWorldState);
	startingAction->SetPreconditions(*startingWorldState);
}

void GOAPAStar::FindPath(Agent* agent, float dt)
{
}

float GOAPAStar::Heuristic(GOAPAction* goal, GOAPAction* curr)
{
	float h;

	// [h(n) = sqrt(pow(n.x - goal.x, 2) + pow(n.y - goal.y, 2))] EUCLIDEA!!!
	h = sqrt(pow(curr->elementPosition.x - goal->elementPosition.x, 2) + pow(curr->elementPosition.y - goal->elementPosition.y, 2));

	return h;
}

void GOAPAStar::SetGoalPosition(Vector2D coinPos)
{
	//goal->position = coinPos;
}

void GOAPAStar::AStarAlgorithm()
{
	int exploredNodes = 0;

	costSoFar.clear();
	cameFrom.clear();
	planToGoal.clear();

	std::queue<GOAPWorldState*> tempStatesFrontier;
	tempStatesFrontier.push(startingWorldState);
	costSoFar[startingWorldState] = 0.0f; // Seems legit
	
	currentWorldState = startingWorldState;

	while (!tempStatesFrontier.empty())
	{
		currentWorldState = tempStatesFrontier.front();
		tempStatesFrontier.pop();

		auto goalIt = currentWorldState->value.find(SceneElements::Coin);
		bool foundEnd = goalIt != currentWorldState->value.end() && goalIt->second;
		if (foundEnd) // NEVER ENTERS
		{
			std::cout << "EARLY EXIT" << std::endl;
			break;
		}

		// Retorna size = 0
		auto stateNeighbours = GetWorldStateNeighbours(currentWorldState); // POT NO ESTAR DONANT ESTATS ACTUALITZATS

		for (int index = 0; index < stateNeighbours.size(); index++)
		{
			float newCost = costSoFar[currentWorldState] + stateNeighbours[index].second->cost;

			if (cameFrom.find(stateNeighbours[index].first) == cameFrom.end() || newCost < costSoFar[stateNeighbours[index].first])
			{
				costSoFar[stateNeighbours[index].first] = newCost;
				priority = newCost; // + Heuristic(goalWorldState, awto[index].second);

				stateNeighbours[index].second->SetCost(priority);
				tempStatesFrontier.push(stateNeighbours[index].first); // KEEPS ADDING STUFF
				std::cout << tempStatesFrontier.size() << std::endl;

				cameFrom[stateNeighbours[index].first] = std::pair<GOAPWorldState*, GOAPAction*>(currentWorldState, stateNeighbours[index].second);
			}

			++exploredNodes;
		}
	}

	planToGoal.push_back(currentAction);

	while (currentAction && (currentAction != startingAction))
	{
		currentAction = cameFrom.find(&currentAction->effects)->second.second;
		planToGoal.push_back(currentAction);
	}

	planToGoal.push_back(startingAction);
	std::reverse(planToGoal.begin(), planToGoal.end());

	std::cout << "Number of explored actions: " << exploredNodes << std::endl;
}

std::vector<std::pair<GOAPWorldState*, GOAPAction*>> GOAPAStar::GetWorldStateNeighbours(GOAPWorldState* _worldState)
{
	std::vector<std::pair<GOAPWorldState*, GOAPAction*>> result = std::vector<std::pair<GOAPWorldState*, GOAPAction*>>();

	for (int i = 0; i < goapActions.size(); i++)
	{
		bool isSameState = true;

		//per cada clau del diccionari goapActions[i]->preconditions.value comprovem que el valor sigui igual al de la mateixa clau en _worldState->value
		for (int j = SceneElements::RedKey; j < SceneElements::Count - 1; j++)
		{
			if (goapActions[i]->preconditions.value.find((SceneElements)j) != goapActions[i]->preconditions.value.end())
			{
				if (_worldState->value.find((SceneElements)j)->second != goapActions[i]->preconditions.value.find((SceneElements)j)->second)
				{
					isSameState = false;
					break;
				}
			}
		}

		if (isSameState)
		{
			// Creem nou WorldState:
			GOAPWorldState* tempWorldState = new GOAPWorldState();

			for (auto it = _worldState->value.begin(); it != _worldState->value.end(); ++it)
			{
				tempWorldState->value[it->first] = _worldState->value[it->first];
			}

			for (auto it = goapActions[i]->effects.value.begin(); it != goapActions[i]->effects.value.end(); ++it)
			{
				tempWorldState->value[it->first] = goapActions[i]->effects.value[it->first];
			}

			result.push_back(std::pair<GOAPWorldState*, GOAPAction*>(tempWorldState, goapActions[i]));
		}
	}

	return result;
}
