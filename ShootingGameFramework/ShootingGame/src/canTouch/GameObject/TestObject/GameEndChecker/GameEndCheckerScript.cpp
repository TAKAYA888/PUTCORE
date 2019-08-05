#include "GameEndCheckerScript.h"

GameEndCheckerScript::GameEndCheckerScript()
{
}

// ���t���[���Ă΂��
void GameEndCheckerScript::update()
{
	// �Q�[���I���t���O�������Ă�����
	if (m_gameEnd)
	{
		// �V�[�����؂�ւ��܂ł̃^�C�}�[���X�V
		m_sceneChangeTimer -= TktkTime::deltaTime();

		// �^�C�}�[���O�ȉ��ɂȂ�����
		if (m_sceneChangeTimer < 0.0f)
		{
			// �^�C�g���V�[���Ɉڍs����
			SceneManager::changeScene(TITLE_SCENE);
		}
		return;
	}

	// �uGAME_OBJECT_TAG_PLAYER�v�̃^�O�������Ă���Q�[���I�u�W�F�N�g��T��
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	// �Q�[���J�n���m�t���O�������Ă��Ȃ����
	if (!m_gameStart)
	{
		// �v���C���[�̑��݂��m�F�o������A�Q�[���J�n���m�t���O�𗧂Ă�
		if (!player.expired()) m_gameStart = true;

		return;
	}

	// �v���C���[��������Ȃ�������i����ł�����j
	if (player.expired())
	{
		// ���Ԃ̌o�ߑ��x��1/5�ɂ���
		TktkTime::setTimeScale(0.2f);

		// �Q�[���I���t���O�𗧂Ă�
		m_gameEnd = true;
	}

	// �{�X�����萔�|������
	if (m_bossKillCount >= m_bossKillTargetValue)
	{
		// ���Ԃ̌o�ߑ��x��1/5�ɂ���
		TktkTime::setTimeScale(0.2f);

		// �Q�[���I���t���O�𗧂Ă�
		m_gameEnd = true;
	}
}

// ���b�Z�[�W��M���ɌĂ΂��
void GameEndCheckerScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	// �󂯎�������b�Z�[�W���uENEMY_BOSS_DEAD�v��������
	if (eventMessageType == ENEMY_BOSS_DEAD)
	{
		// �{�X��|��������+1����
		m_bossKillCount++;
	}

	// �󂯎�������b�Z�[�W���uDIE_GAMEPLAY_OBJECT�v��������
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		// ���g���E��
		getGameObject().lock()->destroy();
	}
}

// �����钼�O�ɌĂ΂��
void GameEndCheckerScript::onDestroy()
{
	// ���Ԃ̌o�ߑ��x�𓙔{�ɂ���
	TktkTime::setTimeScale(1.0f);
}