#pragma once
#include <map>
#include <queue>
#include "PathFindingAlgorithm.h"
#include "Node.h"
#include "GOAPWorldState.h"
#include "GOAPAction.h"

class GOAPAStar
{
public:
	GOAPAStar(std::vector<GOAPAction*> actions, GOAPWorldState*);
	~GOAPAStar();

	std::map<GOAPWorldState*, std::pair<GOAPWorldState*, GOAPAction*>> cameFrom;
	std::vector<GOAPAction*> planToGoal;
	std::map<GOAPWorldState*, float> costSoFar;

	float priority;
	// Actions
	std::vector<GOAPAction*> goapActions; // All possible actions, used to get neighbours
	std::vector<GOAPAction*> neighbourActions;
	GOAPAction* currentAction;
	GOAPAction* targetAction;
	//GOAPAction* goalAction;
	GOAPAction* startingAction;

	// World States
	//std::vector<GOAPWorldState*> neighbourWorldStates;
	//GOAPWorldState* currentWorldState;
	//GOAPWorldState* targetWorldState;
	GOAPWorldState* goalWorldState;
	GOAPWorldState* startingWorldState;


	void FindPath(Agent* agent, float dt);
	float Heuristic(GOAPAction* goal, GOAPAction* curr);
	void SetGoalPosition(Vector2D coinPos);
	void AStarAlgorithm();
	std::vector<std::pair<GOAPWorldState*, GOAPAction*>> GetWorldStateNeighbours(GOAPWorldState* _worldState);
};