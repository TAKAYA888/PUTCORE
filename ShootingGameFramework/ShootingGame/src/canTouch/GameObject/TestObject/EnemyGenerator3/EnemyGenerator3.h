#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "EnemyGenerator3Script.h"

struct EnemyGenerator3
{
	static void create()
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto enemyGenerator3 = std::make_shared<GameObject>();

		// �g�p����G�̏o�����̃e�L�X�g�t�@�C���̃p�X�������ɓG�o���R���|�[�l���g��ǉ�
		enemyGenerator3->addComponent(std::make_shared<EnemyGenerator3Script>(
			"res/text/stageData/stage3.txt"
			));

		// ����̃��b�Z�[�W����M�����玩�g���E���R���|�[�l���g��ǉ�
		enemyGenerator3->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(enemyGenerator3);
	}
};
