#include "StageSelectLogoScript.h"

StageSelectLogoScript::StageSelectLogoScript()
{
}

void StageSelectLogoScript::update()
{
	m_curAlpha += m_increaseAlphaPerSec * TktkTime::deltaTime();

	if (m_curAlpha > 1.0f) m_curAlpha = 1.0f;

	getComponent<Sprite2dDrawer>().lock()->setBlendParam(m_curAlpha);
}

void StageSelectLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
