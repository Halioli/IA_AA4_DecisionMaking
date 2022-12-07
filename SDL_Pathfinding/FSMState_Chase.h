#pragma once
#include "FSMState.h"

class FSMState_Chase : public FSMState
{
	FSMState* Update(Agent* agent, float dTime) override;
};

