#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "EnemyNormalBulletScript.h"

struct EnemyNormalBullet
{
	static void create(const Vector2& position, const Vector2& initVelocity)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto enemyNormalBullet = std::make_shared<GameObject>();

		// �^�O��ݒ�
		enemyNormalBullet->setTag(GAME_OBJECT_TAG_ENEMY_BULLET);

		// �Q�������W
		enemyNormalBullet->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.2f, 0.2f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����̊����ړ�
		enemyNormalBullet->addComponent(std::make_shared<InertialMovement2D>(
			0.0f,					// ������
			initVelocity			// �������x
			));

		// ��ʊO�ɏo�������
		enemyNormalBullet->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �~�̓����蔻��
		enemyNormalBullet->addComponent(std::make_shared<CircleCollider>(
			COLLISION_GROUP_ENEMY_BULLET,	// �Փ˔���̃O���[�v
			8.0f							// �Փ˔���̔��a
			));

		// �~�̓����蔻��͈̔͂̕`��
		//enemyNormalBullet->addComponent(std::make_shared<CircleColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
		//	Color::red				// �����蔻��͈̔͂̐F
		//	));

		// �Q�����摜�̕`��
		enemyNormalBullet->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER_BULLET,	// �`�悷�郌�C���[
			IMAGE_PLAYER_BULLET,	// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �G�l�~�[�̒ʏ�e�̃X�N���v�g
		enemyNormalBullet->addComponent(std::make_shared<EnemyNormalBulletScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(enemyNormalBullet);
	}
};