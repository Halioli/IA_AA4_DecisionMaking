#pragma once

#include "AgentStates.h"

class Agent;
class Vector2D;

class FSMState
{
public:
	virtual void Enter(Agent* agent, float dTime);
	virtual FSMState* Update(Agent* agent, float dTime, Vector2D _randomPos);
	virtual void Exit(Agent* agent, float dTime);
};

