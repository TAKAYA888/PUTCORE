#include "setCoreScript.h"

#include "../StayCore/CoreScript.h"
#include "../../../TestObject/PlayerBullet/PlayerBullet.h"
#include "../../../TestObject/CoreBullet/CoreBullet.h"
#include "../../Player/PlayerScript.h"

#include "../../Explosion/Explosion.h"

#include <iostream>


setCoreScript::setCoreScript()
{
	counter = 0;
	coolTime = 0.5f;
	Power_counter = 0;
}

void setCoreScript::update()
{
	bool curActiveFlag = getComponent<CoreScript>().lock()->isActive();
	Vector2 Postion = getComponent<Transform2D>().lock()->getWorldPosition();

	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	Power_counter = player.lock()->getComponent<PlayerScript>().lock()->PowerupCounter;

	counter += TktkTime::deltaTime();

	if (curActiveFlag)
	{
		getComponent<setCoreScript>().lock()->setActive(false);
	}

	//�����蔻���t����
	getComponent<RectCollider>().lock()->setActive(true);
	//�����蔻���`��t����
	//getComponent<RectColliderWireFrameDrawer>().lock()->setActive(true);

	if (counter >= 5)
	{
		//�ړ����鏈��	
		// �ړ����x�{����
		auto velocity = Vector2(MathHelper::sin(90), MathHelper::cos(90)) * 100.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
		//�A�j���[�V�������~�߂�
		getComponent<AnimatedSprite2d>().lock()->setAnimSpeedRate(0);
	}
	else
	{
		if (coolTime < 0)
		{
			if (Power_counter == 0)
			{
				// �e�̏������x
				auto initVelocity1 = Vector2(MathHelper::sin(90), -MathHelper::cos(90)) * 512.0f;
				auto initVelocity2 = Vector2(MathHelper::sin(70), -MathHelper::cos(70)) * 512.0f;
				auto initVelocity3 = Vector2(MathHelper::sin(110), -MathHelper::cos(110)) * 512.0f;
				CoreBullet::create(Postion, initVelocity1);
				CoreBullet::create(Postion, initVelocity2);
				CoreBullet::create(Postion, initVelocity3);
			}
			else if (Power_counter == 1)
			{
				// �e�̏������x
				auto initVelocity1 = Vector2(MathHelper::sin(90), -MathHelper::cos(90)) * 512.0f;
				auto initVelocity2 = Vector2(MathHelper::sin(70), -MathHelper::cos(70)) * 512.0f;
				auto initVelocity3 = Vector2(MathHelper::sin(110), -MathHelper::cos(110)) * 512.0f;
				auto initVelocity4 = Vector2(MathHelper::sin(50), -MathHelper::cos(50)) * 512.0f;
				auto initVelocity5 = Vector2(MathHelper::sin(130), -MathHelper::cos(130)) * 512.0f;
				CoreBullet::create(Postion, initVelocity1);
				CoreBullet::create(Postion, initVelocity2);
				CoreBullet::create(Postion, initVelocity3);
				CoreBullet::create(Postion, initVelocity4);
				CoreBullet::create(Postion, initVelocity5);
			}
			else if (Power_counter == 2)
			{
				// �e�̏������x
				auto initVelocity1 = Vector2(MathHelper::sin(90), -MathHelper::cos(90)) * 512.0f;
				auto initVelocity2 = Vector2(MathHelper::sin(70), -MathHelper::cos(70)) * 512.0f;
				auto initVelocity3 = Vector2(MathHelper::sin(110), -MathHelper::cos(110)) * 512.0f;
				auto initVelocity4 = Vector2(MathHelper::sin(50), -MathHelper::cos(50)) * 512.0f;
				auto initVelocity5 = Vector2(MathHelper::sin(130), -MathHelper::cos(130)) * 512.0f;
				auto initVelocity6 = Vector2(MathHelper::sin(30), -MathHelper::cos(30)) * 512.0f;
				auto initVelocity7 = Vector2(MathHelper::sin(150), -MathHelper::cos(150)) * 512.0f;
				CoreBullet::create(Postion, initVelocity1);
				CoreBullet::create(Postion, initVelocity2);
				CoreBullet::create(Postion, initVelocity3);
				CoreBullet::create(Postion, initVelocity4);
				CoreBullet::create(Postion, initVelocity5);
				CoreBullet::create(Postion, initVelocity6);
				CoreBullet::create(Postion, initVelocity7);
			}
			else if (Power_counter >= 3)
			{
				// �e�̏������x
				auto initVelocity1 = Vector2(MathHelper::sin(90), -MathHelper::cos(90)) * 512.0f;
				auto initVelocity2 = Vector2(MathHelper::sin(70), -MathHelper::cos(70)) * 512.0f;
				auto initVelocity3 = Vector2(MathHelper::sin(110), -MathHelper::cos(110)) * 512.0f;
				auto initVelocity4 = Vector2(MathHelper::sin(50), -MathHelper::cos(50)) * 512.0f;
				auto initVelocity5 = Vector2(MathHelper::sin(130), -MathHelper::cos(130)) * 512.0f;
				auto initVelocity6 = Vector2(MathHelper::sin(30), -MathHelper::cos(30)) * 512.0f;
				auto initVelocity7 = Vector2(MathHelper::sin(150), -MathHelper::cos(150)) * 512.0f;
				CoreBullet::create(Postion, initVelocity1);
				CoreBullet::create(Postion, initVelocity2);
				CoreBullet::create(Postion, initVelocity3);
				CoreBullet::create(Postion, initVelocity4);
				CoreBullet::create(Postion, initVelocity5);
				CoreBullet::create(Postion, initVelocity6);
				CoreBullet::create(Postion, initVelocity7);

				/*add_core_bullet++;*/
			}
			coolTime += 0.5f;
		}
		else
		{
			coolTime -= TktkTime::deltaTime();
		}
		getComponent<AnimatedSprite2d>().lock()->setAnimSpeedRate(-2);
	}


	//��ʊO�ɂł����������	
	if (Postion.x > 1400)
	{
		getGameObject().lock()->destroy();
		counter = 0;
	}
}

void setCoreScript::onCollisionEnter(GameObjectPtr other)
{
	std::cout << other.lock()->getTag();

	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_ENEMY_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BULLET || other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY || other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BOSS)
	{
		// �����𐶐�����
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		getGameObject().lock()->destroy();
		counter = 0;
	}
}

void setCoreScript::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_ENEMY_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BULLET || other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY || other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BOSS)
	{
		// �����𐶐�����
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		getComponent<CoreScript>().lock()->setActive(true);
		counter = 0;
	}
}

void setCoreScript::onCollisionExit(GameObjectPtr other)
{
}

void setCoreScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

void setCoreScript::onDestroy()
{
	//���񂾂Ƃ��ɂ��̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_CORE);
}
