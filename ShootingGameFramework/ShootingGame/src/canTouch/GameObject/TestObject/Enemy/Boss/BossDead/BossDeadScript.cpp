#include "BossDeadScript.h"

BossDeadScript::BossDeadScript()
{
	timer = 0;
}

void BossDeadScript::update()
{
	timer += TktkTime::deltaTime();
	if (timer > 2.6f)
	{
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

void BossDeadScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
}

void BossDeadScript::onDestroy()
{
	//ゲームクリアシーンに移行する
	SceneManager::changeScene(CLEAR_SCENE);
}
