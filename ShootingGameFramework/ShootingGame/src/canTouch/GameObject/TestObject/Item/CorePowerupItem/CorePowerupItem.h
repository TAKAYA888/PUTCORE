#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "CorePowerupItemScript.h"

struct CorePowerupItem
{
	static void create(const Vector2& position, const Vector2& initVelocity)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto corePowerupItem = std::make_shared<GameObject>();

		// �^�O��ݒ�
		corePowerupItem->setTag(GAME_OBJECT_TAG_CORE_POWER_UP_ITEM);

		// �Q�������W
		corePowerupItem->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����̊����ړ�
		corePowerupItem->addComponent(std::make_shared<InertialMovement2D>(
			0.0f,					// ������
			initVelocity			// �������x
			));

		// ��ʊO�ɏo�������
		corePowerupItem->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �~�̓����蔻��
		corePowerupItem->addComponent(std::make_shared<CircleCollider>(
			COLLISION_GROUP_ENEMY_BULLET,	// �Փ˔���̃O���[�v
			64.0f							// �Փ˔���̔��a
			));

		// �~�̓����蔻��͈̔͂̕`��
		//corePowerupItem->addComponent(std::make_shared<CircleColliderWireFrameDrawer>(
			//DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			//Color::red				// �����蔻��͈̔͂̐F
			//));

		// �Q�����摜�̕`��
		corePowerupItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER_BULLET,	// �`�悷�郌�C���[
			IMAGE_CORE_POWER_UP_ITEM,	// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		corePowerupItem->addComponent(std::make_shared<SePlayer>(
			item_get //�T�E���h��
			));

		// �A�C�e���̃X�N���v�g
		corePowerupItem->addComponent(std::make_shared<CorePowerupItemScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(corePowerupItem);
	}
};