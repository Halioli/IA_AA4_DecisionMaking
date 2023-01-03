#pragma once
#include <map>
#include "Vector2D.h"
#include "SceneGOAP.h"

class KeyElement
{
public:
	KeyElement(Vector2D _posotion, Vector2D _cellPosotion, SceneElements _keyColor) : position(_posotion), cellPosition(_cellPosotion), keyColor(_keyColor)
	{
		precondition = std::map<SceneElements, bool>();
		result = std::map<SceneElements, bool>();

		SetResultValues();
	}

	Vector2D position;
	Vector2D cellPosition;

	SceneElements keyColor;

	std::map<SceneElements, bool> precondition;
	std::map<SceneElements, bool> result;

	void CalculatePrecondition(Color colorRoom);

private:
	void SetResultValues();
};

