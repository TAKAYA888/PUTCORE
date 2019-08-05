#ifndef TEXTURE_ASSETS_H_
#define TEXTURE_ASSETS_H_

#include <string>
#include <unordered_map>

#include "TextureHandles.h"

// テクスチャIDと対応したテクスチャを管理するクラス
class TextureAssets
{
public:

	static void initialize();

	static void finalize();

	// ・引数のIDに既にテクスチャデータが関連付けられていた場合、古いデータを削除し、新しいデータを読み込む
	// ・読み込みに成功した場合は真、失敗した場合は偽を返す
	static bool load(int id, const std::string& fileName);

	// ・画像の分割読み込み
	// ・row   ：横に何分割するか
	// ・column：縦に何分割するか
	// ・分割した画像は左上から順に右方向にインデックスが付けられる
	// ・引数のIDに既にテクスチャデータが関連付けられていた場合、古いデータを削除し、新しいデータを読み込む
	// ・読み込みに成功した場合は真、失敗した場合は偽を返す
	static bool load(int id, const std::string& fileName, int row, int column);

	// ・引数のIDにテクスチャデータが関連付けられていない場合、処理を行わない
	static void erase(int id);

	static void eraseAll();

	static const TextureHandles& getTexture(int id);

private:

	static std::unordered_map<int, TextureHandles> m_assets;
};

#endif // !TEXTURE_ASSETS_H_