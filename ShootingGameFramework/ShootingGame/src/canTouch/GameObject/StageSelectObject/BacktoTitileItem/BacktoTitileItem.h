#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "BacktoTitileItemScript.h"

struct BacktoTitileItem
{
	static void create(const Vector2& initPos)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto backtoTitileItem = std::make_shared<GameObject>();

		// �^�O��ݒ�
		backtoTitileItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// �Q�������W
		backtoTitileItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �����`�̓����蔻��
		backtoTitileItem->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_MENU_ITEM,	// �Փ˔���̃O���[�v
			Vector2(400.0f, 100.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		//stageSelectOneItem->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			//DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			//Color::red				// �����蔻��͈̔͂̐F
			//));

		// �Q�����摜�̕`��
		backtoTitileItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// �`�悷�郌�C���[
			IMAGE_BACK_TO_TITLE2,		// �`�悷��摜��ID
			Vector2(0.5f, 0.7f),	// �摜�̒��S�i�����j
			0.0
			));

		// �T�E���h���Đ�����R���|�[�l���g
		backtoTitileItem->addComponent(std::make_shared<SePlayer>(
			INPUT_SE	// �T�E���h�̖��O
			));

		//�ǉ�
		backtoTitileItem->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// �Q�[���J�n�̃��j���[���ڂ̃X�N���v�g
		//stageSelectOneItem->addComponent(std::make_shared<GameStartItemScript>());

		// �v���C���[�̃X�N���v�g�i�ǉ��j
		backtoTitileItem->addComponent(std::make_shared<BacktoTitileItemScript>(
			32.0f	// �ړ����x
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(backtoTitileItem);
	}
};
