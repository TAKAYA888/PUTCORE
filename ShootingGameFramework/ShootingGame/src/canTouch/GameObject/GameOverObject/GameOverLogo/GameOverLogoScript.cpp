#include "GameOverLogoScript.h"

GameOverLogoScript::GameOverLogoScript()
{
}

void GameOverLogoScript::update()
{
	// 現在のスケールを取得
	Vector2 curScaleRate = getComponent<Transform2D>().lock()->getWorldScaleRate();


	if (curScaleRate.x <= 1 && curScaleRate.y <= 1)
	{
		// スケールを変える
		curScaleRate.x += 0.005f;
		curScaleRate.y += 0.005f;

	}
	getComponent<Transform2D>().lock()->setLocalScaleRate(curScaleRate);
}

void GameOverLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
