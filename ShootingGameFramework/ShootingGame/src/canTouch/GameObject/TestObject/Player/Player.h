#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "PlayerScript.h"

struct Player
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto player = std::make_shared<GameObject>();

		// �^�O��ݒ�
		player->setTag(GAME_OBJECT_TAG_PLAYER);

		// �Q�������W
		player->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����̊����ړ�
		player->addComponent(std::make_shared<InertialMovement2D>(
			100.0f					// ������
			));

		// 2�����̍��W�̃N�����p�[
		player->addComponent(std::make_shared<PositionClamper>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));


		// �~�̓����蔻��
		player->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_PLAYER,	// �Փ˔���̃O���[�v
			Vector2(32.0f, 32.0f),   // �Փ˔���̔��a
			Vector2(15, -10)
			));

		// �~�̓����蔻��͈̔͂̕`��
		player->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		player->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER,			// �`�悷�郌�C���[
			IMAGE_PLAYER,			// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �v���C���[�̃X�N���v�g
		player->addComponent(std::make_shared<PlayerScript>(
			500.0f	// �ړ����x
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(player);
	}
};