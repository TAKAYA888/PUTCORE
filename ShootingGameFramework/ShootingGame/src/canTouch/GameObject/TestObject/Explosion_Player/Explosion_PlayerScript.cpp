#include "Explosion_PlayerScript.h"

Explosion_PlayerScript::Explosion_PlayerScript()
{
}

void Explosion_PlayerScript::start()
{
	getComponent<SePlayer>().lock()->playSe();
}

void Explosion_PlayerScript::update()
{
	m_explosionTimer += TktkTime::deltaTime();

	if (m_explosionTimer > m_deleteTimeSec)
	{
		getGameObject().lock()->destroy();
	}
}

// メッセージ受信時に呼ばれる
void Explosion_PlayerScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	// 受け取ったメッセージが「ENEMY_BOSS_DEAD」だったら
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
