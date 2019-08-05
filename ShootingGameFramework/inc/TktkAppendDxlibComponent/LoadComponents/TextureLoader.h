#ifndef TEXTURE_LOADER_H_
#define TEXTURE_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// 画像のリソースを読み込むコンポーネント
class TextureLoader
	: public ComponentBase
{
public:

	TextureLoader(
		const std::string& loadFilePath		// 読み込みに使用するテキストファイルのパス
	);

	void awake();

	void update();

private:

	bool loadTexture(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !TEXTURE_LOADER_H_