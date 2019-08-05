#pragma once

#include <TktkMath.h>
#include <TktkTextProcessing.h>
#include <TktkDxlibWrapper.h>
#include <TktkDxlib2DWrapper.h>
#include <TktkGameLoop.h>
#include <TktkSceneManagement.h>
#include <Tktk2dCollision.h>
#include <TktkClassFuncProcessor.h>
#include <TktkComponentFramework.h>
#include <TktkAppendComponent.h>
#include <TktkAppend2DComponent.h>
#include <TktkAppendDxlibComponent.h>
#include <TktkAppendDxlib2DComponent.h>

// �ǂ̂悤�ȃN���X���g���邩�H
class TktkManual
{
#ifndef _MBCS
	// ���w�I�ȃN���X
	void mathClass()
	{
		Random;		// ���������N���X
		Color;		// �F��\���\����
		Vector2;	// �Q�������W�A�x�N�g����\���\����
		Matrix3;	// �Rx�R�̍s��\����
		MathHelper;	// ���w�v�Z�̃T�|�[�g�N���X
	}

	// �Q�[���I�u�W�F�N�g��R���|�[�l���g
	void componentFrameworkClass()
	{
		GameObject;			// �Q�[���I�u�W�F�N�g�N���X
		GameObjectManager;	// �Q�[���I�u�W�F�N�g�Ǘ��N���X

		ComponentBase;		// �R���|�[�l���g�̌p�����N���X
	}

	// ��R�̃R���|�[�l���g
	void aLotOfComponent()
	{
		Transform2D;			// �Q�������W�A�X�P�[���A��]
		InertialMovement2D;		// �����ړ�
		InertialRotatement2D;	// ������]

		CircleDrawer;		// �~�̕`��
		Sprite2dDrawer;		// �摜�̕`��
		AnimatedSprite2d;	// Sprite2dDrawer�ŕ`�悵���摜���A�j���[�V����������

		RectCollider;		// �����`�̓����蔻��
		CircleCollider;		// �~�̓����蔻��
		Polygon2dCollider;	// ���p�`�̓����蔻��

		RectColliderWireFrameDrawer;	// RectCollider�̓����蔻��̃f�o�b�N�\��
		CircleColliderWireFrameDrawer;	// CircleColliderWireFrameDrawer�̃f�o�b�N�\��

		PositionClamper;			// ���W��͈͓��ɃN�����v����
		OutScreenSelfDestroyer2D;	// �͈͊O�ɏo���玩�g���E��

		BgmPlayer;// BGM�Đ��N���X
		SePlayer;// SE�Đ��N���X

		CurStateTypeList;	// StateMachine�Ŏg�p����X�e�[�g���Ǘ�����
		StateMachine;		// �X�e�[�g�}�V�[��

		BgmLoader;			// BGM�ǂݍ��݃N���X
		SeLoader;			// SE�ǂݍ��݃N���X
		TextureLoader;		// �摜�ǂݍ��݃N���X
		PixelShaderLoader;	// �s�N�Z���V�F�[�_�[�ǂݍ��݃N���X
	}

	// �Q�[�����[�v�N���X
	void gameLoopClass()
	{
		GameLoop;	// �Q�[�����[�v�̃N���X
		TktkTime;	// ���Ԍo�߂̃N���X
	}

	// �V�[���N���X
	void sceneClass()
	{
		SceneBase;		// �V�[���̌p�����N���X
		SceneManager;	// �V�[���Ǘ��N���X
	}

	// �����񑀍�n�N���X
	void textClass()
	{
		FileLoader;			// �t�@�C���ǂݍ��݃N���X
		TextCharDeleter;	// �����񂩂����̕������폜����N���X
		TextSpliter;		// ��������w��̋�؂蕶���ŕ�������N���X
	}

	// �������̃N���X�Ǘ��N���X
	void classFuncProcessor()
	{
		ClassFuncProcessor;	// �������̃N���X�Ǘ��N���X
	}
#endif // _MBCS
};