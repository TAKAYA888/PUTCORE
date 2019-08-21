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

// ���b�Z�[�W��M���ɌĂ΂��
void ExplosionScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	// �󂯎�������b�Z�[�W���uENEMY_BOSS_DEAD�v��������
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
