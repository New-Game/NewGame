/**
 * Project:      NewGame
 * File Name:    System.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ϵͳ������ʵ���ļ�
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"

// ϵͳ��ʼ������
void System::Initialize(HINSTANCE hInstance, int nCmdShow) {
	// ����Alpha��������
	sys_init_info_.mAppInstance = hInstance;  // WinMain�ĵ�1������
	sys_init_info_.mShow = nCmdShow;          // WinMain�ĵ�4������
	sys_init_info_.mWinWidth = 800;
	sys_init_info_.mWinHeight = 400;
	sys_init_info_.mCreateConsole = 1;        // �Ƿ���Ҫ�򿪿���̨��1��ʾ�ǣ�0��ʾ��
	sys_init_info_.mCreateWindow = 1;         // �Ƿ���Ҫ�������ڣ�1��ʾ�ǣ�0��ʾ��
	sys_init_info_.mMaxFrameRate = 60;        // ����֡�ʣ����ʹ��Alpha��֡�ʿ��ƹ��ܵĻ���
	sys_init_info_.mpWinCallBack = Input::Handle;
	sys_init_info_.mClassStyle = CS_HREDRAW | CS_VREDRAW;  // �����ඨ����ػ淽ʽ��ˮƽ�ػ�ʹ�ֱ�ػ�
	sys_init_info_.mWindowStyle = WS_OVERLAPPEDWINDOW;     // ���ڷ��

	// Alphaϵͳ��ʼ������¼����ֵ
	auto AESysInit_return_value = AESysInit(&sys_init_info_);

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
	// ������ļ�ʧ�ܣ������̨���������Ϣ����ֱ���˳�����
	if (!log_file_) {
		std::cout << "Fail to open the log file!" << std::endl;
		log_file_ << "Fail to open the log file!" << std::endl;
		exit(EXIT_FAILURE);
	}

	// ���ϵͳ��ʼ��ʧ�ܣ������̨���������Ϣ����ֱ���˳�����
	if (AESysInit_return_value == 0) {
		std::cout << "Fail to init the AE system!" << std::endl;
		log_file_ << "Fail to open the log file!" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Alphaϵͳģ������
	AESysReset();

	// �޸Ĵ��ڱ���
	AESysSetWindowTitle("New Game!");

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

	// дlog
	log_file_ << "System: Exit." << std::endl;

	// �ر��ļ���������log��¼�ļ���д��
	log_file_.close();
}
