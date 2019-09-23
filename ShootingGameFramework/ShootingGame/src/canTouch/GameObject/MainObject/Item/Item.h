#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "ItemScript.h"

struct Item
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto item  = std::make_shared<GameObject>();

		// �^�O��ݒ�
		item->setTag(GameObjectTag::GAME_OBJECT_TAG_ITEM);

		// �Q�������W
		item->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			rotationDeg				// ��]�i��������󂯎��E�x���@�j
			));

		// �Q�����̊����ړ�
		item->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// ��ʊO�ɏo�������
		item->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// �ŏ����W
			SCREEN_SIZE				// �ő���W
			));

		// �����`�̓����蔻��
		item->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ITEM,	// �Փ˔���̃O���[�v
			Vector2(32.0f, 32.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		item->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		item->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,			// �`�悷�郌�C���[
			IMAGE_ENEMY,				// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));
		
		// �G�l�~�[�̃X�N���v�g
		item->addComponent(std::make_shared<ItemScript>());

		GameObjectManager::addGameObject(item);
	}
};