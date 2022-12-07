#pragma once
#include "FSMState.h"

class FSMState_Patrol : public FSMState
{
	FSMState* Update(Agent* agent, float dTime) override;
};

