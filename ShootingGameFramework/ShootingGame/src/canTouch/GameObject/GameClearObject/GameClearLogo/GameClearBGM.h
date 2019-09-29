#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

struct GameClearBGM
{
	static void create()
	{
		//�Q�[���I�u�W�F�N�g���쐬
		auto gameClearBgm = std::make_shared<GameObject>();

		//BGM�R���|�[�l���g��ǉ�
		gameClearBgm->addComponent(std::make_shared<BgmPlayer>(
			GAMECLEAR_BGM,
			true
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		gameClearBgm->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_O_C
			));

		//�Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(gameClearBgm);
	}
};