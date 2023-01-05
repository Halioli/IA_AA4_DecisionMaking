#include "GOAPWorldState.h"

std::map<SceneElements, bool> GOAPWorldState::GetValue()
{
	return value;
}

void GOAPWorldState::SetValue(std::map<SceneElements, bool> val)
{
	value = val;
}

void GOAPWorldState::SetValueElement(int index, bool _value)
{
	value[(SceneElements)index] = _value;
}

void GOAPWorldState::ClearValue()
{
	value.clear();
}

//std::map<SceneElements, bool> GOAPWorldState::GetMask()
//{
//	return mask;
//}
//
//void GOAPWorldState::SetMask(std::map<SceneElements, bool> val)
//{
//	mask = val;
//}
//
//void GOAPWorldState::SetMaskElement(int index, bool value)
//{
//	mask[(SceneElements)index] = value;
//}
//
//void GOAPWorldState::ClearMask()
//{
//	mask.clear();
//}
