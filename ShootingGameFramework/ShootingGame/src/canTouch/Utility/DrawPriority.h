#pragma once

// ������������������ɕ`�悳���
namespace DrawPriority
{
	const float DRAW_PRIORITY_BACK_GROUND = -100.0f;

	// �G�̒e��`�悷�郌�C���[
	const float DRAW_PRIORITY_ENEMY_BULLET = 10.0f;

	// �v���C���[�̒e��`�悷�郌�C���[
	const float DRAW_PRIORITY_PLAYER_BULLET = 20.0f;

	// �G��`�悷�郌�C���[
	const float DRAW_PRIORITY_ENEMY = 30.0f;

	// �v���C���[��`�悷�郌�C���[
	const float DRAW_PRIORITY_PLAYER = 40.0f;

	// �G�̃{�X��`�悷�郌�C���[
	const float DRAW_PRIORITY_ENEMY_BOSS = 50.0f;

	// �G�t�F�N�g��`�悷�郌�C���[
	const float  DRAW_PRIORITY_EFFECT = 60.0f;

	// UI��`�悷�郌�C���[
	const float DRAW_PRIORITY_UI = 100.0f;

	// �f�o�b�N�\����`�悷�郌�C���[
	const float DRAW_PRIORITY_DEBUG_FLAME = 100.0f;
}