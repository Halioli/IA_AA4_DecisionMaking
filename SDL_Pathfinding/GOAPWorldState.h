#pragma once
#include <vector>

class GOAPWorldState
{
	std::vector<bool> value;
	std::vector<bool> mask;

	void Set(std::vector<bool> val);
	void Clear();
};

