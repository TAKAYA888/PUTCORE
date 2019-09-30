#include "TitleDummyItemScript.h"

// ���t���[���Ă΂��
void TitleDummyItemScript::update()
{
	counter++;

	if (Stealth == 1)
	{
		m_curAlpha += m_increaseAlphaPerSec * TktkTime::deltaTime();

		if (m_curAlpha > 1.0f) m_curAlpha = 1.0f;

		getComponent<Sprite2dDrawer>().lock()->setBlendParam(m_curAlpha);
	}

	if (counter == 120)
	{
		Stealth = 1;
	}
}

// �ՓˊJ�n�ŌĂ΂��
void TitleDummyItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// �Փ˒��ŌĂ΂��
void TitleDummyItemScript::onCollisionStay(GameObjectPtr other)
{
}

// �ՓˏI���ŌĂ΂��
void TitleDummyItemScript::onCollisionExit(GameObjectPtr other)
{
}

void TitleDummyItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}