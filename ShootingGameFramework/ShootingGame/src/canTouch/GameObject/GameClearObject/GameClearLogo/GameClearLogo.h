#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "GameClearLogoScript.h"

struct GameClearLogo
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gameClearLogo = std::make_shared<GameObject>();

		// �Q�������W
		gameClearLogo->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE / 2.0f,		// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		gameClearLogo->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_BACK_GROUND,	// �`�悷�郌�C���[
			IMAGE_CLEAR_LOGO,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �^�C�g�����S�̃X�N���v�g
		gameClearLogo->addComponent(std::make_shared<GameClearLogoScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gameClearLogo);
	}
};