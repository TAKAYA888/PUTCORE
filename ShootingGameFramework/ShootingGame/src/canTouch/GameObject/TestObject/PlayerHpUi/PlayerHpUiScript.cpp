#include "PlayerHpUiScript.h"

#include "../Player/PlayerScript.h"

PlayerHpUiScript::PlayerHpUiScript(float hpGaugeWidth)
	: m_hpGaugeWidth(hpGaugeWidth)
{
}

void PlayerHpUiScript::update()
{
	// �ő�HP�ƌ��݂�HP�̔䗦���擾
	float playerHpRate = calculateHpRate();

	// �����̃g�����X�t�H�[��2D���擾
	auto transform2D = getComponent<Transform2D>();

	// ���g��x�����̃X�P�[�����uHP�̔䗦*�Q�[�W�̒����v�ɂ���
	transform2D.lock()->setLocalScaleRate(Vector2(playerHpRate * m_hpGaugeWidth, 1.0f));
}

void PlayerHpUiScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

// �ő�HP�ƌ��݂�HP�̔䗦���v�Z����
float PlayerHpUiScript::calculateHpRate()
{
	// �v���C���[�̃|�C���^���󂾂�����
	if (m_player.expired())
	{
		// �v���C���[�̃^�O�������Ă���Q�[���I�u�W�F�N�g���擾
		m_player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

		// �擾�ł��Ȃ����0.0f��Ԃ�
		if (m_player.expired()) return 0.0f;
	}

	// �v���C���[����v���C���[�X�N���v�g���擾
	auto playerScript = m_player.lock()->getComponent<PlayerScript>();

	// �擾�ł��Ȃ����0.0f��Ԃ�
	if (playerScript.expired()) return 0.0f;

	// �ő�HP�ƌ��݂�HP�̊�����Ԃ�
	return static_cast<float>(playerScript.lock()->getCurHp()) / playerScript.lock()->getMaxHp();
}
