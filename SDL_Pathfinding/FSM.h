#pragma once
#include "DecisionMakingAlgorithm.h"
#include "FSMState.h"
#include "Agent.h"

class FSM : public DecisionMakingAlgorithm
{
public:
	FSMState* currentState;

	void Update(Agent* agent, float dTime) override;
	void ChangeState(Agent* agent, float dTime, FSMState* newState);
};

