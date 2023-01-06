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
	h = sqrt(pow(curr->GetElementPosition().x - goal->GetElementPosition().x, 2) + pow(curr->GetElementPosition().y - goal->GetElementPosition().y, 2));

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
	
	// From here:
	currentAction = startingAction;//->SetEffect(*startingWorldState);

	while (!tempStatesFrontier.empty())
	{
		currentAction->SetEffect(*tempStatesFrontier.front());
		tempStatesFrontier.pop();

		if (currentAction->GetEffect().GetValue() == goalWorldState->GetValue())
			break;

		auto stateNeighbours = GetWorldStateNeighbours(&currentAction->GetEffect());

		for (int index = 0; index < stateNeighbours.size(); index++)
		{
			if (cameFrom.find(stateNeighbours[index].first) == cameFrom.end())
			{
				float newCost = costSoFar[&currentAction->GetEffect()] + stateNeighbours[index].second->GetCost();

				if (cameFrom.find(stateNeighbours[index].first) == cameFrom.end() || newCost < costSoFar[stateNeighbours[index].first])
				{
					costSoFar[stateNeighbours[index].first] = newCost;
					priority = newCost; // + Heuristic(goalWorldState, awto[index].second);

					stateNeighbours[index].second->SetCost(priority);
					tempStatesFrontier.push(stateNeighbours[index].first);

					cameFrom[stateNeighbours[index].first].second = currentAction;
				}

				++exploredNodes;
			}
		}
	}

	planToGoal.push_back(currentAction);

	while (currentAction && (currentAction != startingAction))//(currentAction->GetEffect().GetValue() != startingWorldState->GetValue())) // Ni de flies [flais] això serà amb GetValue(), però bueno
	{
		currentAction = cameFrom.find(&currentAction->GetEffect())->second.second;
		planToGoal.push_back(currentAction);
	}

	planToGoal.push_back(startingAction);
	std::reverse(planToGoal.begin(), planToGoal.end());

	std::cout << "Nº of explored actions: " << exploredNodes << std::endl;
}

std::vector<std::pair<GOAPWorldState*, GOAPAction*>> GOAPAStar::GetWorldStateNeighbours(GOAPWorldState* _worldState)
{
	std::vector<std::pair<GOAPWorldState*, GOAPAction*>> result = std::vector<std::pair<GOAPWorldState*, GOAPAction*>>();

	for (int i = 0; i < goapActions.size(); i++)
	{
		bool isSameState = true;

		for (auto it = goapActions[i]->GetPreconditions().value.begin(); it != goapActions[i]->GetPreconditions().value.end(); ++it) // Peta aquí:
																																	 // Error: "map/set iterators incompatible".
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
