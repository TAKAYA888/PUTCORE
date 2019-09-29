#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "ResultLogoScript.h"

struct ResultLogo
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto resultLogo = std::make_shared<GameObject>();

		// �Q�������W
		resultLogo->addComponent(std::make_shared<Transform2D>(
			0.0f,		// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		resultLogo->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_BACK_GROUND,	// �`�悷�郌�C���[
			IMAGE_RESULT_LOGO,		// �`�悷��摜��ID
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		// �^�C�g�����S�̃X�N���v�g
		resultLogo->addComponent(std::make_shared<ResultLogoScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(resultLogo);
	}
};