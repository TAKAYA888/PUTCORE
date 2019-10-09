#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "ModeManagerScript.h"

struct ModeManager
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto ModeManager = std::make_shared<GameObject>();

		// �Q�������W
		ModeManager->addComponent(std::make_shared<Transform2D>(
			Vector2::zero,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

	
		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(ModeManager);
	}
};