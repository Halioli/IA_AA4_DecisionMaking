#pragma once
#include "DecisionMakingAlgorithm.h"
#include "FSMState.h"
#include "Agent.h"
#include "AgentStates.h"

class FSM : public DecisionMakingAlgorithm
{
public:
	FSMState* currentState;

	void Update(Agent* agent, float dTime, Vector2D _randomPos) override;
	void ChangeState(Agent* agent, float dTime, FSMState* newState);
};

