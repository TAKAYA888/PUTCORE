#include "GameStartItemScript.h"

GameStartItemScript::GameStartItemScript()
{
}

// 毎フレーム呼ばれる
void GameStartItemScript::update()
{
}

// 衝突開始で呼ばれる
void GameStartItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// 衝突中で呼ばれる
void GameStartItemScript::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_CURSOR」でクリック開始時だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_CURSOR
		&& Mouse::getState(InputType::INPUT_BEGIN, MouseButtonType::MOUSE_LEFT_BUTTON))
	{
		getComponent<SePlayer>().lock()->playSe();

		// メインシーンに遷移する
		SceneManager::changeScene(MAIN_SCENE);

		
	}
}

// 衝突終了で呼ばれる
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
