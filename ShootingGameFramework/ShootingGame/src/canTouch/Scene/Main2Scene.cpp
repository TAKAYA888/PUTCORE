#include "Main2Scene.h"

#include "../GameObject/TestObject/Core/StayCore/Core.h"
#include "../GameObject/TestObject/BackGround/BackGround2/BackGround_2.h"
#include "../GameObject/PauseObject/PauseLogo/PauseLogo.h"
#include "../GameObject/PauseObject/RestartButton/RestartButton.h"
#include "../GameObject/TestObject/Player/Player.h"
#include "../GameObject/TestObject/EnemyGenerator2/EnemyGenerator2.h"
#include "../GameObject/TestObject/PlayerHpUi/PlayerHpUi.h"
#include "../GameObject/TestObject/GameEndChecker/GameEndChecker.h"

#include "../GameObject/TestObject/AnimSample/AnimSample.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"



Main2Scene::Main2Scene()
{
}

// �V�[���̊J�n���ɌĂ΂��
void Main2Scene::start()
{
	//�w�i2�𐶐�����
	BackGround_2::create(Vector2::zero);
	BackGround_2::create(Vector2(SCREEN_SIZE_X, 0));

	// �v���C���[�𐶐�����
	Player::create(SCREEN_SIZE / 2);

	//�R�A�𐶐�����
	Core::create(SCREEN_SIZE / 2);

	// �v���C���[��HP�Q�[�W�𐶐�����
	PlayerHpUi::create(Vector2(20.0f, SCREEN_SIZE_Y - 30.0f));

	// �G�l�~�[�W�F�l���[�^�[�𐶐�����
	EnemyGenerator2::create();

	// �Q�[���I�������𔻒肷��N���X�𐶐�����
	GameEndChecker::create();

	// �A�j���[�V�����T���v���𐶐�
	AnimSample::create(Vector2(SCREEN_SIZE.x / 2, 32.0f));

	// �Q�[���v���C�p��BGM�v���C���[�𐶐�
	GamePlayBgmPlayer::create();


}

// ���t���[���Ă΂��
void Main2Scene::update()
{
	

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
void Main2Scene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_GAMEPLAY_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}
