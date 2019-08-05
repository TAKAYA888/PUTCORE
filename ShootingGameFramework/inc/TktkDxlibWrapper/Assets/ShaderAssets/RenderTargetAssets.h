#ifndef RENDER_TARGET_ASSETS_H_
#define RENDER_TARGET_ASSETS_H_

#include <unordered_map>
#include <vector>
#include <TktkMath/Vector2.h>
#include "RenderTargetHandles.h"

class RenderTargetAssets
{
public:

	static void initialize();

	static void finalize();

	static bool createRenderTarget(
		int id,
		const Vector2& size,
		bool hdr = false,
		bool useZbuffer = false,
		int bitDepth = 32,
		int channel = 4
	);

	static void erase(int id);

	static void eraseAll();

	static const RenderTargetHandles& getRenderTarget(int id);

private:

	static std::unordered_map<int, RenderTargetHandles> m_assets;
};

#endif // !RENDER_TARGET_ASSETS_H_