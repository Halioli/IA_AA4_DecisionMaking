#include "KeyElement.h"

void KeyElement::CalculatePrecondition(Color colorRoom)
{
	switch (colorRoom)
	{
	case Red:
		precondition[SceneElements::RedKey] = true;
		break;

	case Orange:
		precondition[SceneElements::OrangeKey] = true;
		break;

	case Yellow:
		precondition[SceneElements::YellowKey] = true;
		break;

	case Green:
		precondition[SceneElements::GreenKey] = true;
		break;

	case Blue:
		precondition[SceneElements::BlueKey] = true;
		break;

	case Purple:
		precondition[SceneElements::PurpleKey] = true;
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
		result[SceneElements::RedKey] = true;
		precondition[SceneElements::RedKey] = false;
		break;

	case OrangeKey:
		result[SceneElements::OrangeKey] = true;
		precondition[SceneElements::OrangeKey] = false;
		break;

	case YellowKey:
		result[SceneElements::YellowKey] = true;
		precondition[SceneElements::YellowKey] = false;
		break;

	case GreenKey:
		result[SceneElements::GreenKey] = true;
		precondition[SceneElements::GreenKey] = false;
		break;

	case BlueKey:
		result[SceneElements::BlueKey] = true;
		precondition[SceneElements::BlueKey] = false;
		break;

	case PurpleKey:
		result[SceneElements::PurpleKey] = true;
		precondition[SceneElements::PurpleKey] = false;
		break;

	case Coin:
		result[SceneElements::Coin] = true;
		precondition[SceneElements::Coin] = false;
		break;

	case Count:
	default:
		break;
	}
}