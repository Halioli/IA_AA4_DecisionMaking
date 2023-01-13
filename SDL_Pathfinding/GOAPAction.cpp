#include "GOAPAction.h"

void GOAPAction::SetPreconditions(GOAPWorldState _precondition)
{
	preconditions = _precondition;
}

void GOAPAction::SetPreconditionValue(int index, bool value)
{
	// TODO
	preconditions.SetValueElement(index, value);
}

void GOAPAction::SetEffect(GOAPWorldState _effect)
{
	effects = _effect;
}

void GOAPAction::SetEffectValue(int index, bool value)
{
	// TODO
	effects.SetValueElement(index, value);
}

void GOAPAction::SetElementPosition(Vector2D _elementPosition)
{
	elementPosition = _elementPosition;
}

void GOAPAction::SetElementCell(Vector2D _elementCell)
{
	elementCell = _elementCell;
}

void GOAPAction::SetCost(float _cost)
{
	cost = _cost;
}

/*GOAPWorldState GOAPAction::GetPreconditions()
{
	return preconditions;
}*/

bool GOAPAction::GetPreconditionValue(int index)
{
	return preconditions.GetValue().find((SceneElements)index)->second; // find() retorna una pair, i el second de la pair és un bool
}

/*GOAPWorldState GOAPAction::GetEffect()
{
	return effects;
}*/

bool GOAPAction::GetEffectValue(int index)
{
	return effects.GetValue().find((SceneElements)index)->second;
}

/*Vector2D GOAPAction::GetElementPosition()
{
	return elementPosition;
}

Vector2D GOAPAction::GetElementCell()
{
	return elementCell;
}

float GOAPAction::GetCost()
{
	return cost;
}*/

void GOAPAction::Update(Agent* agent, float dTime)
{
	// TODO
}
