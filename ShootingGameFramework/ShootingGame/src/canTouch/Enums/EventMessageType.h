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


	// �G�l�~�[�֘A-----------------------------------------

	// �G�l�~�[�{�X������
	ENEMY_BOSS_DEAD,

	//�G�l�~�[1-1���S
	DIE_Enemy1_1,

	//�G�l�~�[1-2���S
	DIE_Enemy1_2,

	//�G�l�~�[1-3���S
	DIE_Enemy2,

	//�G�l�~�[3-1���S
	DIE_Enemy3_1,

	//Boss1������
	DIE_BOSS1_DEAD,
};