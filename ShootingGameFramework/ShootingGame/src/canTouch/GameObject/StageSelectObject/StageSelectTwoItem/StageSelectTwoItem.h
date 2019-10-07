#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "StageSelectTwoItemScript.h"

struct StageSelectTwoItem
{
	static void create(const Vector2& initPos)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto stageSelectTwoItem = std::make_shared<GameObject>();

		// �^�O��ݒ�
		stageSelectTwoItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// �Q�������W
		stageSelectTwoItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// ���W�i��������󂯎��j
			Vector2(1.5f, 1.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		

		// �Q�����摜�̕`��
		stageSelectTwoItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// �`�悷�郌�C���[
			IMAGE_STAGE_SELECT_TWO,		// �`�悷��摜��ID
			Vector2(0.5f, 2.0f),	// �摜�̒��S�i�����j
			0.0
			));

		// �T�E���h���Đ�����R���|�[�l���g
		stageSelectTwoItem->addComponent(std::make_shared<SePlayer>(
			INPUT_SE	// �T�E���h�̖��O
			));

		//�ǉ�
		stageSelectTwoItem->addComponent(std::make_shared<InertialMovement2D>(
			3.0f // ������
		    ));
		

		// �v���C���[�̃X�N���v�g�i�ǉ��j
		stageSelectTwoItem->addComponent(std::make_shared<StageSelectTwoItemScript>(
			32.0f	// �ړ����x
			));


		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(stageSelectTwoItem);


	}
};
