#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "GameEndCheckerScript.h"

struct GameEndChecker
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gameEndChecker = std::make_shared<GameObject>();

		// �Q�[���I���`�F�b�J�[�̃X�N���v�g
		gameEndChecker->addComponent(std::make_shared<GameEndCheckerScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gameEndChecker);
	}
};