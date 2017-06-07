/**
 * Project:      NewGame
 * File Name:    System.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ϵͳ������ʵ���ļ�
 */

#include <iostream>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"
#include "Global.h"
#include "resource.h"
#include <winuser.h>

using namespace std;

// ϵͳ��ʼ������
void System::Start(HINSTANCE hInstance, int nCmdShow) {
	// ��ʵ������洢��ȫ�ֱ�����
	instance_ = hInstance;

	// Alphaϵͳ��ʼ����Ϣ����
	sys_init_info_.mAppInstance = hInstance;              // WinMain�ĵ�1������
	sys_init_info_.mShow = nCmdShow;                      // WinMain�ĵ�4������
	sys_init_info_.mWinWidth = window_width_;             // ���ڿ��
	sys_init_info_.mWinHeight = window_height_;           // ���ڸ߶�
	sys_init_info_.mCreateConsole = 0;                    // �Ƿ���Ҫ�򿪿���̨��1��ʾ�ǣ�0��ʾ��
	sys_init_info_.mCreateWindow = 0;                     // �Ƿ���Ҫ�������ڣ�1��ʾ�ǣ�0��ʾ��
	sys_init_info_.mMaxFrameRate = frame_rate_;           // ����֡�ʣ�ʹ��Alpha��֡�ʿ��ƹ��ܣ�
	sys_init_info_.mpWinCallBack = nullptr;               // ��Ϊû��Alpha�������ڣ���������ΪNULL
	sys_init_info_.mClassStyle = CS_HREDRAW | CS_VREDRAW; // �����ඨ����ػ淽ʽ��ˮƽ�ػ�ʹ�ֱ�ػ�
	sys_init_info_.mWindowStyle = WS_OVERLAPPEDWINDOW;    // ���ڷ��

	// Window Class���ڴ�����Ϣ����
	win_class_.style = sys_init_info_.mClassStyle;
	win_class_.lpfnWndProc = Input::MainHandle;
	win_class_.cbClsExtra = 0;
	win_class_.cbWndExtra = 0;
	win_class_.hInstance = sys_init_info_.mAppInstance;
	win_class_.hIcon = LoadIcon(win_class_.hInstance, MAKEINTRESOURCE(IDI_APP_ICON));
	win_class_.hCursor = LoadCursor(nullptr, IDC_ARROW);
	win_class_.hbrBackground = HBRUSH(GetStockObject(WHITE_BRUSH));
	win_class_.lpszMenuName = nullptr;
	win_class_.lpszClassName = LPCSTR("NewGame");
	RegisterClass(&win_class_);

	// ���ڴ���
	/**
	 * hWnd = CreateWindow(wndClass.lpszClassName,
	 * "WindowTitle",        ���ڱ���
	 * WS_OVERLAPPEDWINDOW,  ���ڷ��
	 * 0,                    �������Ͻ�X���꣬��Ļ���Ͻ���ԭ��(0, 0)
	 * 0,                    �������Ͻ�Y����
	 * WINDOW_WIDTH,         ���ڿ��
	 * WINDOW_HEIGHT,        ���ڸ߶�
	 * NULL,                 �����ڵľ��������ô������Ӵ��ڣ�
	 * NULL,                 �˵����
	 * hInstance,            WinMain�ĵ�1������
	 * NULL);                WM_Create��Ϣ�����õ���
	 */
	handle_ = CreateWindow(win_class_.lpszClassName, LPCSTR("���㿪ʼ���Թ�����ս"), WS_OVERLAPPEDWINDOW, 0, 0, window_width_, window_height_, nullptr, nullptr, hInstance, nullptr);
	ShowWindow(handle_, nCmdShow);
	UpdateWindow(handle_);

	// ����Alphaϵͳ���ھ��
	sys_init_info_.mWindowHandle = handle_;

	// Alphaϵͳ��ʼ����ģ������
	AESysInit(&sys_init_info_);
	AESysReset();

	// ����������ԭ����Ϊ��Ļ���Ͻ�
	AEGfxSetWorldOriginMode(AE_WOM_TOP_LEFT);

	//// �������̨������debug���ѱ�׼������ض���AEϵͳ�Ŀ���̨
	//if (sys_init_info_.mCreateConsole) {
	//	AllocConsole();
	//	console_out_.open("CONOUT$");
	//	streambuf_pointer_ = cout.rdbuf(console_out_.rdbuf());
	//	cout << "Console is ready for debug." << endl;
	//}
	//// ֮�����б�׼���������AEϵͳ�Ŀ���̨�ϴ�ӡ����

	//if (sys_init_info_.mCreateConsole)
	//	cout << "System: Initialize." << endl;
}

// ϵͳ�˳�����
void System::End() {
	//if (sys_init_info_.mCreateConsole)
	//	cout << "System: Exit." << endl;

	//// ���ѡ�񿪳�AEϵͳ����̨�Ļ�
	//if (sys_init_info_.mCreateConsole) {
	//	// �ָ�cout�������󻺳�ָ�벢�ر�console_out_��
	//	cout.rdbuf(streambuf_pointer_);
	//	console_out_.close();
	//}

	// Alphaϵͳ�˳�
	AESysExit();

	// ����ע��
	UnregisterClass(win_class_.lpszClassName, instance_);
}
