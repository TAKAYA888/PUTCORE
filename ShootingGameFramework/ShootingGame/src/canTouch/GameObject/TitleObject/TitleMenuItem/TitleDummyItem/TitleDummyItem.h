#pragma once
#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "TitleDummyItemScript.h"

struct TitleDummyItem
{
	static void create(const Vector2& initPos)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto TitleDummyItem = std::make_shared<GameObject>();

		// �^�O��ݒ�
		TitleDummyItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// �Q�������W
		TitleDummyItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		TitleDummyItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// �`�悷�郌�C���[
			IMAGE_TITLE_MENU_DUMMY,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f),	// �摜�̒��S�i�����j
			0.0
			));

		// �T�E���h���Đ�����R���|�[�l���g
		TitleDummyItem->addComponent(std::make_shared<SePlayer>(
			INPUT_SE	// �T�E���h�̖��O
			));

		//�ǉ�
		TitleDummyItem->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// ������
			));

		// 2�����̍��W�̃N�����p�[(�ǉ�)
		TitleDummyItem->addComponent(std::make_shared<PositionClamper>(
			Vector2(SCREEN_SIZE.x / 2, 000.0f),			// �ŏ����W
			Vector2(SCREEN_SIZE.x / 2, 500.0f)			// �ő���W
			));

		// �Q�[���J�n�̃��j���[���ڂ̃X�N���v�g
		TitleDummyItem->addComponent(std::make_shared<TitleDummyItemScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(TitleDummyItem);
	}
};