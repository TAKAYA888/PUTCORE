#pragma once

// �S�̂ɑ��郁�b�Z�[�W�̎��
enum EventMessageType
{
	// ���b�Z�[�W����
	NO_MESSAGE = 0,

	// ���[�h�V�[���̃Q�[���I�u�W�F�N�g�S������
	DIE_LOAD_OBJECT,

	// �^�C�g���̃Q�[���I�u�W�F�N�g�S������
	DIE_TITLE_OBJECT,

	// �Q�[���v���C�̃Q�[���I�u�W�F�N�g�S������
	DIE_GAMEPLAY_OBJECT,

	// �G�l�~�[�{�X������
	ENEMY_BOSS_DEAD,
};