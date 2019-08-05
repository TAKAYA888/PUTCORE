#ifndef MODEL_LOADER_H_
#define MODEL_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// 3Dモデルのリソースを読み込むコンポーネント
class ModelLoader
	: public ComponentBase
{
public:

	ModelLoader(
		const std::string& loadFilePath		// 読み込みに使用するテキストファイルのパス
	);

	void awake();

	void update();

private:

	bool loadModel(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !MODEL_LOADER_H_