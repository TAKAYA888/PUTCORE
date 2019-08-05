#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

struct AnimSample
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto animSample = std::make_shared<GameObject>();

		// �Q�������W
		animSample->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(1.0f, 1.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		animSample->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER,			// �`�悷�郌�C���[
			IMAGE_ANIM_SAMPLE,		// �`�悷��摜��ID
			0,						// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// 
		animSample->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_ANIM_SAMPLE,	// �A�j���[�V�����Ŏg�p����摜�̎��
			0,					// �ŏ��̍����̉摜�ԍ�
			3,					// �ő�̍����̉摜�ԍ�
			0.1f,				// ���b�ԂŎ��̉摜�ɕς�邩
			true				// �A�j���[�V���������[�v�����邩�H
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		animSample->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(animSample);
	}
};