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
