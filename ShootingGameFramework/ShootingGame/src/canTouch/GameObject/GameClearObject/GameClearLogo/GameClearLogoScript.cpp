#include "GameClearLogoScript.h"

GameClearLogoScript::GameClearLogoScript()
{
}

void GameClearLogoScript::update()
{
	// ���݂̃X�P�[�����擾
	Vector2 curScaleRate = getComponent<Transform2D>().lock()->getWorldScaleRate();

	if (curScaleRate.x <= 1 && curScaleRate.y <= 1)
	{
		// �X�P�[����ς���
		curScaleRate.x += 0.02f;
		curScaleRate.y += 0.02f;

	}
	getComponent<Transform2D>().lock()->setLocalScaleRate(curScaleRate);
}

void GameClearLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_O_C)
	{
		getGameObject().lock()->destroy();
	}
}
