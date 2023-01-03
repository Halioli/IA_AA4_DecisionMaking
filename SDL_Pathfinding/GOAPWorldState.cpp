#include "GOAPWorldState.h"

void GOAPWorldState::Set(std::map<SceneElements, bool> val)
{
	value = val;
}

void GOAPWorldState::Clear()
{
	value.clear();
}
