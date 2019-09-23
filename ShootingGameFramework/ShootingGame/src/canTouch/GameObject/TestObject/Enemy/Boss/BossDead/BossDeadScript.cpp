#include "BossDeadScript.h"
#include "../BossTeleportation/BossTeleportation.h"

BossDeadScript::BossDeadScript()
{
	timer = 0;
}

void BossDeadScript::update()
{
	Vector2 Pos = getComponent<Transform2D>().lock()->getWorldPosition();
	int randomX = Random::getRandI(-200, 200);
	int randomY = Random::getRandI(-200, 200);
	Vector2 spawnPos;
	spawnPos.x = Pos.x + randomX;
	spawnPos.y = Pos.y + randomY;
	timer += TktkTime::deltaTime();
	if (timer > 3)
	{
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
	else
	{
		BossTeleportation::create(spawnPos);
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
