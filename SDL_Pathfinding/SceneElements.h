#pragma once
#include <map>
#include "Vector2D.h"
#include "SceneGOAP.h"

enum Color { White = 0, Black, Red, Orange, Yellow, Green, Blue, Purple };

enum SceneElements { 
	WhiteKey = 0, 
	BlackKey, 
	RedKey, 
	OrangeKey, 
	Yellowkey, 
	GreenKey, 
	BlueKey, 
	PurpleKey, 
	Coin,
	Count
};

class SceneElement
{
public:
	Vector2D position;
	Vector2D cellPosition;

	std::map<SceneElements, bool> precondition;
	std::map<SceneElements, bool> result;

	void CalculatePrecondition(Color colorRoom);
};
