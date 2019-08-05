#include "LoadScene.h"

#include "../GameObject/LoadObject/ImageLoadObject.h"
#include "../GameObject/LoadObject/BgmLoadObject.h"
#include "../GameObject/LoadObject/SeLoadObject.h"

LoadScene::LoadScene()
{
}

// �V�[���̊J�n���ɌĂ΂��
void LoadScene::start()
{
	// �摜�̓ǂݍ��݃N���X�𐶐��i�����͓ǂݍ��މ摜�̏���\���e�L�X�g�t�@�C���j
	ImageLoadObject::create("res/text/resourcePaths/imageResourcePaths.txt");

	// BGM�̓ǂݍ��݃N���X�𐶐��i�����͓ǂݍ���BGM�̏���\���e�L�X�g�t�@�C���j
	BgmLoadObject::create("res/text/resourcePaths/bgmResourcePaths.txt");

	// SE�̓ǂݍ��݃N���X�𐶐��i�����͓ǂݍ���SE�̏���\���e�L�X�g�t�@�C���j
	SeLoadObject::create("res/text/resourcePaths/seResourcePaths.txt");

	
}

// ���t���[���Ă΂��
void LoadScene::update()
{
	// �V�[�������C���V�[���ɕύX
	changeScene(TITLE_SCENE);
}

// �V�[���̏I�����ɌĂ΂��
void LoadScene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_GAMEPLAY_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}
