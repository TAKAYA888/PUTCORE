#ifndef MODEL_TEXTURE_LOADER_H_
#define MODEL_TEXTURE_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// 3D���f���ɓ\��摜�̃��\�[�X��ǂݍ��ރR���|�[�l���g
class ModelTextureLoader
	: public ComponentBase
{
public:

	ModelTextureLoader(
		const std::string& loadFilePath		// �ǂݍ��݂Ɏg�p����e�L�X�g�t�@�C���̃p�X
	);

	void awake();

	void update();

private:

	bool loadModelTexture(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};

#endif // !MODEL_TEXTURE_LOADER_H_