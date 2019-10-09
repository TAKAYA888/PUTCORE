#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "VirusEnemyScript5.h"

struct VirusEnemy5
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto virusenemy5 = std::make_shared<GameObject>();

		// �^�O��ݒ�
		virusenemy5->setTag(GameObjectTag::GAME_OBJECT_TAG_ENEMY);

		// �Q�������W
		virusenemy5->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			rotationDeg				// ��]�i��������󂯎��E�x���@�j
			));

		// �Q�����̊����ړ�
		virusenemy5->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// ��ʊO�ɏo�������
		virusenemy5->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �����`�̓����蔻��
		virusenemy5->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// �Փ˔���̃O���[�v
			Vector2(64.0f, 64.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		//virusenemy5->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
		//	Color::red				// �����蔻��͈̔͂̐F
		//	));

		// �Q�����摜�̕`��
		virusenemy5->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,			// �`�悷�郌�C���[
			IMAGE_VIRUS_ENEMY_ONE, 0,				// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		virusenemy5->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_VIRUS_ENEMY_ONE,
			0,
			4,
			0.1f,
			true
			));

		// �T�E���h���Đ�����R���|�[�l���g
		virusenemy5->addComponent(std::make_shared<SePlayer>(
			enemy_bullet 	// �T�E���h�̖��O
			));

		// �G�l�~�[�̃X�N���v�g
		virusenemy5->addComponent(std::make_shared<VirusEnemyScript5>());

		GameObjectManager::addGameObject(virusenemy5);

	}
};