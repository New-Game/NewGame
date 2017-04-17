/* Project:      NewGame
 * File Name:    System.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      系统管理器实现文件
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"

using namespace std;

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

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Memeber Functions:
//------------------------------------------------------------------------------
// 系统初始化函数
void System::Initialize(HINSTANCE hInstance, int nCmdShow) {
	// 打开文件用于之后写log，该文件成为一个输入输出的流
	out_file_log.open("log.txt", ios::out);
	// 如果打开文件失败，向控制台输出错误信息，并直接退出程序
	if (!out_file_log) {
		clog << "Fail to open the log file!" << endl;
		exit(EXIT_FAILURE);
	}

	// 利用Alpha创建窗口
	AESysInitInfo sysInitInfo;
	sysInitInfo.mAppInstance = hInstance;  // WinMain的第1个参数
	sysInitInfo.mShow = nCmdShow;		   // WinMain的第4个参数
	sysInitInfo.mWinWidth = 800;
	sysInitInfo.mWinHeight = 400;
	sysInitInfo.mCreateConsole = 1;        // 是否需要打开控制台，1表示是，0表示否
	sysInitInfo.mCreateWindow = 1;         // 是否需要创建窗口，1表示是，0表示否
	sysInitInfo.mMaxFrameRate = 60;        // 设置帧率（如果使用Alpha的帧率控制功能的话）
	sysInitInfo.mpWinCallBack = Input::Handle;
	sysInitInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;  // 窗口类定义的重绘方式，水平重绘和垂直重绘
	sysInitInfo.mWindowStyle = WS_OVERLAPPEDWINDOW;     // 窗口风格

	// Alpha系统初始化
	// 如果系统初始化失败，向控制台输出错误信息，并直接退出程序
	if (0 == AESysInit(&sysInitInfo)) {
		clog << "Fail to init the AE system!" << endl;
		exit(EXIT_FAILURE);
	}

	// Alpha系统模块重置
	AESysReset();

	// 修改窗口标题
	AESysSetWindowTitle("New Game!");

	/*AEGfxMeshStart();
	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f,
		25.5f, 0.0f, 0x00FF0000, 0.0f, 0.0f,
		-25.5f, 25.5f, 0xFFFFFF00, 0.0f, 0.0f);
	AEGfxVertexList *test = AEGfxMeshEnd();
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	//AESysFrameStart();
	//AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(0.0f, 0.0f);
	//AEGfxTextureSet(NULL, 0, 0);
	//AEGfxSetTransparency(1);
	//AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	AEGfxMeshDraw(test, AE_GFX_MDM_TRIANGLES);
	//AESysFrameEnd();

	AEGfxMeshFree(test);*/

	// 写log
	out_file_log << "System: Initialize." << endl;
}

// 系统退出函数
void System::Exit() {
	// Alpha系统退出
	AESysExit();

	// 写log
	out_file_log << "System: Exit." << endl;

	// 关闭文件，结束对log记录文件的写入
	out_file_log.close();
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
