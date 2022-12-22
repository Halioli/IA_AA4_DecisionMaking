#pragma once
#include "FSMState.h"
#include "Vector2D.h"

class FSMState_Evade : public FSMState
{
	void Enter(Agent* agent, float dTime) override;
	FSMState* Update(Agent* agent, float dTime, Grid* _maze, AgentStates& state) override;
	void Exit(Agent* agent, float dTime) override;

	Vector2D CalculateFarthestCell(Agent* agent, Grid* _maze);
};

