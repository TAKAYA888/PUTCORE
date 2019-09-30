#include "Boss3Script.h"
#include "../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"
#include "../../Enemy/Boss/BossTeleportation/BossTeleportation.h"
#include "../../Enemy/zako6/zako6Up/zako6Up.h"
#include "../../Enemy/zako6/zako6Down/zako6Down.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../Enemy/Boss/BossDead/BossDead.h"

Boss3Script::Boss3Script()
{
	timer = 0;
	//�v���C���[�̍��W���󂯎��
	Vector2 playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
	//�v���C���[���������Ă���
	PlayerFrag = true;
	//�ˌ����邩�ǂ�����
	ShotFrag1 = true;
	ShotFrag2 = true;
}

void Boss3Script::update()
{
	//�J�E���g�A�b�v
	timer += TktkTime::deltaTime();

	if (ActionCounter < 4)
	{
		if (timer > 1 && ShotFrag1)
		{
			Shot1();

			ShotFrag1 = false;
		}
		else if (timer > 1.5 && ShotFrag2)
		{
			Shot2();

			ShotFrag2 = false;
		}
		else if (timer > 3)
		{
			ActionCounter++;

			//���Z�b�g
			ShotFrag1 = true;
			ShotFrag2 = true;

			Move();

			timer = 0;
		}
	}
	else
	{
		if (timer > 1 && EnemyFrag[0])
		{
			zako6Up::create(Vector2(600, 700), 0);
			zako6Down::create(Vector2(400, 0), 0);
			EnemyFrag[0] = false;
		}
		else if (timer > 1.5&&EnemyFrag[1])
		{
			zako6Up::create(Vector2(600, 700), 0);
			zako6Down::create(Vector2(400, 0), 0);
			EnemyFrag[1] = false;
		}
		else if (timer > 2 && EnemyFrag[2])
		{
			zako6Up::create(Vector2(600, 700), 0);
			zako6Down::create(Vector2(400, 0), 0);
			EnemyFrag[2] = false;
		}
		else if (timer > 4.5 && EnemyFrag2[0])
		{
			zako6Up::create(Vector2(400, 700), 0);
			zako6Down::create(Vector2(600, 0), 0);
			EnemyFrag2[0] = false;
		}
		else if (timer > 5 && EnemyFrag2[1])
		{
			zako6Up::create(Vector2(400, 700), 0);
			zako6Down::create(Vector2(600, 0), 0);
			EnemyFrag2[1] = false;
		}
		else if (timer > 5.5 && EnemyFrag2[2])
		{
			zako6Up::create(Vector2(400, 700), 0);
			zako6Down::create(Vector2(600, 0), 0);
			EnemyFrag2[2] = false;
		}
		else if (timer > 8 && EnemyFrag3[0])
		{
			zako6Up::create(Vector2(500, 700), 0);
			zako6Down::create(Vector2(300, 0), 0);
			EnemyFrag3[0] = false;
		}
		else if (timer > 8.5 && EnemyFrag3[1])
		{
			zako6Up::create(Vector2(500, 700), 0);
			zako6Down::create(Vector2(300, 0), 0);
			EnemyFrag3[1] = false;
		}
		else if (timer > 9 && EnemyFrag3[2])
		{
			zako6Up::create(Vector2(500, 700), 0);
			zako6Down::create(Vector2(300, 0), 0);
			EnemyFrag3[2] = false;
		}
		else if (timer > 11.5&&EnemyFrag4[0])
		{
			zako6Up::create(Vector2(300, 700), 0);
			zako6Down::create(Vector2(500, 0), 0);
			EnemyFrag4[0] = false;
		}
		else if (timer > 12 && EnemyFrag4[1])
		{
			zako6Up::create(Vector2(300, 700), 0);
			zako6Down::create(Vector2(500, 0), 0);
			EnemyFrag4[1] = false;
		}
		else if (timer > 12.5&&EnemyFrag4[2])
		{
			zako6Up::create(Vector2(300, 700), 0);
			zako6Down::create(Vector2(500, 0), 0);
			EnemyFrag4[2] = false;
		}
		else if (timer > 13)
		{
			//���Z�b�g
			ActionCounter = 0;
			for (size_t i = 0; i < 3; i++)
			{
				EnemyFrag[i] = true;
				EnemyFrag2[i] = true;
				EnemyFrag3[i] = true;
				EnemyFrag4[i] = true;
			}
			timer = 0;
		}
	}

	//����Hp��0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		BossDead::create(getComponent<Transform2D>().lock()->getWorldPosition());
		GameObjectManager::sendMessage(DIE_BOSS3_DEAD);
		// �������E��
		getGameObject().lock()->destroy();
	}
}

void Boss3Script::onCollisionEnter(GameObjectPtr other)
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

void Boss3Script::onCollisionStay(GameObjectPtr other)
{
}

void Boss3Script::onCollisionExit(GameObjectPtr other)
{
}

void Boss3Script::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//�v���C���[�����񂾂�t���O��ς���
	if (eventMessageType == DIE_PLAYER)
	{
		PlayerFrag = false;
	}

	//�����Q�[���v���C�I�u�W�F�N�g�����˂Ƃ���ꂽ��
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		//���̃R���|�[�l���g������
		getGameObject().lock()->destroy();
	}
}

void Boss3Script::onDestroy()
{
}

void Boss3Script::Shot1()
{
	//���g�̈ʒu���擾����
	Vector2 Boss3Pos = getComponent<Transform2D>().lock()->getWorldPosition();

	if (PlayerFrag)
	{
		// �v���C���[�̈ʒu���擾
		playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
	}

	// �u�v���C���[�v->�u�G�l�~�[�v�̃x�N�g�������߂�
	auto enemyToMouse = playerPos - Boss3Pos;

	// �Q�̃x�N�g���̊O�ς����߂�
	float cross = Vector2::cross(enemyToMouse, Vector2::down);

	// �Q�̃x�N�g���̓��ς����߂�
	float dot = Vector2::dot(enemyToMouse, Vector2::down);

	// �t�^���W�F���g���g���Č��������p�x�����߂�
	float result = MathHelper::atan(cross, dot);

	for (size_t i = 0; i < 5; i++)
	{
		// �e�̏������x
		auto initVelocity = Vector2(MathHelper::sin(result + shotAngle1[i] + 180), MathHelper::cos(result + shotAngle1[i] + 180)) * 512.0f;

		EnemyNormalBullet::create(Boss3Pos, initVelocity);
	}
}

void Boss3Script::Shot2()
{
	//���g�̈ʒu���擾����
	Vector2 Boss3Pos = getComponent<Transform2D>().lock()->getWorldPosition();

	if (PlayerFrag)
	{
		// �v���C���[�̈ʒu���擾
		playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
	}

	// �u�v���C���[�v->�u�G�l�~�[�v�̃x�N�g�������߂�
	auto enemyToMouse = playerPos - Boss3Pos;

	// �Q�̃x�N�g���̊O�ς����߂�
	float cross = Vector2::cross(enemyToMouse, Vector2::down);

	// �Q�̃x�N�g���̓��ς����߂�
	float dot = Vector2::dot(enemyToMouse, Vector2::down);

	// �t�^���W�F���g���g���Č��������p�x�����߂�
	float result = MathHelper::atan(cross, dot);

	for (size_t i = 0; i < 4; i++)
	{
		// �e�̏������x
		auto initVelocity = Vector2(MathHelper::sin(result + shotAngle2[i] + 180), MathHelper::cos(result + shotAngle2[i] + 180)) * 512.0f;

		//�ˏo
		EnemyNormalBullet::create(Boss3Pos, initVelocity);
	}
}

void Boss3Script::Move()
{
	//x��500�A1100�̊ԂŃ����_���Ɉړ�����
	float x = Random::getRandF(600, 1280);
	//y��128�A600�̊ԂŃ����_���Ɉړ�����
	float y = Random::getRandF(0, 760);

	//�e���|�̃G�t�F�N�g�𐶐�
	BossTeleportation::create(Vector2(x, y));

	//�e���|
	getComponent<Transform2D>().lock()->setLocalPosition(Vector2(x, y));
}