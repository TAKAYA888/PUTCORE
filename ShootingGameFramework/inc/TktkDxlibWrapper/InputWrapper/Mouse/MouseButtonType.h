#ifndef MOUSE_BUTTON_TYPE_H_
#define MOUSE_BUTTON_TYPE_H_

#include <DxLib.h>

// マウスのボタンの種類
enum MouseButtonType
{
	MOUSE_LEFT_BUTTON	= MOUSE_INPUT_LEFT,		// 左マウスボタン
	MOUSE_RIGHT_BUTTON	= MOUSE_INPUT_RIGHT,	// 右マウスボタン
	MOUSE_MIDDLE_BUTTON = MOUSE_INPUT_MIDDLE	// マウスホイール押し込み
};

#endif // !MOUSE_BUTTON_TYPE_H_