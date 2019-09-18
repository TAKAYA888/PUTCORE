#include "MainScene.h"

#include "../GameObject/TestObject/Core/StayCore/Core.h"
#include "../GameObject/TestObject/BackGround/BackGround1/BackGround_1.h"
#include "../GameObject/PauseObject/PauseLogo/PauseLogo.h"
#include "../GameObject/PauseObject/RestartButton/RestartButton.h"
#include "../GameObject/TestObject/Player/Player.h"
#include "../GameObject/TestObject/EnemyGenerator/EnemyGenerator.h"
#include "../GameObject/TestObject/PlayerHpUi/PlayerHpUi.h"
#include "../GameObject/TestObject/GameEndChecker/GameEndChecker.h"

#include "../GameObject/TestObject/AnimSample/AnimSample.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"
#include "../GameObject/ResultObject/Score/Score.h"
#include "../GameObject/MainObject/Score_screen.h"


MainScene::MainScene()
{
}

// �V�[���̊J�n���ɌĂ΂��
void MainScene::start()
{
	//�w�i�P�𐶐�����
	BackGround_1::create(SCREEN_SIZE/2);
	BackGround_1::create(Vector2(1920, 360));

	// �v���C���[�𐶐�����
	Player::create(SCREEN_SIZE / 2);

	//�R�A�𐶐�����
	Core::create(SCREEN_SIZE / 2);

	// �v���C���[��HP�Q�[�W�𐶐�����
	PlayerHpUi::create(Vector2(10.0f, SCREEN_SIZE_Y - 20.0f));

	// �G�l�~�[�W�F�l���[�^�[�𐶐�����
	EnemyGenerator::create();

	// �Q�[���I�������𔻒肷��N���X�𐶐�����
	GameEndChecker::create();

	// �A�j���[�V�����T���v���𐶐�
	AnimSample::create(Vector2(SCREEN_SIZE.x / 2, 32.0f));

	// �Q�[���v���C�p��BGM�v���C���[�𐶐�
	GamePlayBgmPlayer::create();

	// �X�R�A�𐶐�
	Score::create();


	// �X�R�A�\�����𐶐�
	float Complement = 2.0f; // �����Ԃ̌���

	float x = 0.0f;
	float Crack = 128.0f / 10.0f + Complement;
	
	// ������1�i���ꂩ������for�ɕς��Ă��������΁j
	Score_Screen_1::create(Vector2(x, 0.0f));
	x += Crack;
	//Score_Screen_2::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_3::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_4::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_5::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_6::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_7::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_8::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_9::create(Vector2(x, 0.0f));
}

// ���t���[���Ă΂��
void MainScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_TAB))
	{
		float TimeScale = 0.0f;
		TimeScale = TktkTime::getTimeScale();
		if (TimeScale >= 0.9f) 
		{
			//GameObjectManager::findGameObjectWithTag(AKITA_BANZAI).lock()->getComponent<BackGround_1Script>().lock()->setActive(false);
			// ���Ԃ̌o�ߑ��x��0�ɂ���
			TktkTime::setTimeScale(0.0f);
			// PlayerScript�𖳌���
			GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<PlayerScript>().lock()->setActive(false);
			

			//�|�[�Y��ʂ��N���G�C�g����
			RestartButton::create(SCREEN_SIZE.x / 1);
			PauseLogo::create();
		}
		else 
		{
			//�|�[�Y�I���̃A�i�E���X
			GameObjectManager::sendMessage(PAUSE_END);
			// ���Ԃ̌o�ߑ��x��1�ɂ���
			GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<PlayerScript>().lock()->setActive(true);
			// PlayerScript��L����
			TktkTime::setTimeScale(1.0f);
			//BG��I�����I
			//GameObjectManager::findGameObjectWithTag(AKITA_BANZAI).lock()->getComponent<BackGround_1Script>().lock()->setActive(true);
		}
	}
}

// �V�[���̏I�����ɌĂ΂��
void MainScene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_GAMEPLAY_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}
