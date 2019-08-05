#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "GameStartItemScript.h"

struct GameStartItem
{
	static void create(const Vector2& initPos)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gameStartItem = std::make_shared<GameObject>();

		// �^�O��ݒ�
		gameStartItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// �Q�������W
		gameStartItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �����`�̓����蔻��
		gameStartItem->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_MENU_ITEM,	// �Փ˔���̃O���[�v
			Vector2(640.0f, 128.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		gameStartItem->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		gameStartItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// �`�悷�郌�C���[
			IMAGE_TITLE_MENU_GAMESTART,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �Q�[���J�n�̃��j���[���ڂ̃X�N���v�g
		gameStartItem->addComponent(std::make_shared<GameStartItemScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gameStartItem);
	}
};