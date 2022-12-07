#pragma once
#include "FSMState.h"

class FSMState_Evade : public FSMState
{
	FSMState* Update(Agent* agent, float dTime) override;
};

