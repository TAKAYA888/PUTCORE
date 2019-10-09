#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "EnemyGenerator2Script.h"

struct EnemyGenerator2
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto enemyGenerator2 = std::make_shared<GameObject>();

		// �g�p����G�̏o�����̃e�L�X�g�t�@�C���̃p�X�������ɓG�o���R���|�[�l���g��ǉ�
		enemyGenerator2->addComponent(std::make_shared<EnemyGenerator2Script>(
			"res/text/stageData/stage2.txt"
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		enemyGenerator2->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(enemyGenerator2);
	}
};