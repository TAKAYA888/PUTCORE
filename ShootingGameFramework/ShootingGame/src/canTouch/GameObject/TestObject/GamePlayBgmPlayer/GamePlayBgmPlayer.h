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
};