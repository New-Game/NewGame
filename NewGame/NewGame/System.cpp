/* Project:      NewGame
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
// ϵͳ��ʼ������
void System::Initialize(HINSTANCE hInstance, int nCmdShow) {
	// ����Alpha��������
	sys_init_info_.mAppInstance = hInstance;  // WinMain�ĵ�1������
	sys_init_info_.mShow = nCmdShow;		  // WinMain�ĵ�4������
	sys_init_info_.mWinWidth = 800;
	sys_init_info_.mWinHeight = 400;
	sys_init_info_.mCreateConsole = 1;        // �Ƿ���Ҫ�򿪿���̨��1��ʾ�ǣ�0��ʾ��
	sys_init_info_.mCreateWindow = 1;         // �Ƿ���Ҫ�������ڣ�1��ʾ�ǣ�0��ʾ��
	sys_init_info_.mMaxFrameRate = 60;        // ����֡�ʣ����ʹ��Alpha��֡�ʿ��ƹ��ܵĻ���
	sys_init_info_.mpWinCallBack = Input::Handle;
	sys_init_info_.mClassStyle = CS_HREDRAW | CS_VREDRAW;  // �����ඨ����ػ淽ʽ��ˮƽ�ػ�ʹ�ֱ�ػ�
	sys_init_info_.mWindowStyle = WS_OVERLAPPEDWINDOW;     // ���ڷ��

	// Alphaϵͳ��ʼ������¼����ֵ
	int AESysInit_return_value = AESysInit(&sys_init_info_);

	// �������̨������debug���ѱ�׼������ض���AEϵͳ�Ŀ���̨
	if (sys_init_info_.mCreateConsole) {
		AllocConsole();
		console_out_.open("CONOUT$");
		streambuf_pointer_ = cout.rdbuf(console_out_.rdbuf());
		cout << "Console is ready for debug." << endl;
	}
	// ֮�����б�׼���������AEϵͳ�Ŀ���̨�ϴ�ӡ����

	// ���ļ�����֮��дlog�����ļ���Ϊһ���������
	log_file_.open("log.txt", ios::out);
	// ������ļ�ʧ�ܣ������̨���������Ϣ����ֱ���˳�����
	if (!log_file_) {
		cout << "Fail to open the log file!" << endl;
		log_file_ << "Fail to open the log file!" << endl;
		exit(EXIT_FAILURE);
	}

	// ���ϵͳ��ʼ��ʧ�ܣ������̨���������Ϣ����ֱ���˳�����
	if (AESysInit_return_value == 0) {
		cout << "Fail to init the AE system!" << endl;
		log_file_ << "Fail to open the log file!" << endl;
		exit(EXIT_FAILURE);
	}

	// Alphaϵͳģ������
	AESysReset();

	// �޸Ĵ��ڱ���
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

	// дlog
	log_file_ << "System: Initialize." << endl;
}

// ϵͳ�˳�����
void System::Exit() {
	// ���ѡ�񿪳�AEϵͳ����̨�Ļ�
	if (sys_init_info_.mCreateConsole) {
		// �ָ�cout�������󻺳�ָ�벢�ر�console_out_��
		cout.rdbuf(streambuf_pointer_);
		console_out_.close();
	}

	// Alphaϵͳ�˳�
	AESysExit();

	// дlog
	log_file_ << "System: Exit." << endl;

	// �ر��ļ���������log��¼�ļ���д��
	log_file_.close();
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
