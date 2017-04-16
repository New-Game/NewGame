/* Project:      NewGame
 * File Name:    System.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      系统管理器实现文件
 */

#include "AEEngine.h"
#include "System.h"
#include "Input.h"

#pragma comment (lib, "Alpha_Engine.lib")

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
// 系统初始化函数
int SystemInitialize(HINSTANCE hInstance, int nCmdShow) {
	// 利用Alpha创建窗口
	AESysInitInfo sysInitInfo;
	sysInitInfo.mAppInstance = hInstance;  // WinMain的第1个参数
	sysInitInfo.mShow = nCmdShow;		   // WinMain的第4个参数
	sysInitInfo.mWinWidth = 800;
	sysInitInfo.mWinHeight = 400;
	sysInitInfo.mCreateConsole = 0;        // 是否需要打开控制台，1表示是，0表示否
	sysInitInfo.mCreateWindow = 1;         // 是否需要创建窗口，1表示是，0表示否
	sysInitInfo.mMaxFrameRate = 60;        // 设置帧率（如果使用Alpha的帧率控制功能的话）
	sysInitInfo.mpWinCallBack = InputHandle;
	sysInitInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;  // 窗口类定义的重绘方式，水平重绘和垂直重绘
	sysInitInfo.mWindowStyle = WS_OVERLAPPEDWINDOW;     // 窗口风格

	// Alpha系统初始化 及 模块重置
	if (0 == AESysInit(&sysInitInfo))
		return -1;
	AESysReset();
	// 修改窗口标题
	AESysSetWindowTitle("New Game!");

	/*AEGfxMeshStart();
	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f,
		25.5f, 0.0f, 0x00FF0000, 0.0f, 0.0f,
		-25.5f, 25.5f, 0xFFFFFF00, 0.0f, 0.0f);
	AEGfxVertexList *test = AEGfxMeshEnd();
	float x = 0.0f;
	float y = 0.0f;
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	
	AESysFrameStart();
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(x, y);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxSetTransparency(1);
	AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	AEGfxMeshDraw(test, AE_GFX_MDM_TRIANGLES);
	AESysFrameEnd();

	AEGfxMeshFree(test);*/

	// 打开签到表
	//if ((fp = fopen("Output.txt", "w")) == NULL) {
	//	printf("Cannot find file Output.txt\n");
	//	return -1;
	//}
	// 签到
	//fprintf(fp, "System:Initialize\n");

	return 0;
}

// 系统退出函数
void SystemExit() {
	// Alpha系统退出
	AESysExit();

	// 签到
	//fprintf(fp, "System:Exit\n");
	//fclose(fp);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Memeber Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
