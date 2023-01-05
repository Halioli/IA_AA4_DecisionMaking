#pragma once
#include <vector>
#include <map>
#include "SceneElements.h"

class GOAPWorldState
{
	//std::map<SceneElements, bool> mask;

public:
	std::map<SceneElements, bool> value;

	std::map<SceneElements, bool> GetValue();
	void SetValue(std::map<SceneElements, bool> val);
	void SetValueElement(int index, bool value);
	void ClearValue();

	//std::map<SceneElements, bool> GetMask();
	//void SetMask(std::map<SceneElements, bool> val);
	//void SetMaskElement(int index, bool value);
	//void ClearMask();
};

