#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <string>
#include <TktkMath/Vector2.h>
#include <TktkMath/Color.h>

#include "BlendMode.h"
#include "../Assets/ShaderAssets/RenderTargetHandles.h"

class Graphics
{
// TODO : �֐��������ƍׂ����N���X��������
public:

	static void setUpDxlibScreen(const Vector2& windowSize, bool fullScreen);

	static void deleteDxlibScreen();

	static void initalize();

	static void finalize();

	static void clearScreen();

	static void flipScreen();

	// �J��������ێ����ĕ`����ʂ�ݒ肷��
	static void setDxDrawScreen(int drawScreen);

	// �E�w�i�摜�������̐F�ŏ���������
	// �Er(float 0.0f �` 1.0f)
	// �Eg(float 0.0f �` 1.0f)
	// �Eb(float 0.0f �` 1.0f)
	static void clearColor(const Color& color);

	// �E�u�����h�̎�ނ�ݒ肷��
	static void setBlendMode(BlendMode mode, float blendParam = 1.0f);

	// ******************************
	// �V�F�[�_�[�֘A

	static void useOrigShader(bool useOrigShader);

	static void setVertexShader(int id);
	static void setPixelShader(int id);

	static void setShaderUsedTexture(int stageIndex, int textureId);
	static void setShaderUsedModelTexture(int stageIndex, int modelTextureId);
	static void setShaderUsedRenderTargetsTexture(int stageIndex, int renderTargetsId);

	// ******************************
	// �����_�[�^�[�Q�b�g�֘A

	// �����_�[�^�[�Q�b�g�̕`����e���폜����
	static void clearRenderTargets(int id);

	// �J��������ێ����Ďw�肵��ID�̃����_�[�^�[�Q�b�g��`����ʂɐݒ肷��
	static void setRenderTarget(int id);

	// �J��������ێ����ă����_�[�^�[�Q�b�g�̐ݒ����������
	static void unSetRenderTarget();

	// �V�F�[�_�[���g�p���Đݒ肵�������_�[�^�[�Q�b�g�ɕ`�悷��
	static void dxDrawPrimitive2DToShader();

	// �w�肵�������_�[�^�[�Q�b�g�̉摜�����ݐݒ肳�ꂽ�`����ʂɕ`�悷��
	static void drawRenderTargetTexture(int renderTargetId);

private:

	static RenderTargetHandles m_bindRenderTargetHandles;
};

#endif // !GRAPHICS_H_