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
		// �������E��
		getGameObject().lock()->destroy();
	}
}

void BossDeadScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
}

void BossDeadScript::onDestroy()
{
	//�Q�[���N���A�V�[���Ɉڍs����
	SceneManager::changeScene(CLEAR_SCENE);
}
