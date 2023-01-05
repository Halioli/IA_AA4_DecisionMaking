#pragma once
#include "GOAPWorldState.h"
#include "Agent.h"

class GOAPAction
{
	GOAPWorldState preconditions;
	GOAPWorldState effects;

	Vector2D elementPosition;
	Vector2D elementCell;

	float cost = 1.f;

public:
	std::vector<GOAPAction*> neighbourActions;

	void SetPreconditions(GOAPWorldState _preconditions);
	void SetPreconditionValue(int index, bool value);
	void SetEffect(GOAPWorldState _effect);
	void SetEffectValue(int index, bool value);
	void SetElementPosition(Vector2D _elementPosition);
	void SetElementCell(Vector2D _elementCell);
	void SetCost(float _cost);

	GOAPWorldState GetPreconditions();
	bool GetPreconditionValue(int index);
	GOAPWorldState GetEffect();
	bool GetEffectValue(int index);
	Vector2D GetElementPosition();
	Vector2D GetElementCell();
	float GetCost();

	virtual void Update(Agent* agent, float dTime);
};

