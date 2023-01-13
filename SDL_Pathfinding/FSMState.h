#pragma once

#include "AgentStates.h"

class Agent;
class Vector2D;
class Grid;

class FSMState
{
public:
	virtual void Enter(Agent* agent, float dTime);
	virtual FSMState* Update(Agent* agent, float dTime, Grid* _maze, AgentStates& state);
	virtual void Exit(Agent* agent, float dTime);
};

