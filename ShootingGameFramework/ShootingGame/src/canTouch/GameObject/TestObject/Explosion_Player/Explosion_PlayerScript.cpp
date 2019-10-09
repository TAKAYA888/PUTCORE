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

// ���b�Z�[�W��M���ɌĂ΂��
void Explosion_PlayerScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	// �󂯎�������b�Z�[�W���uENEMY_BOSS_DEAD�v��������
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
