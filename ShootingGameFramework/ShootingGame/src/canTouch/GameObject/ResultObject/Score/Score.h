#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "ScoreScript.h"

struct Score
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto Score = std::make_shared<GameObject>();

		// �Q�������W
		Score->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE * 0.5f,		// ���W�i��������󂯎��j
			Vector2(1.5f, 1.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �^�C�g�����S�̃X�N���v�g
		Score->addComponent(std::make_shared<ScoreScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(Score);
	}
};