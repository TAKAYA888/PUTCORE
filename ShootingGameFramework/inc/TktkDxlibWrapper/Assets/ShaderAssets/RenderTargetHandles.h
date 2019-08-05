#ifndef RENDER_TARGET_H_
#define RENDER_TARGET_H_

#include <DxLib.h>

#include <array>

struct RenderTargetHandles
{
public:

	// SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h��
	int screenGraphHandle{ -1 };

	// ���_�f�[�^�̔z��
	std::array<VERTEX2DSHADER, 4U> vertices{ };
};

#endif // !RENDER_TARGET_H_