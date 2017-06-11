/**
 * Project:      NewGame
 * File Name:    main.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      游戏main函所在文件，main函数实现Game Loop
 */

#include <Windows.h>
#include "GameStateManager.h"
#include "System.h"
#include<mmsystem.h>
#include<Digitalv.h>
#include <mciapi.h>

#pragma comment (lib, "Alpha_Engine.lib")
#pragma comment (lib,"winmm.lib")

void Play() {
	AllocConsole();
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
	
	MCI_OPEN_PARMS mciopen;
	MCI_PLAY_PARMS play;
	mciopen.lpstrDeviceType = "mpegvideo";
	mciopen.lpstrElementName = "C:\\music\\menu.wav";
	MCIERROR mcierror=mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciopen);
	if(mcierror) {
		WriteConsole(hd, "hello hplonline", sizeof("hello hplonline"), NULL, NULL);
		}
	UINT device = mciopen.wDeviceID;
	mcierror=mciSendCommand(device, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)&play);
	if (mcierror) {
		WriteConsole(hd, "hello hplonline", sizeof("hello hplonline"), NULL, NULL);
		CloseHandle(hd);
	}
}

// 程序主函数，我们只需要用到第一个和第四个参数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	Play();
	System::Start(hInstance, nCmdShow);
	GameStateManager::Start();
	
	// Game Flow
	while (true) {
		//PlaySound("menu.wav", NULL, SND_FILENAME | SND_ASYNC);
		if (!GameStateManager::GetGameState()->GetIsReadyForRestart())
			GameStateManager::GetGameState()->Load();
		else {
			GameStateManager::GetGameState()->Reset();
			GameStateManager::GetGameState()->ResetIsReadyForRestart();
		}

		GameStateManager::GetGameState()->Process();

		if (!GameStateManager::GetGameState()->GetIsReadyForRestart())
			GameStateManager::GetGameState()->Unload();
		else
			continue;

		if (GameStateManager::GetGameState()->GetIsReadyForExit())
			break;

		if (GameStateManager::HasNextGameState())
			GameStateManager::NextGameState();
		else
			break;
	}

	GameStateManager::End();
	System::End();

	return 0;
}
