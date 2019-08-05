#pragma once

#include <TktkIncludePaths.h>
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
#endif

// �摜��ǂݍ��ރQ�[���I�u�W�F�N�g
struct ImageLoadObject
{
	static void create(const std::string& loadFilePath)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto imageLoadObject = std::make_shared<GameObject>();

		// �쐬�����I�u�W�F�N�g�ɉ摜�ǂݍ��݃R���|�[�l���g��ǉ�
		imageLoadObject->addComponent(std::make_shared<TextureLoader>(loadFilePath));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(imageLoadObject);
	}
};