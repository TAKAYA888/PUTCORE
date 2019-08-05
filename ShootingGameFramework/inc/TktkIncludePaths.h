#pragma once

#include <TktkMath.h>
#include <TktkTextProcessing.h>
#include <TktkDxlibWrapper.h>
#include <TktkDxlib2DWrapper.h>
#include <TktkGameLoop.h>
#include <TktkSceneManagement.h>
#include <Tktk2dCollision.h>
#include <TktkClassFuncProcessor.h>
#include <TktkComponentFramework.h>
#include <TktkAppendComponent.h>
#include <TktkAppend2DComponent.h>
#include <TktkAppendDxlibComponent.h>
#include <TktkAppendDxlib2DComponent.h>

// どのようなクラスが使えるか？
class TktkManual
{
#ifndef _MBCS
	// 数学的なクラス
	void mathClass()
	{
		Random;		// 乱数生成クラス
		Color;		// 色を表す構造体
		Vector2;	// ２次元座標、ベクトルを表す構造体
		Matrix3;	// ３x３の行列構造体
		MathHelper;	// 数学計算のサポートクラス
	}

	// ゲームオブジェクトやコンポーネント
	void componentFrameworkClass()
	{
		GameObject;			// ゲームオブジェクトクラス
		GameObjectManager;	// ゲームオブジェクト管理クラス

		ComponentBase;		// コンポーネントの継承元クラス
	}

	// 沢山のコンポーネント
	void aLotOfComponent()
	{
		Transform2D;			// ２次元座標、スケール、回転
		InertialMovement2D;		// 慣性移動
		InertialRotatement2D;	// 慣性回転

		CircleDrawer;		// 円の描画
		Sprite2dDrawer;		// 画像の描画
		AnimatedSprite2d;	// Sprite2dDrawerで描画した画像をアニメーションさせる

		RectCollider;		// 長方形の当たり判定
		CircleCollider;		// 円の当たり判定
		Polygon2dCollider;	// 多角形の当たり判定

		RectColliderWireFrameDrawer;	// RectColliderの当たり判定のデバック表示
		CircleColliderWireFrameDrawer;	// CircleColliderWireFrameDrawerのデバック表示

		PositionClamper;			// 座標を範囲内にクランプする
		OutScreenSelfDestroyer2D;	// 範囲外に出たら自身を殺す

		BgmPlayer;// BGM再生クラス
		SePlayer;// SE再生クラス

		CurStateTypeList;	// StateMachineで使用するステートを管理する
		StateMachine;		// ステートマシーン

		BgmLoader;			// BGM読み込みクラス
		SeLoader;			// SE読み込みクラス
		TextureLoader;		// 画像読み込みクラス
		PixelShaderLoader;	// ピクセルシェーダー読み込みクラス
	}

	// ゲームループクラス
	void gameLoopClass()
	{
		GameLoop;	// ゲームループのクラス
		TktkTime;	// 時間経過のクラス
	}

	// シーンクラス
	void sceneClass()
	{
		SceneBase;		// シーンの継承元クラス
		SceneManager;	// シーン管理クラス
	}

	// 文字列操作系クラス
	void textClass()
	{
		FileLoader;			// ファイル読み込みクラス
		TextCharDeleter;	// 文字列から特定の文字を削除するクラス
		TextSpliter;		// 文字列を指定の区切り文字で分割するクラス
	}

	// 根っこのクラス管理クラス
	void classFuncProcessor()
	{
		ClassFuncProcessor;	// 根っこのクラス管理クラス
	}
#endif // _MBCS
};