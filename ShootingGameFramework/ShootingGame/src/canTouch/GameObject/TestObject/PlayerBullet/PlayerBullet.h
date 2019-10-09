#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "PlayerBulletScript.h"

struct PlayerBullet
{
	static void create(const Vector2& position, const Vector2& initVelocity)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto playerBullet = std::make_shared<GameObject>();

		// �^�O��ݒ�
		playerBullet->setTag(GAME_OBJECT_TAG_PLAYER_BULLET);

		// �Q�������W
		playerBullet->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.2f, 0.2f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����̊����ړ�
		playerBullet->addComponent(std::make_shared<InertialMovement2D>(
			0.0f,					// ������
			initVelocity			// �������x
			));

		// ��ʊO�ɏo�������
		playerBullet->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �~�̓����蔻��
		playerBullet->addComponent(std::make_shared<CircleCollider>(
			COLLISION_GROUP_PLAYER_BULLET,	// �Փ˔���̃O���[�v
			8.0f							// �Փ˔���̔��a
			));

		// �~�̓����蔻��͈̔͂̕`��
		//playerBullet->addComponent(std::make_shared<CircleColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
		//	Color::red				// �����蔻��͈̔͂̐F
		//	));

		// �Q�����摜�̕`��
		playerBullet->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER_BULLET,	// �`�悷�郌�C���[
			IMAGE_PLAYER_BULLET,	// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �v���C���[�̒e�̃X�N���v�g
		playerBullet->addComponent(std::make_shared<PlayerBulletScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(playerBullet);
	}
};