#ifndef MODEL_ASSET_H_
#define MODEL_ASSET_H_

#include <vector>
#include <unordered_map>
#include <string>

#include "ModelHandles.h"

// 3DモデルIDと対応したモデルを管理するクラス
class ModelAssets
{
public:

	static void initialize();

	static void finalize();

	// ・引数のIDに既に3Dモデルデータが関連付けられていた場合、古いデータを削除し、新しいデータを読み込む
	// ・読み込みに成功した場合は真、失敗した場合は偽を返す
	static bool load(int id, const std::string& fileName);

	// ・引数のIDに既に3Dモデルデータが関連付けられていた場合、古いデータを削除し、新しいデータを読み込む
	// ・読み込みに成功した場合は真、失敗した場合は偽を返す
	// ・アニメーションデータ同時読み込み用
	static bool load(int id, const std::string& modelFileName, std::vector<std::string> animFileNames);

	// ・引数のIDに3Dモデルデータが関連付けられていない場合、処理を行わない
	static void erase(int id);

	static void eraseAll();

	static const ModelHandles& getModel(int id);

private:

	static std::unordered_map<int, ModelHandles> m_assets;
};

#endif // !MODEL_ASSET_H_