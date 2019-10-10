#include"SelectStageScene.h"

#include "../GameObject/StageSelectObject/StageSelectLogo/StageSelectLogo.h"
#include "../GameObject/StageSelectObject/StageSelectOneItem/StageSelectOneItem.h"
#include "../GameObject/StageSelectObject/StageSelectTwoItem/StageSelectTwoItem.h"
#include "../GameObject/StageSelectObject/StageSelectThreeItem/StageSelectThreeItem.h"
#include "../GameObject/StageSelectObject/BacktoTitileItem/BacktoTitileItem.h"





SelectStageScene::SelectStageScene()
{

}

// �V�[���̊J�n���ɌĂ΂��
void SelectStageScene::start()
{
	//�w�i�`���̎莆�`����Ł[���邠�Ȃ��́[��
	StageSelectLogo::create();

	//�X�e�[�W�P�̃{�^��
	StageSelectOneItem::create(Vector2(SCREEN_SIZE.x / 5, 700.0f));

	//�X�e�[�W�Q�̉��O
	StageSelectTwoItem::create(Vector2(SCREEN_SIZE.x / 2, 700.0f));

	//�X�e�[�W�R�̖t
	StageSelectThreeItem::create(Vector2(SCREEN_SIZE.x / 1,800.0f));	

	//�^�C�g���ɖ߂�{�^��
	BacktoTitileItem::create(Vector2(SCREEN_SIZE.x / 2,500.0f));

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