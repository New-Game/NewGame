/**
 * Project:      NewGame
 * File Name:    System.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ϵͳ������ʵ���ļ�
 */

#include <iostream>
#include <fstream>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"

// ϵͳ��ʼ������
void System::Initialize(HINSTANCE hInstance, int nCmdShow) {
	// ��ʵ������洢��ȫ�ֱ�����
	h_instance_ = hInstance;

	// Alphaϵͳ��ʼ����Ϣ����
	sys_init_info_.mAppInstance = hInstance;              // WinMain�ĵ�1������
	sys_init_info_.mShow = nCmdShow;                      // WinMain�ĵ�4������
	sys_init_info_.mWinWidth = 800;                       // ���ڿ��
	sys_init_info_.mWinHeight = 600;                      // ���ڸ߶�
	sys_init_info_.mCreateConsole = 1;                    // �Ƿ���Ҫ�򿪿���̨��1��ʾ�ǣ�0��ʾ��
	sys_init_info_.mCreateWindow = 0;                     // �Ƿ���Ҫ�������ڣ�1��ʾ�ǣ�0��ʾ��
	sys_init_info_.mMaxFrameRate = 60;                    // ����֡�ʣ�ʹ��Alpha��֡�ʿ��ƹ��ܣ�
	sys_init_info_.mpWinCallBack = nullptr;               // ��Ϊû��Alpha�������ڣ���������ΪNULL
	sys_init_info_.mClassStyle = CS_HREDRAW | CS_VREDRAW; // �����ඨ����ػ淽ʽ��ˮƽ�ػ�ʹ�ֱ�ػ�
	sys_init_info_.mWindowStyle = WS_OVERLAPPEDWINDOW;    // ���ڷ��

	// Window Class���ڴ�����Ϣ����
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

	// ����ע��
	RegisterClass(&win_class_);

	// ���ڴ���
	/**
	 * hWnd = CreateWindow(wndClass.lpszClassName,
	 * "WindowTitle",        ���ڱ���
	 * WS_OVERLAPPEDWINDOW,  ���ڷ��
	 * 200,                  �������Ͻ�X���꣬��Ļ���Ͻ���ԭ��(0, 0)
	 * 100,                  �������Ͻ�Y����
	 * 640,                  ���ڿ��
	 * 480,                  ���ڸ߶�
	 * NULL,                 �����ڵľ��������ô������Ӵ��ڣ�
	 * NULL,                 �˵����
	 * hInstance,            WinMain�ĵ�1������
	 * NULL);                WM_Create��Ϣ�����õ���
	 */
	HWND win_handle = CreateWindow(win_class_.lpszClassName, "���㿪ʼ���Թ�����ս", WS_OVERLAPPEDWINDOW,
		                           200, 100, 800, 600, nullptr, nullptr, hInstance, nullptr);
	ShowWindow(win_handle, nCmdShow);
	UpdateWindow(win_handle);

	// ����Alphaϵͳ���ھ��
	sys_init_info_.mWindowHandle = win_handle;

	// Alphaϵͳ��ʼ����ģ������
	AESysInit(&sys_init_info_);
	AESysReset();

	// �������̨������debug���ѱ�׼������ض���AEϵͳ�Ŀ���̨
	if (sys_init_info_.mCreateConsole) {
		AllocConsole();
		console_out_.open("CONOUT$");
		streambuf_pointer_ = std::cout.rdbuf(console_out_.rdbuf());
		std::cout << "Console is ready for debug." << std::endl;
	}
	// ֮�����б�׼���������AEϵͳ�Ŀ���̨�ϴ�ӡ����

	// ���ļ�����֮��дlog�����ļ���Ϊһ���������
	log_file_.open("log.txt", std::ios::out);

	// дlog
	log_file_ << "System: Initialize." << std::endl;
}

// ϵͳ�˳�����
void System::Exit() {
	// ���ѡ�񿪳�AEϵͳ����̨�Ļ�
	if (sys_init_info_.mCreateConsole) {
		// �ָ�cout�������󻺳�ָ�벢�ر�console_out_��
		std::cout.rdbuf(streambuf_pointer_);
		console_out_.close();
	}

	// Alphaϵͳ�˳�
	AESysExit();

	// ����ע��
	UnregisterClass(win_class_.lpszClassName, h_instance_);

	// дlog
	log_file_ << "System: Exit." << std::endl;

	// �ر��ļ���������log��¼�ļ���д��
	log_file_.close();
}
