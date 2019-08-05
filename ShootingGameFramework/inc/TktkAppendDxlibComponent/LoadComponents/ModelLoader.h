#ifndef MODEL_LOADER_H_
#define MODEL_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// 3D���f���̃��\�[�X��ǂݍ��ރR���|�[�l���g
class ModelLoader
	: public ComponentBase
{
public:

	ModelLoader(
		const std::string& loadFilePath		// �ǂݍ��݂Ɏg�p����e�L�X�g�t�@�C���̃p�X
	);

	void awake();

	void update();

private:

	bool loadModel(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !MODEL_LOADER_H_