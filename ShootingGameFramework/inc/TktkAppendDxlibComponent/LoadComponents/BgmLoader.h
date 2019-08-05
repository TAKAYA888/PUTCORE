#ifndef BGM_LOADER_H_
#define BGM_LOADER_H_

#include <vector>
#include <string>
#include <TktkComponentFramework/Component/ComponentBase.h>

// Bgm�̃��\�[�X��ǂݍ��ރR���|�[�l���g
class BgmLoader
	: public ComponentBase
{
public:

	BgmLoader(
		const std::string& loadFilePath		// �ǂݍ��݂Ɏg�p����e�L�X�g�t�@�C���̃p�X
	);

	void awake();

	void update();

private:

	bool loadBgm(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !BGM_LOADER_H_