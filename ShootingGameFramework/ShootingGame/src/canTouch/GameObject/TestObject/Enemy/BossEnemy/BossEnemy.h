#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "BossEnemyScript.h"

struct BossEnemy
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto bossEnemy = std::make_shared<GameObject>();

		// �^�O��ݒ�
		bossEnemy->setTag(GameObjectTag::GAME_OBJECT_TAG_ENEMY_BOSS);

		// �Q�������W
		bossEnemy->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			rotationDeg				// ��]�i��������󂯎��E�x���@�j
			));

		// �Q�����̊����ړ�
		bossEnemy->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// �����`�̓����蔻��
		bossEnemy->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// �Փ˔���̃O���[�v
			Vector2(128.0f, 128.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		//bossEnemy->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
		//	Color::red				// �����蔻��͈̔͂̐F
		//	));

		// �Q�����摜�̕`��
		bossEnemy->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY_BOSS,		// �`�悷�郌�C���[
			IMAGE_ENEMY_BOSS,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �{�X�̃X�N���v�g
		bossEnemy->addComponent(std::make_shared<BossEnemyScript>());

		GameObjectManager::addGameObject(bossEnemy);
	}
};