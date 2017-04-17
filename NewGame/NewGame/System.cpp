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
	// 利用Alpha创建窗口
	sys_init_info_.mAppInstance = hInstance;  // WinMain的第1个参数
	sys_init_info_.mShow = nCmdShow;		  // WinMain的第4个参数
	sys_init_info_.mWinWidth = 800;
	sys_init_info_.mWinHeight = 400;
	sys_init_info_.mCreateConsole = 1;        // 是否需要打开控制台，1表示是，0表示否
	sys_init_info_.mCreateWindow = 1;         // 是否需要创建窗口，1表示是，0表示否
	sys_init_info_.mMaxFrameRate = 60;        // 设置帧率（如果使用Alpha的帧率控制功能的话）
	sys_init_info_.mpWinCallBack = Input::Handle;
	sys_init_info_.mClassStyle = CS_HREDRAW | CS_VREDRAW;  // 窗口类定义的重绘方式，水平重绘和垂直重绘
	sys_init_info_.mWindowStyle = WS_OVERLAPPEDWINDOW;     // 窗口风格

	// Alpha系统初始化，记录返回值
	int AESysInit_return_value = AESysInit(&sys_init_info_);

	// 分配控制台来帮助debug，把标准输出流重定向到AE系统的控制台
	if (sys_init_info_.mCreateConsole) {
		AllocConsole();
		console_out_.open("CONOUT$");
		streambuf_pointer_ = cout.rdbuf(console_out_.rdbuf());
		cout << "Console is ready for debug." << endl;
	}
	// 之后所有标准输出都会在AE系统的控制台上打印出来

	// 打开文件用于之后写log，该文件成为一个输出的流
	log_file_.open("log.txt", ios::out);
	// 如果打开文件失败，向控制台输出错误信息，并直接退出程序
	if (!log_file_) {
		cout << "Fail to open the log file!" << endl;
		log_file_ << "Fail to open the log file!" << endl;
		exit(EXIT_FAILURE);
	}

	// 如果系统初始化失败，向控制台输出错误信息，并直接退出程序
	if (AESysInit_return_value == 0) {
		cout << "Fail to init the AE system!" << endl;
		log_file_ << "Fail to open the log file!" << endl;
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
	log_file_ << "System: Initialize." << endl;
}

// 系统退出函数
void System::Exit() {
	// 如果选择开出AE系统控制台的话
	if (sys_init_info_.mCreateConsole) {
		// 恢复cout的流对象缓冲指针并关闭console_out_流
		cout.rdbuf(streambuf_pointer_);
		console_out_.close();
	}

	// Alpha系统退出
	AESysExit();

	// 写log
	log_file_ << "System: Exit." << endl;

	// 关闭文件，结束对log记录文件的写入
	log_file_.close();
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
