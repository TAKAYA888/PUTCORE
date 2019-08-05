#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <string>
#include <TktkMath/Vector2.h>
#include <TktkMath/Color.h>

#include "BlendMode.h"
#include "../Assets/ShaderAssets/RenderTargetHandles.h"

class Graphics
{
// TODO : 関数をもっと細かくクラス分けする
public:

	static void setUpDxlibScreen(const Vector2& windowSize, bool fullScreen);

	static void deleteDxlibScreen();

	static void initalize();

	static void finalize();

	static void clearScreen();

	static void flipScreen();

	// カメラ情報を保持して描画先画面を設定する
	static void setDxDrawScreen(int drawScreen);

	// ・背景画像を引数の色で初期化する
	// ・r(float 0.0f ～ 1.0f)
	// ・g(float 0.0f ～ 1.0f)
	// ・b(float 0.0f ～ 1.0f)
	static void clearColor(const Color& color);

	// ・ブレンドの種類を設定する
	static void setBlendMode(BlendMode mode, float blendParam = 1.0f);

	// ******************************
	// シェーダー関連

	static void useOrigShader(bool useOrigShader);

	static void setVertexShader(int id);
	static void setPixelShader(int id);

	static void setShaderUsedTexture(int stageIndex, int textureId);
	static void setShaderUsedModelTexture(int stageIndex, int modelTextureId);
	static void setShaderUsedRenderTargetsTexture(int stageIndex, int renderTargetsId);

	// ******************************
	// レンダーターゲット関連

	// レンダーターゲットの描画内容を削除する
	static void clearRenderTargets(int id);

	// カメラ情報を保持して指定したIDのレンダーターゲットを描画先画面に設定する
	static void setRenderTarget(int id);

	// カメラ情報を保持してレンダーターゲットの設定を解除する
	static void unSetRenderTarget();

	// シェーダーを使用して設定したレンダーターゲットに描画する
	static void dxDrawPrimitive2DToShader();

	// 指定したレンダーターゲットの画像を現在設定された描画先画面に描画する
	static void drawRenderTargetTexture(int renderTargetId);

private:

	static RenderTargetHandles m_bindRenderTargetHandles;
};

#endif // !GRAPHICS_H_