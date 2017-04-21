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

#pragma comment (lib, "Alpha_Engine.lib")

// 程序主函数，我们只需要用到第一个和第四个参数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	System::Initialize(hInstance, nCmdShow);
	GameStateManager::Initialize();

	// Game Flow
	while (true) {
		if (!GameStateManager::GetGameState()->GetIsReadyForRestart())
			GameStateManager::GetGameState()->Load();
		else
			GameStateManager::GetGameState()->ResetIsReadyForRestart();

		GameStateManager::GetGameState()->Initialize();
		GameStateManager::GetGameState()->Draw();
		GameStateManager::GetGameState()->Process();
		GameStateManager::GetGameState()->Free();

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

	GameStateManager::Exit();
	System::Exit();

	return 0;
}
