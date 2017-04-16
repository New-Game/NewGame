/* Project:      NewGame
 * File Name:    System.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ϵͳ������ʵ���ļ�
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
// ϵͳ��ʼ������
int SystemInitialize(HINSTANCE hInstance, int nCmdShow) {
	// ����Alpha��������
	AESysInitInfo sysInitInfo;
	sysInitInfo.mAppInstance = hInstance;  // WinMain�ĵ�1������
	sysInitInfo.mShow = nCmdShow;		   // WinMain�ĵ�4������
	sysInitInfo.mWinWidth = 800;
	sysInitInfo.mWinHeight = 400;
	sysInitInfo.mCreateConsole = 0;        // �Ƿ���Ҫ�򿪿���̨��1��ʾ�ǣ�0��ʾ��
	sysInitInfo.mCreateWindow = 1;         // �Ƿ���Ҫ�������ڣ�1��ʾ�ǣ�0��ʾ��
	sysInitInfo.mMaxFrameRate = 60;        // ����֡�ʣ����ʹ��Alpha��֡�ʿ��ƹ��ܵĻ���
	sysInitInfo.mpWinCallBack = InputHandle;
	sysInitInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;  // �����ඨ����ػ淽ʽ��ˮƽ�ػ�ʹ�ֱ�ػ�
	sysInitInfo.mWindowStyle = WS_OVERLAPPEDWINDOW;     // ���ڷ��

	// Alphaϵͳ��ʼ�� �� ģ������
	if (0 == AESysInit(&sysInitInfo))
		return -1;
	AESysReset();
	// �޸Ĵ��ڱ���
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

	// ��ǩ����
	//if ((fp = fopen("Output.txt", "w")) == NULL) {
	//	printf("Cannot find file Output.txt\n");
	//	return -1;
	//}
	// ǩ��
	//fprintf(fp, "System:Initialize\n");

	return 0;
}

// ϵͳ�˳�����
void SystemExit() {
	// Alphaϵͳ�˳�
	AESysExit();

	// ǩ��
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
