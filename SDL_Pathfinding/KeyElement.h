#pragma once
#include <map>
#include "Vector2D.h"
#include "SceneGOAP.h"
#include "GOAPWorldState.h"

class KeyElement
{
public:
	KeyElement(Vector2D _posotion, Vector2D _cellPosotion, SceneElements _keyColor) : position(_posotion), cellPosition(_cellPosotion), keyColor(_keyColor)
	{
		SetResultValues();
	}

	Vector2D position;
	Vector2D cellPosition;

	SceneElements keyColor;

	GOAPWorldState worldState;

	void CalculatePrecondition(Color colorRoom);

private:
	void SetResultValues();
};

