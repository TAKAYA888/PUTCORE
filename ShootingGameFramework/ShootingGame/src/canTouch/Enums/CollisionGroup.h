#pragma once

// �Փ˔���̃O���[�v
enum CollisionGroup
{
	// �Փ˔��薳��
	COLLISION_GROUP_NONE,

	// �J�[�\���̏Փ˔���
	COLLISION_GROUP_CURSOR,

	// ���j���[���ڂ̏Փ˔���
	COLLISION_GROUP_MENU_ITEM,

	// �v���C���[�̏Փ˔���
	COLLISION_GROUP_PLAYER,
	COLLISION_GROUP_ITEM,
	//�R�A�̏Փ˔���
	COLLISION_GROUP_CORE,

	// �G�̏Փ˔���
	COLLISION_GROUP_ENEMY,


	// �v���C���[�̒e�̏Փ˔���
	COLLISION_GROUP_PLAYER_BULLET,

	//�R�A�̒e�̏Փ˔���
	COLLISION_GROUP_CORE_BULLET,

	// �G�̒e�̏Փ˔���
	COLLISION_GROUP_ENEMY_BULLET,
};