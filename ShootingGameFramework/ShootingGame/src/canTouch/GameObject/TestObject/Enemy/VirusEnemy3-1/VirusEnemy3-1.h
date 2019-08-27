#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "VirusEnemyScript3-1.h"

struct  VirusEnemy3_1
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto virusenemy3_1 = std::make_shared<GameObject>();

		//�^�O��ݒ�
		virusenemy3_1->setTag(GameObjectTag::GAME_OBJECT_TAG_ENEMY);

		// �Q�������W
		virusenemy3_1->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			rotationDeg				// ��]�i��������󂯎��E�x���@�j
			));

		// �Q�����̊����ړ�
		virusenemy3_1->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// ��ʊO�ɏo�������
		virusenemy3_1->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �����`�̓����蔻��
		virusenemy3_1->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// �Փ˔���̃O���[�v
			Vector2(64.0f, 64.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		virusenemy3_1->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		virusenemy3_1->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,			// �`�悷�郌�C���[
			IMAGE_VIRUS_ENEMY_ONE, 0,				// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		virusenemy3_1->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_VIRUS_ENEMY_ONE,
			0,
			4,
			0.1f,
			true
			));
		// �G�l�~�[�̃X�N���v�g
		virusenemy3_1->addComponent(std::make_shared<VirusEnemyScript3_1>());

		GameObjectManager::addGameObject(virusenemy3_1);
	}
};