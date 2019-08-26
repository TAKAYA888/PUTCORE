
#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "CoreScript.h"
#include "../setCore/setCoreScript.h"

struct Core
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto core = std::make_shared<GameObject>();

		// �^�O��ݒ�
		core->setTag(GAME_OBJECT_TAG_CORE);

		// �Q�������W
		core->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(2.0f, 2.0f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����̊����ړ�
		core->addComponent(std::make_shared<InertialMovement2D>(
			10.0f					// ������
			));

		// 2�����̍��W�̃N�����p�[
		core->addComponent(std::make_shared<PositionClamper>(
			Vector2::zero,			// �ŏ����W
			Vector2(1400.0f, 720.0f)// �ő���W		// �ő���W
			));

		core->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_CORE,	// �A�j���[�V�����Ŏg�p����摜�̎��
			0,					// �ŏ��̍����̉摜�ԍ�
			5,					// �ő�̍����̉摜�ԍ�
			2.0f,				// ���b�ԂŎ��̉摜�ɕς�邩
			true				// �A�j���[�V���������[�v�����邩�H		
			));


		// �����`�̓����蔻��
		core->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_CORE,	// �Փ˔���̃O���[�v
			Vector2(50.0f, 20.0f)	// �Փ˔���̑傫��
			));


		// �����`�̓����蔻��͈̔͂̕`��
		core->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// �`�悷�郌�C���[
			Color::red				// �����蔻��͈̔͂̐F
			));

		// �Q�����摜�̕`��
		core->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER,			// �`�悷�郌�C���[
			IMAGE_CORE,			// �`�悷��摜��ID
			0,
			Vector2(0.5f, 0.5f)		// �摜�̒��S�i�����j
			));

		// �v���C���[�̃X�N���v�g
		core->addComponent(std::make_shared<CoreScript>(
			));

		core->addComponent(std::make_shared<setCoreScript>(
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(core);
	}
};