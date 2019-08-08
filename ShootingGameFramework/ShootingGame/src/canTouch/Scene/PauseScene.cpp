#include "PauseScene.h"

#include "../GameObject/PauseObject/PauseLogo/PauseLogo.h"
PauseScene::PauseScene()
{
}

void PauseScene::start()
{
	PauseLogo::create();
}

void PauseScene::update()
{
}

void PauseScene::end()
{
}
