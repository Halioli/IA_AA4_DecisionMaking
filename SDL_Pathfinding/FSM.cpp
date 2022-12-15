#include "FSM.h"

void FSM::Update(Agent* agent, float dTime, Vector2D _randomPos) 
{
	AgentStates newState; // Valorar què fem?
	FSMState* newFSMState = currentState->Update(agent, dTime, _randomPos, &newState); // Valorar què fem?
	
	if (newState != AgentStates::NONE) ChangeState(agent, dTime, newFSMState); // Valorar què fem?
	//						^
}

void FSM::ChangeState(Agent* agent, float dTime, FSMState* newState)
{
	currentState->Exit(agent, dTime);
	currentState = newState;
	currentState->Enter(agent, dTime);

	// Segurament necessitarem un switch aquí:
		// En cas que volguem seguir amb l'Enum que hem creat,
		// serà necessari fer un Switch per inicialitzar cada estat de la FSM correctament.

		// Si no volem fer-ho, haurem de fer includes o Forward Declaration a dins de
		// cada FSM_State (Chase, Patrol, Evade) ja que necessitarem que es coneguin per
		// poder fer un return d'un new FSM_State (del tipus que sigui necessari).
}