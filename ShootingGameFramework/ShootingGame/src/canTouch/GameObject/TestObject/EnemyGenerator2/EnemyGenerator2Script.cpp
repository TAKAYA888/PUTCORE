#include "EnemyGenerator2Script.h"

#include <vector>
#include "../Enemy/NormalEnemy/NormalEnemy.h"
#include "../Enemy/VirusEnemy1-1/VirusEnemy1-1.h"
#include "../Enemy/VirusEnemy1-2/VirusEnemy1-2.h"
#include "../Enemy/VirusEnemy2/VirusEnemy2.h"
#include "../Enemy/VirusEnemy3-1/VirusEnemy3-1.h"
#include "../Enemy/VirusEnemy4/VirusEnemy4.h"
#include "../Enemy/VirusEnemy5/VirusEnemy5.h"
#include "../Enemy/zako6/zako6Up/zako6Up.h"
#include "../Enemy/zako6/zako6Down/zako6Down.h"
#include "../Enemy/BossEnemy/BossEnemy.h"
#include "../Enemy/Boss/Boss.h"
#include "../Enemy/Boss2/Boss2.h"
#include "../Enemy/Boss3/Boss3.h"

EnemyGenerator2Script::EnemyGenerator2Script(const std::string & stageTextPath)
{
	// 使用する敵の出現情報の文字列を行ごとに格納する配列
	std::vector<std::string> stageTextData;

	// 引数から受け取ったテキストファイルのパスを使用して文字列を読み込む
	FileLoader::fileLoad(stageTextPath, &stageTextData);

	// 読み込んだ文字列を巡回する
	for (const auto & line : stageTextData)
	{
		// 読み込んだ行をカンマ区切りの文字列で格納する配列
		std::vector<std::string> wordData;

		// 読み込んだ行をカンマ区切りで切り分けて配列に入れる
		TextSpliter::textSplit(line, ',', &wordData);

		// 出現させる敵の情報を準備
		GenerateData generateData;

		// 読み込んだカンマ区切りの文字列を数値に変換して敵の情報に適応
		// 最初の数値を出現時間に
		generateData.name = wordData.at(0);
		// ２番目の数値を出現時間に
		generateData.time = std::stof(wordData.at(1));
		// ３、４番目の数値を出現座標に
		generateData.position = Vector2(std::stof(wordData.at(2)), std::stof(wordData.at(3)));
		// ５番目の数値を出現回転角度
		generateData.rotationDeg = std::stof(wordData.at(4));

		// 出現させる敵情報のリストに追加
		m_generateDataList.push_front(generateData);
	}

	// 追加した敵情報のリストを出現時間順にソートする
	m_generateDataList.sort(
		[](const GenerateData& a, const GenerateData& b) { return a.time < b.time; }
	);

	// リストでの次に出現する敵の情報の場所をリストの先頭の位置にする
	m_curIterator = std::begin(m_generateDataList);
}

void EnemyGenerator2Script::update()
{
	// 経過時間を更新
	m_spawnTimer += TktkTime::deltaTime();

	// リストの最後の位置を取得
	auto end = std::end(m_generateDataList);

	/*
	 * 次に出現する敵のデータの位置がリストの要素の最後では無く、
	 * 次に出現する敵のデータの出現時間が現在の時間よりも小さければループを続ける
	 */
	while (m_curIterator != end && (*m_curIterator).time < m_spawnTimer)
	{
		// 次に出現する敵のデータを使用して新たな敵を出現させる

		// もし出現させる敵の名前が"enemy"だったら
		if ((*m_curIterator).name == "enemy")
		{
			// NormalEnemyを生成する
			NormalEnemy::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "boss")
		{
			BossEnemy::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "virusenemy1-1")
		{
			VirusEnemy1_1::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "virusenemy1-2")
		{
			VirusEnemy1_2::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "virusenemy2")
		{
			VirusEnemy2::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "virusenemy3-1")
		{
			VirusEnemy3_1::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "virusenemy4")
		{
			VirueEnemy4::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "virusenemy5")
		{
			VirusEnemy5::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "zako6up")
		{
			zako6Up::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "zako6down")
		{
			zako6Down::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "Boss1")
		{
			Boss::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "Boss2")
		{
			Boss2::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "Boss3")
		{
			Boss3::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}

		// リストでの次に出現する敵の情報の場所を一つ進める
		m_curIterator++;
	}
}