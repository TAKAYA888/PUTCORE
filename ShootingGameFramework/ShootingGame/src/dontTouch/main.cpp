#if defined(NDEBUG) || !defined(_DEBUG)
#pragma comment( lib, "TktkAppendComponentLib_mt.lib" )
#pragma comment( lib, "TktkAppend2DComponentLib_mt.lib" )
#pragma comment( lib, "TktkAppendDxlib2DComponentLib_mt.lib" )
#pragma comment( lib, "TktkAppendDxlibComponentLib_mt.lib" )
#pragma comment( lib, "TktkClassFuncProcessLib_mt.lib" )
#pragma comment( lib, "TktkComponentFrameworkLib_mt.lib" )
#pragma comment( lib, "TktkGameLoopLib_mt.lib" )
#pragma comment( lib, "TktkSceneManagementLib_mt.lib" )
#pragma comment( lib, "TktkTextProcessingLib_mt.lib" )
#pragma comment( lib, "TktkMathLib_mt.lib" )
#pragma comment( lib, "TktkDxlibWrappingLib_mt.lib" )
#pragma comment( lib, "TktkDxlib2DWrappingLib_mt.lib" )
#pragma comment( lib, "Tktk2dCollisionLib_mt.lib" )
#else
#pragma comment( lib, "TktkAppendComponentLib_mtd.lib" )
#pragma comment( lib, "TktkAppend2DComponentLib_mtd.lib" )
#pragma comment( lib, "TktkAppendDxlib2DComponentLib_mtd.lib" )
#pragma comment( lib, "TktkAppendDxlibComponentLib_mtd.lib" )
#pragma comment( lib, "TktkClassFuncProcessLib_mtd.lib" )
#pragma comment( lib, "TktkComponentFrameworkLib_mtd.lib" )
#pragma comment( lib, "TktkGameLoopLib_mtd.lib" )
#pragma comment( lib, "TktkSceneManagementLib_mtd.lib" )
#pragma comment( lib, "TktkTextProcessingLib_mtd.lib" )
#pragma comment( lib, "TktkMathLib_mtd.lib" )
#pragma comment( lib, "TktkDxlibWrappingLib_mtd.lib" )
#pragma comment( lib, "TktkDxlib2DWrappingLib_mtd.lib" )
#pragma comment( lib, "Tktk2dCollisionLib_mtd.lib" )
#endif

#include "MyGame/MyGame.h"
#include "../canTouch/Utility/ScreenSize.h"

int main()
{
	return MyGame(Vector2(SCREEN_SIZE), false).run();
}