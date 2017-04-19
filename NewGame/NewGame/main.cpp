/* Project:      NewGame
 * File Name:    main.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ��Ϸmain�������ļ���main����ʵ��Game Loop
 */

#include <iostream>
#include <Windows.h>
#include "AEEngine.h"
#include "GameStateManager.h"
#include "System.h"
#include "Global.h"

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

// ����������������ֻ��Ҫ�õ���һ���͵��ĸ�����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	System::Initialize(hInstance, nCmdShow);
	GameStateManager::Initialize();
	while (true) {
		GameStateManager::GetGameState()->Load();
		GameStateManager::GetGameState()->Initialize();
		while (!GameStateManager::GetGameState()->GetIsReadyForNextGameState()) {
			AESysFrameStart();
			GameStateManager::GetGameState()->Draw();
			GameStateManager::GetGameState()->Process();
			AESysFrameEnd();
		}
		GameStateManager::GetGameState()->Free();
		GameStateManager::GetGameState()->Unload();
		if (GameStateManager::HasNextGameState())
			GameStateManager::NextGameState();
		else
			break;
	}
	GameStateManager::Exit();
	System::Exit();
	return 0;
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
