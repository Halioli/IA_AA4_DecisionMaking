#pragma once
#include "FSMState.h"

class FSMState_Chase : public FSMState
{
	void Enter(Agent* agent, float dTime) override;
	FSMState* Update(Agent* agent, float dTime) override;
	void Exit(Agent* agent, float dTime) override;
};

