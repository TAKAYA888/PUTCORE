#ifndef SE_LOADER_H_
#define SE_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// Se�̃��\�[�X��ǂݍ��ރR���|�[�l���g
class SeLoader
	: public ComponentBase
{
public:

	SeLoader(
		const std::string& loadFilePath		// �ǂݍ��݂Ɏg�p����e�L�X�g�t�@�C���̃p�X
	);

	void awake();

	void update();

private:

	bool loadSe(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !SE_LOADER_H_