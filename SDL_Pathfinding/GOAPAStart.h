#pragma once
#include <map>
#include <queue>
#include "PathFindingAlgorithm.h"
#include "Node.h"
#include "KeyElement.h"
#include "GOAPWorldState.h"

class GOAPAStar
{
public:
	GOAPAStar();
	~GOAPAStar();

	std::map<KeyElement*, KeyElement*> cameFrom;
	std::vector<KeyElement*> pathToGoal;
	std::map<KeyElement*, float> costSoFar;

	float priority;
	GOAPWorldState worldStateGOAP;

	std::vector<KeyElement*> neighbours;
	KeyElement* current;
	KeyElement* target;
	KeyElement* goal;
	KeyElement* startingNode;

	void FindPath(Agent* agent, float dt);
	float Heuristic(KeyElement* goal, KeyElement* curr);
	void Heuristic() {};
	void SetGoalPosition(Vector2D coinPos);
	void AStarAlgorithm(PathFindingGraph* graph);
};