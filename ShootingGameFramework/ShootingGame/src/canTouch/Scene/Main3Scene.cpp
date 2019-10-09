#include "Main3Scene.h"

#include "../GameObject/TestObject/Core/StayCore/Core.h"
#include "../GameObject/TestObject/BackGround/BackGround3/BackGround_3.h"
#include "../GameObject/PauseObject/PauseLogo/PauseLogo.h"
#include "../GameObject/PauseObject/RestartButton/RestartButton.h"
#include "../GameObject/TestObject/Player/Player.h"
#include "../GameObject/TestObject/EnemyGenerator3/EnemyGenerator3.h"
#include "../GameObject/TestObject/PlayerHpUi/PlayerHpUi.h"
#include "../GameObject/TestObject/GameEndChecker/GameEndChecker.h"

#include "../GameObject/TestObject/AnimSample/AnimSample.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"
#include "../GameObject/ResultObject/Score/Score.h"
#include "../GameObject/MainObject/Score_Screen/Score_screen.h"



Main3Scene::Main3Scene()
{
}

// �V�[���̊J�n���ɌĂ΂��
void Main3Scene::start()
{
	//�w�i2�𐶐�����
	BackGround_3::create(Vector2(-10,0));
	BackGround_3::create(Vector2(SCREEN_SIZE_X/2, 0));
	BackGround_3::create(Vector2(SCREEN_SIZE_X, 0));

	// �v���C���[�𐶐�����
	Player::create(SCREEN_SIZE / 2);

	//�R�A�𐶐�����
	Core::create(SCREEN_SIZE / 2);

	// �v���C���[��HP�Q�[�W�𐶐�����
	PlayerHpUi::create(Vector2(20.0f, SCREEN_SIZE_Y - 30.0f));

	// �G�l�~�[�W�F�l���[�^�[�𐶐�����
	EnemyGenerator3::create();

	// �Q�[���I�������𔻒肷��N���X�𐶐�����
	GameEndChecker::create();

	// �Q�[���v���C�p��BGM�v���C���[�𐶐�
	GamePlayBgmPlayer::create();

	// �X�R�A�𐶐�
	Score::create();
}

// ���t���[���Ă΂��
void Main3Scene::update()
{
	// �X�R�A�\�����𐶐�
	float Complement = 30.0f; // �����Ԃ̌���

	float x = 0.0f;
	float Crack = 128.0f / 10.0f + Complement;
	Score_Screen_1::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_2::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_3::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_4::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_5::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_6::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_7::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_8::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_9::create(Vector2(x, 0.0f));

	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_TAB) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_START_BUTTON))
	{
		float TimeScale = 0.0f;
		TimeScale = TktkTime::getTimeScale();
		if (TimeScale >= 0.9f)
		{
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
		}
	}
}

// �V�[���̏I�����ɌĂ΂��
void Main3Scene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_GAMEPLAY_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}
