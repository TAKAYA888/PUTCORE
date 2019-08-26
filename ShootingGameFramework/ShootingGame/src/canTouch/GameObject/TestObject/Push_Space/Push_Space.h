#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "Push_SpaceScript.h"

struct Push_Space
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto push_space = std::make_shared<GameObject>();

		// �Q�������W
		push_space->addComponent(std::make_shared<Transform2D>(
			position,		// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		push_space->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,	// �`�悷�郌�C���[
			IMAGE_PUSH_SPACE,		// �`�悷��摜��ID
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �T�E���h���Đ�����R���|�[�l���g
		push_space->addComponent(std::make_shared<SePlayer>(
			INPUT_SE 	// �T�E���h�̖��O
			));

		// �v�b�V���X�y�[�X�̃X�N���v�g
		push_space->addComponent(std::make_shared<Push_SpaceScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(push_space);
	}
};
