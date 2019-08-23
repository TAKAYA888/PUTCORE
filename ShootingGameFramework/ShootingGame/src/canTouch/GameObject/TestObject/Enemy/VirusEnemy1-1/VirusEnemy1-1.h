#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "VirusEnemyScript1-1.h"

struct VirusEnemy1_1
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto virusenemy1_1 = std::make_shared<GameObject>();

		// �^�O��ݒ�
		virusenemy1_1->setTag(GameObjectTag::GAME_OBJECT_TAG_VIRYS_ENEMY1);

		// �Q�������W
		virusenemy1_1->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			rotationDeg				// ��]�i��������󂯎��E�x���@�j
			));

		// �Q�����̊����ړ�
		virusenemy1_1->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// ��ʊO�ɏo�������
		virusenemy1_1->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �����`�̓����蔻��
		virusenemy1_1->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// �Փ˔���̃O���[�v
			Vector2(64.0f, 64.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		virusenemy1_1->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		virusenemy1_1->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,			// �`�悷�郌�C���[
			IMAGE_VIRUS_ENEMY_TWO,0,						// �`�悷��摜��ID				
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		virusenemy1_1->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_VIRUS_ENEMY_TWO,
			0,
			4,
			0.1f,
			true
			));


		// �G�l�~�[�̃X�N���v�g
		virusenemy1_1->addComponent(std::make_shared<VirusEnemyScript1_1>());

		GameObjectManager::addGameObject(virusenemy1_1);
	}
};