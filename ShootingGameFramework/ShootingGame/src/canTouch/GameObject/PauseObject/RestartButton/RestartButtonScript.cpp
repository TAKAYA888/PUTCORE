#include "RestartButtonScript.h"
#include "../../TestObject/Player/Player.h"
RestartButtonScript::RestartButtonScript()
{
}

void RestartButtonScript::update()
{ 
	counter++;
	if (select == 1)
	{
		if (counter % 40 == 0)
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}
		else if (counter % 40 == 20)
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(false);
		}
	}
		
	

	//if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_UP))
	//{
		//select = 1;
	//}
	//else if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_DOWN))
	//{
		//select = 2;
		//getComponent<Sprite2dDrawer>().lock()->setActive(true);
	//}

	if ( Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE)||GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1,InputType::INPUT_BEGIN,GamePadButtonType::GAME_PAD_B_BUTTON))
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