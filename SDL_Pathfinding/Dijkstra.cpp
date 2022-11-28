#include "Dijkstra.h"

Dijkstra::Dijkstra()
{
	current = new Node(Vector2D(0.0f, 0.0f), 0.0f);
	goal = new Node(Vector2D(0.0f, 0.0f), 0.0f);
	startingNode = new Node(Vector2D(0.0f, 0.0f), 0.0f);
}

void Dijkstra::FindPath(Agent* agent, float dt)
{
}

float Dijkstra::Heuristic(Node* goal, Node* curr)
{
	// [h(n) = sqrt(pow(n.x - goal.x, 2) + pow(n.y - goal.y, 2))] EUCLIDEA!!!
	float h;

	return h = sqrt(pow(curr->GetPos().x - goal->GetPos().x, 2) + pow(curr->GetPos().y - goal->GetPos().y, 2));
}

void Dijkstra::SetGoalPosition(Vector2D coinPos)
{
	goal->SetPos(coinPos);
}

void Dijkstra::DijkstraAlgorithm(PathFindingGraph* graph)
{
	costSoFar.clear();
	cameFrom.clear();
	pathToGoal.clear();

	std::priority_queue<Node*, std::vector<Node*>, CompareNodes> tempFrontier;
	tempFrontier.push(startingNode);
	cameFrom[startingNode] = NULL;
	costSoFar[startingNode] = 0.f;

	current = startingNode;

	while (!tempFrontier.empty())
	{
		current = tempFrontier.top();
		tempFrontier.pop();
		if (current->GetPos() == goal->GetPos())
			break;

		for (int index = 0; index < current->neighbours.size(); index++)
		{
			if (cameFrom.find(current->neighbours[index]) == cameFrom.end())
			{
				float newCost = costSoFar[current] + current->neighbours[index]->GetWeight();

				//if next not in cost_so_far or new_cost < cost_so_far[next]:
				if (costSoFar.find(current->neighbours[index]) == costSoFar.end() || newCost < costSoFar[current->neighbours[index]])
				{
					costSoFar[current->neighbours[index]] = newCost;
					priority = newCost;

					current->neighbours[index]->SetCost(priority);
					tempFrontier.push(current->neighbours[index]);

					cameFrom[current->neighbours[index]] = current;
				}
			}
		}
	}


	// END
	pathToGoal.push_back(current);

	while (current && (current->GetPos() != startingNode->GetPos()))
	{
		current = cameFrom[current];
		pathToGoal.push_back(current);
	}

	pathToGoal.push_back(startingNode);
	std::reverse(pathToGoal.begin(), pathToGoal.end());
}
