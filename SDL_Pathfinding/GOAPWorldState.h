#pragma once
#include <vector>
#include <map>
#include "SceneElements.h"

class GOAPWorldState
{
public:
	std::map<SceneElements, bool> value;
	//std::map<SceneElements, bool> mask;

	void Set(std::map<SceneElements, bool> val);
	void Clear();
};

