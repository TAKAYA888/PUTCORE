#include "BossScript.h"

#include "../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "BossTeleportation/BossTeleportation.h"
#include "BossDead/BossDead.h"

BossScript::BossScript()
{
	timer = 0;
	counter = 0;
	teleportionCounter = true;
}

void BossScript::update()
{
	//�J�E���g�A�b�v�@�ړ��Ɣ��˂̃^�C�~���O
	timer += TktkTime::deltaTime();
	//�����X�e�[�^�X�����ʂȂ�
	if (m_curState == State::normal)
	{
		//���˂ƈړ��̏��������ă^�C�}�[�̃��Z�b�g
		if (timer > 1.94f && teleportionCounter)
		{
			BossTeleportation::create(getComponent<Transform2D>().lock()->getWorldPosition());
			teleportionCounter = false;
		}
		else if (timer > 2.0f)
		{
			Shot();

			move();

			timer = 0;

			teleportionCounter = true;
		}

		//����HP��50�����������
		if (m_hp <= 50)
		{
			//�A�j���[�V�����̃R���|�[�l���g���I�t�ɂ���
			getComponent<AnimatedSprite2d>().lock()->setActive(false);
			//�C�⎞�̉摜�ɍ����ւ���
			getComponent<Sprite2dDrawer>().lock()->setSpriteId(IMAGE_ENEMY_BOSS_FAINT);
			//�^�C�}�[�����Z�b�g����
			timer = 0;
			counter = 0;
			//�X�e�[�^�X�����|���傤�����ɂ���
			changeState(faint);
		}
	}
	//�����X�e�[�^�X�����|�Ȃ�
	else if (m_curState == State::faint)
	{
		//�����^�C�}�[��2�b�ȏ�o�߂�����
		if (timer > 2.0f)
		{
			//�X�e�[�^�X��{���Ԃɂ���
			changeState(angry);
			//�A�j���̃R���|�[�l���g���I���ɂ���
			getComponent<AnimatedSprite2d>().lock()->setActive(true);
			//�`���ID��BOSS1�ɂ��ǂ��@�@�K�v���킩��Ȃ��̂ł���Ȃ����Ȃ�����Ă����Ȃ�
			getComponent<Sprite2dDrawer>().lock()->setSpriteId(IMAGE_ENEMY_BOSS_1);
		}
	}
	else if (m_curState == State::angry)
	{
		//�����J�E���^�[��3�ȉ��Ȃ�
		if (counter < 3.0f)
		{
			//�����^�C�}�[����b�ȏ�Ȃ�
			if (timer > 0.96f && teleportionCounter)
			{
				BossTeleportation::create(getComponent<Transform2D>().lock()->getWorldPosition());
				teleportionCounter = false;
			}
			if (timer > 1.0f)
			{
				Shot();

				move();

				timer = 0;
				//�J�E���g�A�b�v
				counter += 1;

				teleportionCounter = true;
			}

		}
		//3�ȏ�Ȃ�
		else
		{
			if (timer > 2.96f && teleportionCounter)
			{
				BossTeleportation::create(getComponent<Transform2D>().lock()->getWorldPosition());
				teleportionCounter = false;
			}
			else if (timer > 3)
			{
				Shot();

				move();

				timer = 0;
				//�J�E���^�[���Z�b�g
				counter = 0;
				teleportionCounter = true;
			}
		}
	}

	if (m_hp <= 0)
	{
		////�Q�[���N���A�V�[���Ɉڍs����
		//SceneManager::changeScene(CLEAR_SCENE);
		BossDead::create(getComponent<Transform2D>().lock()->getWorldPosition());
		changeState(dying);
		// �������E��
		getGameObject().lock()->destroy();
	}
}

void BossScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET || other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
	}

	//�Փˑ���̃^�O���uGAME_OBJECT_TAG_CORE�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-10����
		m_hp -= 10;
	}

	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
	}
}

void BossScript::onCollisionStay(GameObjectPtr other)
{
}

void BossScript::onCollisionExit(GameObjectPtr other)
{
}

void BossScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//�����Q�[���v���C�I�u�W�F�N�g�����˂Ƃ���ꂽ��
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		//���̃R���|�[�l���g������
		getGameObject().lock()->destroy();
	}
}

void BossScript::onDestroy()
{
	GameObjectManager::sendMessage(DIE_BOSS1_DEAD);
}

//�X�e�[�^�X�̕ύX���s��
void BossScript::changeState(State nextState)
{
	m_curState = nextState;
}

void BossScript::move()
{
	//x��500�A1100�̊ԂŃ����_���Ɉړ�����
	float x = Random::getRandF(500, 1100);
	//y��128�A600�̊ԂŃ����_���Ɉړ�����
	float y = Random::getRandF(128, 600);

	getComponent<Transform2D>().lock()->setLocalPosition(Vector2(x, y));
}

void BossScript::Shot()
{
	// �e�̏o�����W
	Vector2 spawnPos = getComponent<Transform2D>().lock()->getWorldPosition();

	//�e�̃X�|�[���ʒu�����炷
	spawnPos;
	spawnPos.x = spawnPos.x - 45.0f;
	spawnPos.y = spawnPos.y + 15.0f;

	for (float i = 0; i < 12; i++)
	{
		// ���g�̉�]�p�x
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// �e�̏������x
		auto initVelocity = Vector2(MathHelper::sin(30.0f * i), MathHelper::cos(30.0f * i)) * 512.0f;

		// �G�̒ʏ�e���o��
		EnemyNormalBullet::create(spawnPos, initVelocity);
	}
}