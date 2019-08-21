#include "ExplosionScript.h"

ExplosionScript::ExplosionScript()
{
}

void ExplosionScript::start()
{
	getComponent<SePlayer>().lock()->playSe();
}

void ExplosionScript::update()
{
	m_explosionTimer += TktkTime::deltaTime();

	if (m_explosionTimer > m_deleteTimeSec)
	{
		getGameObject().lock()->destroy();
	}
}

// メッセージ受信時に呼ばれる
void ExplosionScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	// 受け取ったメッセージが「ENEMY_BOSS_DEAD」だったら
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
