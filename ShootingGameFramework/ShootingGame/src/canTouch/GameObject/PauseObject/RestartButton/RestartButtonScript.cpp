#include "RestartButtonScript.h"

RestartButtonScript::RestartButtonScript()
{
}

void RestartButtonScript::update()
{
	Move();

	counter++;

	if (count % 2 == 0)
	{

		getComponent<Sprite2dDrawer>().lock()->setActive(false);
		select = 0;

	}
	else
	{
		getComponent<Sprite2dDrawer>().lock()->setActive(true);
		select = 1;
	}


	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_TAB))
	{
		count = count + 1;
		select = 1;
	}


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

	if (select == 3)
	{


		if (counter % 5 == 0)
		{

			getComponent<Sprite2dDrawer>().lock()->setActive(false);

		}
		else if (counter % 10 == 1)
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}


	}



}
//	’Ç‰Á
void RestartButtonScript::Move()
{


	if (select == 1 && Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE))
	{
		//getComponent<SePlayer>().lock()->playSe();



		count = count + 1;




		GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->destroy();
		SceneManager::changeScene(TITLE_SCENE);




	}


}



void RestartButtonScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
