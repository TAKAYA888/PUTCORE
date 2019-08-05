#ifndef VERTEX_SHADER_ASSETS_H_
#define VERTEX_SHADER_ASSETS_H_

#include <unordered_map>
#include <string>

class VertexShaderAssets
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

	static const int& getVertexShader(int id);

private:

	static std::unordered_map<int, int> m_assets;
};

#endif // !VERTEX_SHADER_ASSETS_H_
