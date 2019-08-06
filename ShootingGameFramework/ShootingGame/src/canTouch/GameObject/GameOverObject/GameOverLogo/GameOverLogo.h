#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "GameOverLogoScript.h"

struct GameOverLogo
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gameoverLogo = std::make_shared<GameObject>();

		// �Q�������W
		gameoverLogo->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE / 2.0f,		// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		gameoverLogo->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_BACK_GROUND,	// �`�悷�郌�C���[
			IMAGE_GAMEOVER_LOGO,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �^�C�g�����S�̃X�N���v�g
		gameoverLogo->addComponent(std::make_shared<GameOverLogoScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gameoverLogo);
	}
};