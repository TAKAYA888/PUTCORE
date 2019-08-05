#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "PlayerHpUiScript.h"

struct PlayerHpUi
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto playerHpUi = std::make_shared<GameObject>();

		// �Q�������W
		playerHpUi->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		playerHpUi->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			IMAGE_PLAYER_HP_GAUGE,	// �`�悷��摜��ID
			Vector2(0.0f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �v���C���[�̗̑̓o�[�̃X�N���v�g
		playerHpUi->addComponent(std::make_shared<PlayerHpUiScript>(
			10.0f					// HP�Q�[�W�̉����i���摜�̉��{���H�j
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(playerHpUi);
	}
};