#ifndef MODEL_TEXTURE_ASSETS_H_
#define MODEL_TEXTURE_ASSETS_H_

#include <string>
#include <unordered_map>

// モデル適応用のテクスチャIDと対応したテクスチャを管理するクラス
class ModelTextureAssets
{
public:

	static void initialize();

	static void finalize();

	// ・引数のIDに既にモデル適応用のテクスチャデータが関連付けられていた場合、古いデータを削除し、新しいデータを読み込む
	// ・読み込みに成功した場合は真、失敗した場合は偽を返す
	static bool load(int id, const std::string& fileName);

	// ・引数のIDにモデル適応用のテクスチャデータが関連付けられていない場合、処理を行わない
	static void erase(int id);

	static void eraseAll();

	static const int getModelTexture(int id);

private:

	static std::unordered_map<int, int> m_assets;
};

#endif // !MODEL_TEXTURE_ASSETS_H_