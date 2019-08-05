#ifndef TEXTURE_LOADER_H_
#define TEXTURE_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// �摜�̃��\�[�X��ǂݍ��ރR���|�[�l���g
class TextureLoader
	: public ComponentBase
{
public:

	TextureLoader(
		const std::string& loadFilePath		// �ǂݍ��݂Ɏg�p����e�L�X�g�t�@�C���̃p�X
	);

	void awake();

	void update();

private:

	bool loadTexture(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !TEXTURE_LOADER_H_