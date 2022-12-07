#pragma once
#include "GOAPWorldState.h"
#include "Agent.h"

class GOAPAction
{
	GOAPWorldState preconditions;
	GOAPWorldState effects;
	int cost;

public:
	void SetPrecondition(int index, bool value);
	void SetEffect(int index, bool value);
	virtual void Update(Agent* agent, float dTime);
};

