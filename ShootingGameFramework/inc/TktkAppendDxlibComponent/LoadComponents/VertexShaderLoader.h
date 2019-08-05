#ifndef VERTEX_SHADER_LOADER_H_
#define VERTEX_SHADER_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// ���_�V�F�[�_�[�̃��\�[�X��ǂݍ��ރR���|�[�l���g
class VertexShaderLoader
	: public ComponentBase
{
public:

	VertexShaderLoader(
		const std::string& loadFilePath		// �ǂݍ��݂Ɏg�p����e�L�X�g�t�@�C���̃p�X
	);

	void awake();

	void update();

private:

	bool loadVertexShader(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !VERTEX_SHADER_LOADER_H_