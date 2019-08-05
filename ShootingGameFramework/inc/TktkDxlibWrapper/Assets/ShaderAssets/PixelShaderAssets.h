#ifndef PIXEL_SHADER_ASSETS_H_
#define PIXEL_SHADER_ASSETS_H_

#include <unordered_map>
#include <string>

class PixelShaderAssets
{
public:

	static void initialize();

	static void finalize();

	// ・引数のIDにシェーダーデータが関連付けられていた場合、古いデータを削除し、新しいデータを読み込む
	// ・読み込みに成功した場合は真、失敗した場合は偽を返す
	static bool load(int id, const std::string& fileName);

	// ・引数のIDにシェーダーデータが関連付けられていない場合、処理を行わない
	static void erase(int id);

	static void eraseAll();

	static const int& getPixelShader(int id);

private:

	static std::unordered_map<int, int> m_assets;
};

#endif // !PIXEL_SHADER_ASSETS_H_
