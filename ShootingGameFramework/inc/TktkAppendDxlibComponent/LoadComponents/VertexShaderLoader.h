#ifndef VERTEX_SHADER_LOADER_H_
#define VERTEX_SHADER_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// 頂点シェーダーのリソースを読み込むコンポーネント
class VertexShaderLoader
	: public ComponentBase
{
public:

	VertexShaderLoader(
		const std::string& loadFilePath		// 読み込みに使用するテキストファイルのパス
	);

	void awake();

	void update();

private:

	bool loadVertexShader(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !VERTEX_SHADER_LOADER_H_