#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "zako6UpScript.h"

struct zako6Up
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto zako6up = std::make_shared<GameObject>();

		// �^�O��ݒ�
		zako6up->setTag(GameObjectTag::GAME_OBJECT_TAG_ENEMY);

		// �Q�������W
		zako6up->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			rotationDeg				// ��]�i��������󂯎��E�x���@�j
			));

		// �Q�����̊����ړ�
		zako6up->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// ��ʊO�ɏo�������
		zako6up->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �����`�̓����蔻��
		zako6up->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// �Փ˔���̃O���[�v
			Vector2(120.0f, 120.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		zako6up->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		zako6up->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,			// �`�悷�郌�C���[
			IMAGE_ZAKO6_ENEMY,
			0,						// �`�悷��摜��ID				
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		zako6up->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_ZAKO6_ENEMY,
			0,
			3,
			0.1f,
			true
			));


		// �G�l�~�[�̃X�N���v�g
		zako6up->addComponent(std::make_shared<zako6UpScript>());

		GameObjectManager::addGameObject(zako6up);
	}
};