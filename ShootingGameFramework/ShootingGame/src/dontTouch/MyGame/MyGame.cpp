#include "MyGame.h"

#include <TktkMath/Random.h>
#include <TktkSceneManagement/SceneManager.h>
#include <TktkClassFuncProcessor/ClassFuncProcessor.h>
#include <TktkComponentFramework/GameObject/GameObjectManager.h>

#include <TktkDxlibWrapper/GraphicsWrapper/Graphics.h>
#include <TktkDxlibWrapper/_DxlibWrapperManager/DxlibWrapperManager.h>
#include <TktkDxlib2dWrapper/_Dxlib2dWrapperManager/Dxlib2dWrapperManager.h>
#include <TktkDxlibWrapper/InputWrapper/GamePad/GamePad.h>
#include <TktkDxlibWrapper/InputWrapper/Keyboard/Keyboard.h>

#include "../../canTouch/Utility/SceneTypeSetter.h"
#include "../../canTouch/Utility/CollisionGroupSetter.h"

#include <TktkAppend2DComponent/Transform2D.h>
#include <TktkAppend2DComponent/InertialMovement2D.h>
#include <TktkAppend2DComponent/RectCollider.h>
#include <TktkAppend2DComponent/CircleCollider.h>

#include <DxLib.h>

MyGame::MyGame(const Vector2 & initWindowSize, bool initFullScreenFlag)
	: GameLoop(initWindowSize, initFullScreenFlag)
{
}

void MyGame::initalize()
{
	SetOutApplicationLogValidFlag(FALSE);

	Random::randomize();

	Graphics::setUpDxlibScreen(
		getInitWindowSize(),
		getInitFullScreenFlag()
	);

	DxlibWrapperManager::initailize();
	Dxlib2DWrapperManager::initailize();

	SceneManager::initialize();
	SceneTypeSetter::set();

	GamePad::setGamePadCount(1);

	GameObjectManager::initialize();

	CollisionGroupSetter::set();

	ClassFuncProcessor::addUpdatePriority<GameObject>(-1000.0f);

	ClassFuncProcessor::addUpdatePriority<InertialMovement2D>(1000.0f);
	ClassFuncProcessor::addUpdatePriority<Transform2D>(1010.0f);
	ClassFuncProcessor::addUpdatePriority<RectCollider>(1020.0f);
	ClassFuncProcessor::addUpdatePriority<CircleCollider>(1020.0f);
}

void MyGame::start()
{
}

void MyGame::update()
{
	DxlibWrapperManager::update();

	SceneManager::update();

	ClassFuncProcessor::update();

	GameObjectManager::updateGameObjectList();

	if (ProcessMessage() != 0) MyGame::exitGame();

	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_ESCAPE)) MyGame::exitGame();

	Graphics::clearScreen();
}

void MyGame::draw()
{
	ClassFuncProcessor::draw();
}

void MyGame::frameEnd()
{
	Graphics::flipScreen();
}

void MyGame::end()
{
}

void MyGame::finalize()
{
	SceneManager::finalize();
	ClassFuncProcessor::finalize();

	DxlibWrapperManager::finalize();
	Dxlib2DWrapperManager::finalize();

	Graphics::deleteDxlibScreen();
}
