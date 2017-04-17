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
	// ���ļ�����֮��дlog�����ļ���Ϊһ�������������
	out_file_log.open("log.txt", ios::out);
	// ������ļ�ʧ�ܣ������̨���������Ϣ����ֱ���˳�����
	if (!out_file_log) {
		clog << "Fail to open the log file!" << endl;
		exit(EXIT_FAILURE);
	}

	// ����Alpha��������
	AESysInitInfo sysInitInfo;
	sysInitInfo.mAppInstance = hInstance;  // WinMain�ĵ�1������
	sysInitInfo.mShow = nCmdShow;		   // WinMain�ĵ�4������
	sysInitInfo.mWinWidth = 800;
	sysInitInfo.mWinHeight = 400;
	sysInitInfo.mCreateConsole = 1;        // �Ƿ���Ҫ�򿪿���̨��1��ʾ�ǣ�0��ʾ��
	sysInitInfo.mCreateWindow = 1;         // �Ƿ���Ҫ�������ڣ�1��ʾ�ǣ�0��ʾ��
	sysInitInfo.mMaxFrameRate = 60;        // ����֡�ʣ����ʹ��Alpha��֡�ʿ��ƹ��ܵĻ���
	sysInitInfo.mpWinCallBack = Input::Handle;
	sysInitInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;  // �����ඨ����ػ淽ʽ��ˮƽ�ػ�ʹ�ֱ�ػ�
	sysInitInfo.mWindowStyle = WS_OVERLAPPEDWINDOW;     // ���ڷ��

	// Alphaϵͳ��ʼ��
	// ���ϵͳ��ʼ��ʧ�ܣ������̨���������Ϣ����ֱ���˳�����
	if (0 == AESysInit(&sysInitInfo)) {
		clog << "Fail to init the AE system!" << endl;
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
	out_file_log << "System: Initialize." << endl;
}

// ϵͳ�˳�����
void System::Exit() {
	// Alphaϵͳ�˳�
	AESysExit();

	// дlog
	out_file_log << "System: Exit." << endl;

	// �ر��ļ���������log��¼�ļ���д��
	out_file_log.close();
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
