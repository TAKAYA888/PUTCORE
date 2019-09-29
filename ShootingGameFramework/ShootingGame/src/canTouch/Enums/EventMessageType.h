#pragma once

// �S�̂ɑ��郁�b�Z�[�W�̎��
enum EventMessageType
{
	// ���b�Z�[�W����
	NO_MESSAGE = 0,

	// �I�u�W�F�N�g�֘A-------------------------------------

	// ���[�h�V�[���̃Q�[���I�u�W�F�N�g�S������
	DIE_LOAD_OBJECT,

	// �^�C�g���̃Q�[���I�u�W�F�N�g�S������
	DIE_TITLE_OBJECT,

	// �Q�[���v���C�̃Q�[���I�u�W�F�N�g�S������
	DIE_GAMEPLAY_OBJECT,

	// �V�[���֘A-------------------------------------------

	// �|�[�Y���I���
	PAUSE_END,

	// �Q�[���I�[�o�[�A�Q�[���N���A������
	DIE_O_C,

	// ���U���g������
	DIE_RESULT,

	// �v���C���[�֘A----------------------------------------

	//�v���C���[�̎��S
	DIE_PLAYER,

	//�R�A�̎��S
	DIE_CORE,

	// �G�l�~�[�֘A-----------------------------------------

	// �G�l�~�[�{�X������
	ENEMY_BOSS_DEAD,

	//�G�l�~�[1-1���S
	DIE_Enemy1_1,

	//�G�l�~�[1-2���S
	DIE_Enemy1_2,

	//�G�l�~�[2���S
	DIE_Enemy2,

	//�G�l�~�[3-1���S
	DIE_Enemy3_1,

	//�G�l�~�[4���S
	DIE_Enemy4,

	//�G�l�~�[5���S
	DIE_Enemy5,

	//�U�R�U�����S
	DIE_Enemy6,

	//Boss1������
	DIE_BOSS1_DEAD,

	//Boss2������
	DIE_BOSS2_DEAD,

	//Boss3������
	DIE_BOSS3_DEAD,

};