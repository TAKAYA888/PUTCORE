#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "BackGround_2Script.h"

struct BackGround_2
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto background_2 = std::make_shared<GameObject>();

		// �^�O��ݒ�
		background_2->setTag(AKITA_BANZAI);

		// �Q�������W
		background_2->addComponent(std::make_shared<Transform2D>(
			position,		// ���W�i��������󂯎��j
			Vector2(1.5f, 1.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		background_2->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_BACK_GROUND,	// �`�悷�郌�C���[
			IMAGE_PLAY_BG2,		// �`�悷��摜��ID
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		// �^�C�g�����S�̃X�N���v�g
		background_2->addComponent(std::make_shared<BackGround_2Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(background_2);
	}
};

