#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "TitleCursorScript.h"

struct TitleCursor
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto titleCursor = std::make_shared<GameObject>();

		// �^�O��ݒ�
		titleCursor->setTag(GAME_OBJECT_TAG_CURSOR);

		// �Q�������W
		titleCursor->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE / 2.0f,		// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �~�̓����蔻��
		titleCursor->addComponent(std::make_shared<CircleCollider>(
			COLLISION_GROUP_CURSOR,			// �Փ˔���̃O���[�v
			32.0f							// �Փ˔���̔��a
			));

		// �~�̓����蔻��͈̔͂̕`��
		titleCursor->addComponent(std::make_shared<CircleColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		titleCursor->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,	// �`�悷�郌�C���[
			IMAGE_TITLE_CURSOR,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �^�C�g���J�[�\���̃X�N���v�g
		titleCursor->addComponent(std::make_shared<TitleCursorScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(titleCursor);
	}
};