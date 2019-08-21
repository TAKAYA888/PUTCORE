#include "MainScene.h"

#include "../GameObject/TestObject/BackGround/BackGround1/BackGround_1.h"
#include "../GameObject/TestObject/Player/Player.h"
#include "../GameObject/TestObject/EnemyGenerator/EnemyGenerator.h"
#include "../GameObject/TestObject/PlayerHpUi/PlayerHpUi.h"
#include "../GameObject/TestObject/GameEndChecker/GameEndChecker.h"

#include "../GameObject/TestObject/AnimSample/AnimSample.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"

MainScene::MainScene()
{
}

// �V�[���̊J�n���ɌĂ΂��
void MainScene::start()
{
	//�w�i�P�𐶐�����
	BackGround_1::create();

	// �v���C���[�𐶐�����
	Player::create(SCREEN_SIZE / 2);

	// �v���C���[��HP�Q�[�W�𐶐�����
	PlayerHpUi::create(Vector2(10.0f, 10.0f));

	// �G�l�~�[�W�F�l���[�^�[�𐶐�����
	EnemyGenerator::create();

	// �Q�[���I�������𔻒肷��N���X�𐶐�����
	GameEndChecker::create();

	// �A�j���[�V�����T���v���𐶐�
	AnimSample::create(Vector2(SCREEN_SIZE.x / 2, 32.0f));

	// �Q�[���v���C�p��BGM�v���C���[�𐶐�
	GamePlayBgmPlayer::create();
}

// ���t���[���Ă΂��
void MainScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_TAB))
	{
		changeScene(PAUSE_SCENE);
	}
}

// �V�[���̏I�����ɌĂ΂��
void MainScene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_GAMEPLAY_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}
