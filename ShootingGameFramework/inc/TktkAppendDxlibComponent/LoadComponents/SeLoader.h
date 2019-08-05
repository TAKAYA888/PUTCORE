#ifndef SE_LOADER_H_
#define SE_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// Seのリソースを読み込むコンポーネント
class SeLoader
	: public ComponentBase
{
public:

	SeLoader(
		const std::string& loadFilePath		// 読み込みに使用するテキストファイルのパス
	);

	void awake();

	void update();

private:

	bool loadSe(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !SE_LOADER_H_