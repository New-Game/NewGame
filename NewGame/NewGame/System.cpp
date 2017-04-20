/**
 * Project:      NewGame
 * File Name:    System.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      系统管理器实现文件
 */

#include <iostream>
#include <fstream>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"

// 系统初始化函数
void System::Initialize(HINSTANCE hInstance, int nCmdShow) {
	// 将实例句柄存储在全局变量中
	h_instance_ = hInstance;

	// Alpha系统初始化信息设置
	sys_init_info_.mAppInstance = hInstance;              // WinMain的第1个参数
	sys_init_info_.mShow = nCmdShow;                      // WinMain的第4个参数
	sys_init_info_.mWinWidth = 800;                       // 窗口宽度
	sys_init_info_.mWinHeight = 600;                      // 窗口高度
	sys_init_info_.mCreateConsole = 1;                    // 是否需要打开控制台，1表示是，0表示否
	sys_init_info_.mCreateWindow = 0;                     // 是否需要创建窗口，1表示是，0表示否
	sys_init_info_.mMaxFrameRate = 60;                    // 设置帧率（使用Alpha的帧率控制功能）
	sys_init_info_.mpWinCallBack = nullptr;               // 因为没用Alpha创建窗口，所以设置为NULL
	sys_init_info_.mClassStyle = CS_HREDRAW | CS_VREDRAW; // 窗口类定义的重绘方式，水平重绘和垂直重绘
	sys_init_info_.mWindowStyle = WS_OVERLAPPEDWINDOW;    // 窗口风格

	// Window Class窗口创建信息设置
	win_class_.style = sys_init_info_.mClassStyle;
	win_class_.lpfnWndProc = Input::Handle;
	win_class_.cbClsExtra = 0;
	win_class_.cbWndExtra = 0;
	win_class_.hInstance = sys_init_info_.mAppInstance;
	win_class_.hIcon = LoadIcon(nullptr, IDI_EXCLAMATION);
	win_class_.hCursor = LoadCursor(nullptr, IDC_ARROW);
	win_class_.hbrBackground = HBRUSH(GetStockObject(GRAY_BRUSH));
	win_class_.lpszMenuName = nullptr;
	win_class_.lpszClassName = "NewGame";

	// 窗口注册
	RegisterClass(&win_class_);

	// 窗口创建
	/**
	 * hWnd = CreateWindow(wndClass.lpszClassName,
	 * "WindowTitle",        窗口标题
	 * WS_OVERLAPPEDWINDOW,  窗口风格
	 * 200,                  窗口左上角X坐标，屏幕左上角是原点(0, 0)
	 * 100,                  窗口左上角Y坐标
	 * 640,                  窗口宽度
	 * 480,                  窗口高度
	 * NULL,                 父窗口的句柄（如果该窗口是子窗口）
	 * NULL,                 菜单句柄
	 * hInstance,            WinMain的第1个参数
	 * NULL);                WM_Create消息传递用到的
	 */
	HWND win_handle = CreateWindow(win_class_.lpszClassName, "从零开始的迷宫大作战", WS_OVERLAPPEDWINDOW,
		                           200, 100, 800, 600, nullptr, nullptr, hInstance, nullptr);
	ShowWindow(win_handle, nCmdShow);
	UpdateWindow(win_handle);

	// 设置Alpha系统窗口句柄
	sys_init_info_.mWindowHandle = win_handle;

	// Alpha系统初始化及模块重置
	AESysInit(&sys_init_info_);
	AESysReset();

	// 分配控制台来帮助debug，把标准输出流重定向到AE系统的控制台
	if (sys_init_info_.mCreateConsole) {
		AllocConsole();
		console_out_.open("CONOUT$");
		streambuf_pointer_ = std::cout.rdbuf(console_out_.rdbuf());
		std::cout << "Console is ready for debug." << std::endl;
	}
	// 之后所有标准输出都会在AE系统的控制台上打印出来

	// 打开文件用于之后写log，该文件成为一个输出的流
	log_file_.open("log.txt", std::ios::out);

	// 写log
	log_file_ << "System: Initialize." << std::endl;
}

// 系统退出函数
void System::Exit() {
	// 如果选择开出AE系统控制台的话
	if (sys_init_info_.mCreateConsole) {
		// 恢复cout的流对象缓冲指针并关闭console_out_流
		std::cout.rdbuf(streambuf_pointer_);
		console_out_.close();
	}

	// Alpha系统退出
	AESysExit();

	// 窗口注销
	UnregisterClass(win_class_.lpszClassName, h_instance_);

	// 写log
	log_file_ << "System: Exit." << std::endl;

	// 关闭文件，结束对log记录文件的写入
	log_file_.close();
}
