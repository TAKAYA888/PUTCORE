#include"SelectStageScene.h"

#include "../GameObject/StageSelectObject/StageSelectLogo/StageSelectLogo.h"

SelectStageScene::SelectStageScene()
{

}

// �V�[���̊J�n���ɌĂ΂��
void SelectStageScene::start()
{
	StageSelectLogo::create();
	

}

// ���t���[���Ă΂��
void SelectStageScene::update()
{
	counter++;
}

// �V�[���̏I�����ɌĂ΂��
void SelectStageScene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_TITLE_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}