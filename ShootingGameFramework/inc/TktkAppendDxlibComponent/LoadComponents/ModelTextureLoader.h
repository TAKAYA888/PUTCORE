#ifndef MODEL_TEXTURE_LOADER_H_
#define MODEL_TEXTURE_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// 3Dモデルに貼る画像のリソースを読み込むコンポーネント
class ModelTextureLoader
	: public ComponentBase
{
public:

	ModelTextureLoader(
		const std::string& loadFilePath		// 読み込みに使用するテキストファイルのパス
	);

	void awake();

	void update();

private:

	bool loadModelTexture(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};

#endif // !MODEL_TEXTURE_LOADER_H_