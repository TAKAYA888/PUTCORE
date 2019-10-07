#pragma once

#include <string>
#include <forward_list>
#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class EnemyGenerator2Script
	: public ComponentBase
{
public:

	EnemyGenerator2Script(const std::string& stageTextPath);

public:

	// 毎フレーム呼ばれる
	void update();

private:

	// 出現させる敵の情報の構造体
	struct GenerateData
	{
		// 名前
		std::string name;

		// 出現時間
		float time{ 0.0f };

		// 出現座標
		Vector2 position{ Vector2::zero };

		// 出現時の初期移動方向＋速度
		float rotationDeg{ 0.0f };
	};

private:

	// 出現させる敵のデータのリスト
	std::forward_list<GenerateData> m_generateDataList;

	// 次に出現する敵のデータが「m_generateDataList」のどこにあるかの情報
	std::forward_list<GenerateData>::iterator m_curIterator;

	// ステージが始まってからの時間
	float m_spawnTimer{ 0.0f };
};