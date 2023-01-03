#include "GOAPAStart.h"

GOAPAStar::GOAPAStar()
{
	neighbours = std::vector<KeyElement*>();
}

void GOAPAStar::FindPath(Agent* agent, float dt)
{
}

float GOAPAStar::Heuristic(KeyElement* goal, KeyElement* curr)
{
	float h;

	// [h(n) = sqrt(pow(n.x - goal.x, 2) + pow(n.y - goal.y, 2))] EUCLIDEA!!!
	return h = sqrt(pow(curr->position.x - goal->position.x, 2) + pow(curr->position.y - goal->position.y, 2));
}

void GOAPAStar::SetGoalPosition(Vector2D coinPos)
{
	goal->position =coinPos;
}

void GOAPAStar::AStarAlgorithm(PathFindingGraph* graph)
{
	int exploredNodes = 0;

	costSoFar.clear();
	cameFrom.clear();
	pathToGoal.clear();

	//std::priority_queue<KeyElement*, std::vector<KeyElement*>, CompareStates> tempFrontier;
	std::queue<KeyElement*> tempFrontier;
	tempFrontier.push(startingNode);
	cameFrom[startingNode] = NULL;
	costSoFar[startingNode] = 0.f;

	current = startingNode;

	while (!tempFrontier.empty())
	{
		current = tempFrontier.front();
		tempFrontier.pop();
		if (current->position == goal->position)
			break;

		for (int i = 0; i < SceneElements::Count - 1; i++)
		{

		}

		//for (int index = 0; index < 6; index++)
		//{
		//	if (cameFrom.find(current->neighbours[index]) == cameFrom.end())
		//	{
		//		float newCost = costSoFar[current] + current->neighbours[index]->GetWeight();

		//		//if next not in cost_so_far or new_cost < cost_so_far[next]:
		//		if (costSoFar.find(current->neighbours[index]) == costSoFar.end() || newCost < costSoFar[current->neighbours[index]])
		//		{
		//			costSoFar[current->neighbours[index]] = newCost;
		//			priority = newCost + Heuristic(goal, current->neighbours[index]);

		//			current->neighbours[index]->SetCost(priority);
		//			tempFrontier.push(current->neighbours[index]);

		//			cameFrom[current->neighbours[index]] = current;
		//		}

		//		++exploredNodes;
		//	}
		//}
	}

	// END
	pathToGoal.push_back(current);

	while (current && (current->position != startingNode->position))
	{
		current = cameFrom[current];
		pathToGoal.push_back(current);
	}

	pathToGoal.push_back(startingNode);
	std::reverse(pathToGoal.begin(), pathToGoal.end());

	std::cout << exploredNodes << std::endl;
}