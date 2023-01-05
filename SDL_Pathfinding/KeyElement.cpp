#include "KeyElement.h"

void KeyElement::CalculatePrecondition(Color colorRoom)
{
	switch (colorRoom)
	{
	case Red:
		worldState.SetValueElement(SceneElements::RedKey, true);
		break;

	case Orange:
		worldState.SetValueElement(SceneElements::OrangeKey, true);
		break;

	case Yellow:
		worldState.SetValueElement(SceneElements::YellowKey, true);
		break;

	case Green:
		worldState.SetValueElement(SceneElements::GreenKey, true);
		break;

	case Blue:
		worldState.SetValueElement(SceneElements::BlueKey, true);
		break;

	case Purple:
		worldState.SetValueElement(SceneElements::PurpleKey, true);
		break;

	case White:
	case Black:
	default:
		break;
	}
}

void KeyElement::SetResultValues()
{
	switch (keyColor)
	{
	case RedKey:
		//worldState.SetMaskElement(SceneElements::RedKey, true);
		worldState.SetValueElement(SceneElements::RedKey, false);
		break;

	case OrangeKey:
		//worldState.SetMaskElement(SceneElements::OrangeKey, true);
		worldState.SetValueElement(SceneElements::OrangeKey, false);
		break;

	case YellowKey:
		//worldState.SetMaskElement(SceneElements::YellowKey, true);
		worldState.SetValueElement(SceneElements::YellowKey, false);
		break;

	case GreenKey:
		//worldState.SetMaskElement(SceneElements::GreenKey, true);
		worldState.SetValueElement(SceneElements::GreenKey, false);
		break;

	case BlueKey:
		//worldState.SetMaskElement(SceneElements::BlueKey, true);
		worldState.SetValueElement(SceneElements::BlueKey, false);
		break;

	case PurpleKey:
		//worldState.SetMaskElement(SceneElements::PurpleKey, true);
		worldState.SetValueElement(SceneElements::PurpleKey, false);
		break;

	case Coin:
		//worldState.SetMaskElement(SceneElements::Coin, true);
		worldState.SetValueElement(SceneElements::Coin, false);
		break;

	case Count:
	default:
		break;
	}
}