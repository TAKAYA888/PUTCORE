#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "BossCore2Script.h"
#include "BossCore2DeadScript.h"

struct  BossCore2
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto BossCore2 = std::make_shared<GameObject>();

		//�^�O��ݒ�
		BossCore2->setTag(GameObjectTag::GAME_OBJECT_TAG_ENEMY);

		// �Q�������W
		BossCore2->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			rotationDeg				// ��]�i��������󂯎��E�x���@�j
			));

		// �Q�����̊����ړ�
		BossCore2->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// ��ʊO�ɏo�������
		BossCore2->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �����`�̓����蔻��
		BossCore2->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// �Փ˔���̃O���[�v
			Vector2(64.0f, 64.0f)	// �Փ˔���̑傫��
			));

		//// �����`�̓����蔻��͈̔͂̕`��
		//BossCore2->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
		//	Color::red				// �����蔻��͈̔͂̐F
		//	));

		// �Q�����摜�̕`��
		BossCore2->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,			// �`�悷�郌�C���[
			IMAGE_VIRUS_ENEMY_ONE, 0,				// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		BossCore2->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_VIRUS_ENEMY_ONE,
			0,
			4,
			0.1f,
			true
			));
		// �G�l�~�[�̃X�N���v�g
		BossCore2->addComponent(std::make_shared<BossCore2Script>());
		// �G�l�~�[�̃X�N���v�g
		BossCore2->addComponent(std::make_shared<BossCore2DeadScript>());

		GameObjectManager::addGameObject(BossCore2);
	}
};