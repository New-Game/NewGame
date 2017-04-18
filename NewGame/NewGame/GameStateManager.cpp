/* Project:      NewGame
 * File Name:    GameStateManager.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      游戏状态类管理器类实现文件
 */

#include "GameStateManager.h"
#include "GameState.h"
#include "System.h"

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

void GameStateManager::Initialize() {
	game_state_[MENU] = new Menu();
	game_state_[BACKGROUND_STORY] = new BackgroundStory();
	game_state_[CHARACTER_PICK] = new CharacterPick();
	game_state_[LEVEL1_PREFACE] = new LevelPreface();
	game_state_[LEVEL1] = new Level(); // level1 关卡1
	game_state_[LEVEL2_PREFACE] = new LevelPreface();
	game_state_[LEVEL2] = new Level(); // level2 关卡2
	game_state_[LEVEL3_PREFACE] = new LevelPreface();
	game_state_[LEVEL3] = new Level(); // level3 关卡3
	game_state_[PRIZE] = new Prize();
	game_state_[ENDING] = new Ending();
	game_state_[GAME_OVER] = new GameOver();
	game_state_pointer_ = game_state_;

	// 写log
	System::log_file_ << "GameStateManager: Initialize." << endl;
}

void GameStateManager::Exit() {
	for (int i = 0; i < NUM_OF_GAME_STATES; ++i)
		delete game_state_[i];

	// 写log
	System::log_file_ << "GameStateManager: Exit." << endl;
}

void GameStateManager::RestartFromBeginning() {
	
}

void GameStateManager::RestartFromCurrentLevel() {
	
}

void GameStateManager::Quit() {
	
}

void GameStateManager::Pause() {
	
}

void GameStateManager::Resume() {
	
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
