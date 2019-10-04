#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"

#include "Score_Screen_Script.h"
#include "../../ResultObject/Score/ScoreScript.h"

#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

//MainScene�̃X�R�A�\�����i������1�j

float baritu = 0.5f;

struct Score_Screen_1
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(1),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_2
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(2),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_3
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(3),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_4
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(4),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_5
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(5),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_6
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(6),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_7
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(7),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_8
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(8),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_9
{
	static void create(const Vector2& position)
	{
		// �Q�[���I�u�W�F�N�g���쐬
		auto scoreScreen = std::make_shared<GameObject>();

		// �Q�������W
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// ���W�i��������󂯎��j
			Vector2(0.5f, 0.5f),	// �X�P�[���i�{���j
			0.0f					// ��]�i�x���@�j
			));

		// �Q�����摜�̕`��
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// �`�悷�郌�C���[
			SCORE_NUMBER,		// �`�悷��摜��ID
			ScoreScript::Score_Screen_Number(9),	// ���ォ�猩�ĉ��Ԗڂ̈ʒu�̉摜��\�����邩
			Vector2(0.0f, 0.0f)		// �摜�̒��S�i�����j
			));

		scoreScreen->addComponent(std::make_shared<Score_Screen_Script>());

		// �Q�[���I�u�W�F�N�g��ǉ�
		GameObjectManager::addGameObject(scoreScreen);
	}
};

