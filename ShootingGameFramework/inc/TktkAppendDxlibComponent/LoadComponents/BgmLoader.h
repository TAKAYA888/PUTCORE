#ifndef BGM_LOADER_H_
#define BGM_LOADER_H_

#include <vector>
#include <string>
#include <TktkComponentFramework/Component/ComponentBase.h>

// Bgmのリソースを読み込むコンポーネント
class BgmLoader
	: public ComponentBase
{
public:

	BgmLoader(
		const std::string& loadFilePath		// 読み込みに使用するテキストファイルのパス
	);

	void awake();

	void update();

private:

	bool loadBgm(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !BGM_LOADER_H_