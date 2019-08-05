#pragma once

#include <TktkIncludePaths.h>
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
#endif

// BGM��ǂݍ��ރQ�[���I�u�W�F�N�g
struct BgmLoadObject
{
	static void create(const std::string& loadFilePath)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto bgmLoadObject = std::make_shared<GameObject>();

		// �쐬�����I�u�W�F�N�g��BGM�ǂݍ��݃R���|�[�l���g��ǉ�
		bgmLoadObject->addComponent(std::make_shared<BgmLoader>(loadFilePath));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(bgmLoadObject);
	}
};