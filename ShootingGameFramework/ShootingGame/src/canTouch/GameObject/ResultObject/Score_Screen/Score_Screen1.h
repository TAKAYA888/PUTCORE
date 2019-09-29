#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"

#include "Score_Screen_Script1.h"
#include "../Score/ScoreScript.h"

#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

//MainScene�̃X�R�A�\�����i������1�j

float size = 0.8f; // �����T�C�Y

struct Score_Screen_1_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size, size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(1),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_2_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size , size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(2),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_3_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size, size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(3),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_4_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size, size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(4),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_5_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size, size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(5),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_6_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size, size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(6),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_7_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size, size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(7),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_8_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size, size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(8),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_9_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(size, size),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(9),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));
		
		//����̃��b�Z�[�W����M�����玩�M���E���R���|�[�l���g��ǉ�
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

