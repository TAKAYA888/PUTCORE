#include "Explosion_EnemyScript.h"

Explosion_EnemyScript::Explosion_EnemyScript()
{
}

void Explosion_EnemyScript::start()
{
	getComponent<SePlayer>().lock()->playSe();
}

void Explosion_EnemyScript::update()
{
	m_explosionTimer += TktkTime::deltaTime();

	if (m_explosionTimer > m_deleteTimeSec)
	{
		getGameObject().lock()->destroy();
	}
}

void Explosion_EnemyScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
