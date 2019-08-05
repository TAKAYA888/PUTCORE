#ifndef RENDER_TARGET_H_
#define RENDER_TARGET_H_

#include <DxLib.h>

#include <array>

struct RenderTargetHandles
{
public:

	// SetDrawScreen で描画対象にできるグラフィックハンドル
	int screenGraphHandle{ -1 };

	// 頂点データの配列
	std::array<VERTEX2DSHADER, 4U> vertices{ };
};

#endif // !RENDER_TARGET_H_