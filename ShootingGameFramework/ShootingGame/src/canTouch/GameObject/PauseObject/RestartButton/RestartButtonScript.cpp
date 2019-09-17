#include "RestartButtonScript.h"
#include "../../TestObject/Player/Player.h"
RestartButtonScript::RestartButtonScript()
{
}

void RestartButtonScript::update()
{
	Move();
}
//	’Ç‰Á
void RestartButtonScript::Move()
{
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE))
	{
		GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->destroy();
		GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
		GameObjectManager::sendMessage(PAUSE_END);
		SceneManager::changeScene(TITLE_SCENE);
	}
}

void RestartButtonScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == PAUSE_END)
	{
		getGameObject().lock()->destroy();
	}
}