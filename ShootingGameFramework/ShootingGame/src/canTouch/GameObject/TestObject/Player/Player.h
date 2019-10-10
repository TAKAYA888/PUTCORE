
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

		// 2�����̍��W�̃N�����p�[
		player->addComponent(std::make_shared<PositionClamper>(
			Vector2(95, 60),			// �ŏ����W
			Vector2(SCREEN_SIZE_X - 70.0f, SCREEN_SIZE_Y - 80.0f)				// �ő���W
			));

		// �Q�������W
		player->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.5f, 1.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����̊����ړ�
		player->addComponent(std::make_shared<InertialMovement2D>(
			10.0f					// ������
			));

		// �~�̓����蔻��
		player->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_PLAYER,	// �Փ˔���̃O���[�v
			Vector2(30.0f, 25.0f),   // �Փ˔���̔��a
			Vector2(20, 5)
			));

		// �~�̓����蔻��͈̔͂̕`��
		//player->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
		//	Color::red				// �����蔻��͈̔͂̐F
		//	));

		// �Q�����摜�̕`��
		player->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER,			// �`�悷�郌�C���[
			IMAGE_PLAYER,			// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		player->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_PLAYER,	// �A�j���[�V�����Ŏg�p����摜�̎��
			0,					// �ŏ��̍����̉摜�ԍ�
			5,					// �ő�̍����̉摜�ԍ�
			0.01f,				// ���b�ԂŎ��̉摜�ɕς�邩
			true				// �A�j���[�V���������[�v�����邩�H
			));

		// �T�E���h���Đ�����R���|�[�l���g
		player->addComponent(std::make_shared<SePlayer>(
			INPUT_SE 	// �T�E���h�̖��O
			));

		// �v���C���[�̃X�N���v�g
		player->addComponent(std::make_shared<PlayerScript>(
			50.0f	// �ړ����x
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		player->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(player);
	}
};