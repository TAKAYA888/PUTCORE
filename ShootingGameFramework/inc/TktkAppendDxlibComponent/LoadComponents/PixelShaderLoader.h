#ifndef PIXEL_SHADER_LOADER_H_
#define PIXEL_SHADER_LOADER_H_

#include <string>
#include <vector>
#include <TktkComponentFramework/Component/ComponentBase.h>

// ピクセルシェーダーのリソースを読み込むコンポーネント
class PixelShaderLoader
	: public ComponentBase
{
public:

	PixelShaderLoader(
		const std::string& loadFilePath		// 読み込みに使用するテキストファイルのパス
	);

	void awake();

	void update();

private:

	bool loadPixelShader(const std::vector<std::string>& splitWordData);

private:

	std::string m_loadFilePath;
};
#endif // !PIXEL_SHADER_LOADER_H_