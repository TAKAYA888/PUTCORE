#include "StageSelectScene.h"
#include "../GameObject/StageSelectObject/StageSelectLogo/StageSelectLogo.h"
#include "../GameObject/TitleObject/TitleCursor/TitleCursor.h"
#include "../GameObject/TitleObject/TitleMenuItem/GameStartItem/GameStartItem.h"
#include "../GameObject/TitleObject/TitleMenuItem/SelectMenuItem/SelectMenuItem.h"
#include "../GameObject/TitleObject/TitleMenuItem/TitleDummyItem/TitleDummyItem.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"

StageSelectScene::StageSelectScene()
{
}

// �V�[���̊J�n���ɌĂ΂��
void StageSelectScene::start()
{
	// �^�C�g�����S�𐶐�����
	StageSelectLogo::create();

	

}

// ���t���[���Ă΂��
void StageSelectScene::update()
{
	counter++;
}

// �V�[���̏I�����ɌĂ΂��
void StageSelectScene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_TITLE_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}