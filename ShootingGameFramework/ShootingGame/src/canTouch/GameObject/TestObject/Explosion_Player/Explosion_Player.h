#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "Explosion_PlayerScript.h"

struct Explosion_Player
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto explosion_player = std::make_shared<GameObject>();

		// �Q�������W
		explosion_player->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		explosion_player->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_EFFECT,			// �`�悷�郌�C���[
			IMAGE_PLAYER_DAMAGE,		// �`�悷��摜��ID
			0,						// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �Q�����摜���A�j���[�V����������R���|�[�l���g
		explosion_player->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_PLAYER_DAMAGE,	// �A�j���[�V�����Ŏg�p����摜�̎��
			0,					// �ŏ��̍����̉摜�ԍ�
			7,					// �ő�̍����̉摜�ԍ�
			0.1f,				// ���b�ԂŎ��̉摜�ɕς�邩
			false				// �A�j���[�V���������[�v�����邩�H
			));

		// �T�E���h���Đ�����R���|�[�l���g
		explosion_player->addComponent(std::make_shared<SePlayer>(
			enemy_damage 	// �T�E���h�̖��O
			));

		// �����̃X�N���v�g�𐶐�����
		explosion_player->addComponent(std::make_shared<Explosion_PlayerScript>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(explosion_player);
	}
};