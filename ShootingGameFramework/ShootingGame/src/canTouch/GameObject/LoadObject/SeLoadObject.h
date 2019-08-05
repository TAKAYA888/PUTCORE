#pragma once

#include <TktkIncludePaths.h>
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
#endif

// SE��ǂݍ��ރQ�[���I�u�W�F�N�g
struct SeLoadObject
{
	static void create(const std::string& loadFilePath)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto seLoadObject = std::make_shared<GameObject>();

		// �쐬�����I�u�W�F�N�g��SE�ǂݍ��݃R���|�[�l���g��ǉ�
		seLoadObject->addComponent(std::make_shared<SeLoader>(loadFilePath));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(seLoadObject);
	}
};