#pragma once

class Agent;

class FSMState
{
public:
	virtual void Enter(Agent* agent, float dTime);
	virtual FSMState* Update(Agent* agent, float dTime);
	virtual void Exit(Agent* agent, float dTime);
};

