#pragma once
#include "PathFindingAlgorithm.h"
#include "Node.h"
#include <map>
#include <queue>

class AStar : PathFindingAlgorithm
{
	//Priority Queue
public:
	AStar();
	~AStar();

	struct CompareNodes
	{
		bool operator()(Node* a, Node* b)
		{
			return ((a->GetCost()) > (b->GetCost()));
		}
	};

	std::map<Node*, Node*> cameFrom;
	std::vector<Node*> pathToGoal;
	std::map<Node*, float> costSoFar;

	float priority;
	float enemyAvoidanceWeight = 50; // Increase it to make the player avoid the enemies more

	Node* current;
	Node* goal;
	Node* startingNode;

	void FindPath(Agent* agent, float dt) override;
	float Heuristic(Node* goal, Node* curr);
	void Heuristic() override {};
	void SetGoalPosition(Vector2D coinPos);
	void AStarAlgorithm(PathFindingGraph* graph);
	void AStarAlgorithmWithEnemies(PathFindingGraph* graph, std::vector<Agent*> _enemyAgents, Grid* _maze);
};