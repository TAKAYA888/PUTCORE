#pragma once

// �Q�[���I�u�W�F�N�g�����ʂ��邽�߂̃^�O
enum GameObjectTag
{
	// �^�O����
	GAME_OBJECT_TAG_NONE = 0,

	// ���j���[�J�[�\��
	GAME_OBJECT_TAG_CURSOR,

	// ���j���[����
	GAME_OBJECT_TAG_MENU_ITEM,

	// �v���C���[
	GAME_OBJECT_TAG_PLAYER,

	// �G
	GAME_OBJECT_TAG_ENEMY,

	// �{�X
	GAME_OBJECT_TAG_ENEMY_BOSS,

	// �v���C���[�̒e
	GAME_OBJECT_TAG_PLAYER_BULLET,

	// �G�̒e
	GAME_OBJECT_TAG_ENEMY_BULLET,
};