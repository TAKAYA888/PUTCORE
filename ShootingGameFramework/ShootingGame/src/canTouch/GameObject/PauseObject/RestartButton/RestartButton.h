#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "RestartButtonScript.h"

struct RestartButton
{
	static void create(const Vector2& initPos)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto restartbutton = std::make_shared<GameObject>();

		// �Q�������W
		restartbutton->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE / 1.5f,		// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		restartbutton->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,	// �`�悷�郌�C���[
			IMAGE_PAUSE_BACK,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// 2�����̍��W�̃N�����p�[(�ǉ�)
		restartbutton->addComponent(std::make_shared<PositionClamper>(
			Vector2(SCREEN_SIZE.x / 2, 000.0f),			// �ŏ����W
			Vector2(SCREEN_SIZE.x / 2, 500.0f)			// �ő���W
			));


		// �^�C�g�����S�̃X�N���v�g
		restartbutton->addComponent(std::make_shared<RestartButtonScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(restartbutton);
	}
};
