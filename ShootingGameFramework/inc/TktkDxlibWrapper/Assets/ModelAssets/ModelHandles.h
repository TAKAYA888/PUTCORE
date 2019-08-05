#ifndef MODEL_HANDLES_H_
#define MODEL_HANDLES_H_

#include <vector>

// モデルと対応するアニメーションを同時に格納する構造体
struct ModelHandles
{
public:

	// モデル本体のハンドル
	int modellHandle{ -1 };

	// モデルに対応するアニメーションのハンドル
	std::vector<int> animHandles;
};

#endif // !MODEL_HANDLES_H_