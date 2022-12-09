#pragma once
#include "FSMState_Patrol.h"
#include "FSMState_Chase.h"
#include "FSMState_Evade.h"

class AgentPointer
{
public:
	FSMState_Patrol patrolState;
	FSMState_Chase chaseState;
	FSMState_Evade evadeState;
};

