/**
 * Project:      NewGame
 * File Name:    main.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ��Ϸmain�������ļ���main����ʵ��Game Loop
 */

#include <Windows.h>
#include "GameStateManager.h"
#include "System.h"

#pragma comment (lib, "Alpha_Engine.lib")

// ����������������ֻ��Ҫ�õ���һ���͵��ĸ�����
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
