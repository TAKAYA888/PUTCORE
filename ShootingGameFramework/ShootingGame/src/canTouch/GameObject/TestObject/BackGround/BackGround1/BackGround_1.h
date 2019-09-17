#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "BackGround_1Script.h"

struct BackGround_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto background_1 = std::make_shared<GameObject>();

		// �^�O��ݒ�
		background_1->setTag(AKITA_BANZAI);

		// �Q�������W
		background_1->addComponent(std::make_shared<Transform2D>(
			position,		// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		background_1->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_BACK_GROUND,	// �`�悷�郌�C���[
			IMAGE_PLAY_BG,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �^�C�g�����S�̃X�N���v�g
		background_1->addComponent(std::make_shared<BackGround_1Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(background_1);
	}
};
