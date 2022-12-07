#pragma once
#include "GOAPAction.h"

class GOAPAction_Patrol : public GOAPAction
{
	void Update(Agent* agent, float dTime) override;
};

