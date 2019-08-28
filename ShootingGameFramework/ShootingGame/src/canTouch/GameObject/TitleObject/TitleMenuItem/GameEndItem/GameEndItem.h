#pragma once
#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "GameEndItemScript.h"

struct GameEndItem
{

	static void create(const Vector2& initPos)
	{


		// �Q�[���I�u�W�F�N�g���쐬
		auto gameEndItem = std::make_shared<GameObject>();

		// �^�O��ݒ�
		gameEndItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// �Q�������W
		gameEndItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �����`�̓����蔻��
		gameEndItem->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_MENU_ITEM,	// �Փ˔���̃O���[�v
			Vector2(400.0f, 100.0f)	// �Փ˔���̑傫��
			));

		// �����`�̓����蔻��͈̔͂̕`��
		//gameEndItem->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			//DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			//Color::red				// �����蔻��͈̔͂̐F
			//));

		// �Q�����摜�̕`��
		gameEndItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// �`�悷�郌�C���[
			IMAGE_TITLE_MENU_GAMEEND,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f),		// �摜�̒��S�i�����j
			0.0
			));

		// �T�E���h���Đ�����R���|�[�l���g
		gameEndItem->addComponent(std::make_shared<SePlayer>(
			INPUT_SE	// �T�E���h�̖��O
			));

		//�ǉ�
		gameEndItem->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));


		//// 2�����̍��W�̃N�����p�[(�ǉ�)
		gameEndItem->addComponent(std::make_shared<PositionClamper>(
			Vector2(SCREEN_SIZE.x / 2, 000.0f),			// �ŏ����W
			Vector2(SCREEN_SIZE.x / 2, 650.0f)			// �ő���W
			));

		// �v���C���[�̃X�N���v�g�i�ǉ��j
		gameEndItem->addComponent(std::make_shared<GameEndItemScript>(
			32.0f	// �ړ����x
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gameEndItem);

	}
};