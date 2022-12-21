#pragma once
#include "FSMState.h"
#include "Vector2D.h"

class FSMState_Patrol : public FSMState
{
	void Enter(Agent* agent, float dTime) override;
	FSMState* Update(Agent* agent, float dTime, Grid* _maze, AgentStates& state) override;
	void Exit(Agent* agent, float dTime) override;
};

