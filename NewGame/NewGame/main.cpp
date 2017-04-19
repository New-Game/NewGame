/* Project:      NewGame
 * File Name:    main.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      游戏main函所在文件，main函数实现Game Loop
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

// 程序主函数，我们只需要用到第一个和第四个参数
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
