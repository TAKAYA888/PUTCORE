#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "Boss3Script.h"

struct Boss3
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto Boss3 = std::make_shared<GameObject>();

		// �^�O��ݒ�
		Boss3->setTag(GameObjectTag::GAME_OBJECT_TAG_ENEMY);

		// �Q�������W
		Boss3->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(2.0f, 2.0f),	// �X�P�[���i�{���j
			rotationDeg				// ��]�i��������󂯎��E�x���@�j
			));

		// �Q�����̊����ړ�
		Boss3->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));



		// �����`�̓����蔻��
		Boss3->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// �Փ˔���̃O���[�v
			Vector2(128.0f, 128.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		Boss3->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		Boss3->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,// �`�悷�郌�C���[
			IMAGE_BOSS_DEAD,
			1,						// �`�悷��摜��ID				
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));



		// �G�l�~�[�̃X�N���v�g
		Boss3->addComponent(std::make_shared<Boss3Script>());

		GameObjectManager::addGameObject(Boss3);
	}
};