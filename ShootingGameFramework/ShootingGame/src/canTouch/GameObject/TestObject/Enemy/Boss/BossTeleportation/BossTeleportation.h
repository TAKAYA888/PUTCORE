#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "BossTeleportationScript.h"

struct BossTeleportation
{
	static void create(const Vector2& position)
	{
		//�Q�[���I�u�W�F�N�g�𐶐�
		auto bossteleportation = std::make_shared<GameObject>();

		//2�������W
		bossteleportation->addComponent(std::make_shared<Transform2D>(
			position,
			Vector2(1.0f, 1.0f),
			0.0f
			));

		//2�������W�̕`��
		bossteleportation->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_EFFECT,
			IMAGE_BOSS_TELEPORTATION,
			0,
			Vector2(0.5f, 0.5f)
			));

		//2�����摜���A�j���[�V����������R���|�[�l���g
		bossteleportation->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_BOSS_TELEPORTATION,
			0,
			4,
			0.04f,
			false
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		bossteleportation->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		//�e���|�̃X�N���v�g�𐶐�����
		bossteleportation->addComponent(std::make_shared<BossTeleportationScript>());

		//�Q�[���I�u�W�F�N�g
		GameObjectManager::addGameObject(bossteleportation);
	}
};