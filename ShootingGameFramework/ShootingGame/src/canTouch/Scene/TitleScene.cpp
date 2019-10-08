#include "TitleScene.h"

#include "../GameObject/TitleObject/TitleLogo/TitleLogo.h"
#include "../GameObject/TitleObject/TitleCursor/TitleCursor.h"
#include "../GameObject/TitleObject/TitleMenuItem/GameStartItem/GameStartItem.h"
#include "../GameObject/TitleObject/TitleMenuItem/SelectMenuItem/SelectMenuItem.h"
#include "../GameObject/TitleObject/TitleMenuItem/TitleDummyItem/TitleDummyItem.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"

TitleScene::TitleScene()
{
}

// �V�[���̊J�n���ɌĂ΂��
void TitleScene::start()
{
	// �^�C�g�����S�𐶐�����
	TitleLogo::create();

	// �^�C�g���J�[�\���𐶐�����
	TitleCursor::create();

	// �^�C�g�����j���[�̃Q�[���J�n���ڂ𐶐�����
	GameStartItem::create(Vector2(SCREEN_SIZE.x / 2, 000.0f));

	//�X�e�[�W�Z���N�g�{�^���𐶐�
	SelectMenuItem::create(Vector2(SCREEN_SIZE.x / 2, 000.0f));

	// �^�C�g���p��BGM�v���C���[�𐶐�
	GamePlayBgmPlayer::title();
}

// ���t���[���Ă΂��
void TitleScene::update()
{
	counter++;
}

// �V�[���̏I�����ɌĂ΂��
void TitleScene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_TITLE_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}