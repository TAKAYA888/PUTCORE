#ifndef PIXEL_SHADER_LOADER_H_
#define PIXEL_SHADER_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// �s�N�Z���V�F�[�_�[�̃��\�[�X��ǂݍ��ރR���|�[�l���g
class PixelShaderLoader
	: public ComponentBase
{
public:

	PixelShaderLoader(
		const std::string& loadFilePath		// �ǂݍ��݂Ɏg�p����e�L�X�g�t�@�C���̃p�X
	);

	void awake();

	void update();

private:

	bool loadPixelShader(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !PIXEL_SHADER_LOADER_H_