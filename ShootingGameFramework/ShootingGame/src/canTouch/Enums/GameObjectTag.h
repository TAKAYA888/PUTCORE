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

	// �A�C�e��
	GAME_OBJECT_TAG_ITEM,

	//�R�A
	GAME_OBJECT_TAG_CORE,

	// �G
	GAME_OBJECT_TAG_ENEMY,

	// �{�X
	GAME_OBJECT_TAG_ENEMY_BOSS,

	// �v���C���[�̒e
	GAME_OBJECT_TAG_PLAYER_BULLET,

	//�R�A�̒e
	GAME_OBJECT_TAG_CORE_BULLET,

	// �G�̒e
	GAME_OBJECT_TAG_ENEMY_BULLET,

	//�R�A�p���[�A�b�v�A�C�e��
	GAME_OBJECT_TAG_CORE_POWER_UP_ITEM,

	//�񕜃A�C�e��
	GAME_OBJECT_TAG_RECOVERY_ITEM,

	//BG
	AKITA_BANZAI,
};