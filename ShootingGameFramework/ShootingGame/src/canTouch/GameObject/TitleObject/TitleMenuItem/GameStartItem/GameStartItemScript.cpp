#include "GameStartItemScript.h"

GameStartItemScript::GameStartItemScript()
{
}

// ���t���[���Ă΂��
void GameStartItemScript::update()
{
}

// �ՓˊJ�n�ŌĂ΂��
void GameStartItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// �Փ˒��ŌĂ΂��
void GameStartItemScript::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_CURSOR�v�ŃN���b�N�J�n����������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_CURSOR
		&& Mouse::getState(InputType::INPUT_BEGIN, MouseButtonType::MOUSE_LEFT_BUTTON))
	{
		getComponent<SePlayer>().lock()->playSe();

		// ���C���V�[���ɑJ�ڂ���
		SceneManager::changeScene(MAIN_SCENE);

		
	}
}

// �ՓˏI���ŌĂ΂��
void GameStartItemScript::onCollisionExit(GameObjectPtr other)
{
}

void GameStartItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
