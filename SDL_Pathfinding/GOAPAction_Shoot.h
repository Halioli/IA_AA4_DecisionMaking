#pragma once
#include "GOAPAction.h"

class GOAPAction_Shoot : public GOAPAction
{
	void Update(Agent* agent, float dTime) override;
};

