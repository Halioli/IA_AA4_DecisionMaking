#include "FSM.h"

void FSM::Update(Agent* agent, float dTime, Vector2D _randomPos) 
{
	AgentStates newState{}; // No fa falta
	FSMState* newFSMState = currentState->Update(agent, dTime, _randomPos, newState); // No fa falta newState (hehe)

	if (agent->agentStates == AgentStates::CHASE) // Es pot borrar
		AgentStates test = newState; // Es pot borrar

	if (agent->agentStates != AgentStates::NONE) ChangeState(agent, dTime, newFSMState);
}

void FSM::ChangeState(Agent* agent, float dTime, FSMState* newState)
{
	currentState->Exit(agent, dTime);

	switch (agent->agentStates)
	{
	case AgentStates::PATROL:
		newState = new FSMState_Patrol();
		break;

	case AgentStates::CHASE:
		newState = new FSMState_Chase();
		break;

	case AgentStates::EVADE:
		newState = new FSMState_Evade();
		break;

	default:
		newState = new FSMState_Patrol();
		break;
	}

	currentState = newState;

	currentState->Enter(agent, dTime);

	// Segurament necessitarem un switch aquí:
		// En cas que volguem seguir amb l'Enum que hem creat,
		// serà necessari fer un Switch per inicialitzar cada estat de la FSM correctament.

		// Si no volem fer-ho, haurem de fer includes o Forward Declaration a dins de
		// cada FSM_State (Chase, Patrol, Evade) ja que necessitarem que es coneguin per
		// poder fer un return d'un new FSM_State (del tipus que sigui necessari).
}