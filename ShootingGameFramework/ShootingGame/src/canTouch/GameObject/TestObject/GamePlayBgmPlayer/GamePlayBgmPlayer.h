#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

struct GamePlayBgmPlayer
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM�Đ��R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			TEST_BGM,	// BGM�̎��
			true		// �����ɍĐ����邩�H
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}

	static void title()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM�Đ��R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			TITLE_BGM,	// 
			true		// �����ɍĐ����邩�H
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}

	static void game_1()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM�Đ��R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			GAME_BGM_1,	// 
			true		// �����ɍĐ����邩�H
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}

	static void game_2()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM�Đ��R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			GAME_BGM_2,	// 
			true		// �����ɍĐ����邩�H
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}

	static void game_3()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM�Đ��R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			GAME_BGM_3,	// 
			true		// �����ɍĐ����邩�H
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}
};