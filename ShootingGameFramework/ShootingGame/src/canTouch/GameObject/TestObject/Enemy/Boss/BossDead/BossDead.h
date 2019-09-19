#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "BossDeadScript.h"

struct BossDead
{
	static void create(const Vector2& position)
	{
		//�Q�[���I�u�W�F�N�g�𐶐�
		auto bossDead = std::make_shared<GameObject>();

		//2�������W
		bossDead->addComponent(std::make_shared<Transform2D>(
			position,
			Vector2(2.0f, 2.0f),
			0.0f
			));

		//2�������W�̕`��
		bossDead->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_EFFECT,
			IMAGE_BOSS_DEAD,
			0,
			Vector2(0.5f, 0.5f)
			));

		//2�����摜���A�j���[�V����������R���|�[�l���g
		bossDead->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_BOSS_DEAD,
			0,
			4,
			0.4f,
			false
			));

		//�e���|�̃X�N���v�g�𐶐�����
		bossDead->addComponent(std::make_shared<BossDeadScript>());

		//�Q�[���I�u�W�F�N�g
		GameObjectManager::addGameObject(bossDead);
	};
};