/**
 * Project:      NewGame
 * File Name:    GameStateManager.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      游戏状态类管理器类实现文件
 */

#include "GameStateManager.h"
#include "CharacterPick.h"
#include "Interval.h"
#include "Level.h"
#include "System.h"

void GameStateManager::Initialize() {
	game_state_[GAME_PREFACE] = new Interval("test.png");
	game_state_[BACKGROUND_STORY] = new Interval("test.png");
	game_state_[CHARACTER_PICK] = new CharacterPick();
	game_state_[LEVEL1_PREFACE] = new Interval("test.png");
	game_state_[LEVEL1] = new Level("level1"); // level1  关卡1
	game_state_[LEVEL1_ENDING] = new Interval("test.png");
	game_state_[LEVEL2_PREFACE] = new Interval("test.png");
	game_state_[LEVEL2] = new Level("level2"); // level2 关卡2
	game_state_[LEVEL2_ENDING] = new Interval("test.png");
	game_state_[LEVEL3_PREFACE] = new Interval("test.png");
	game_state_[LEVEL3] = new Level("level3"); // level3 关卡3
	game_state_[LEVEL3_ENDING] = new Interval("test.png");
	game_state_[PRIZE] = new Interval("test.png");
	game_state_[GAME_ENDING] = new Interval("test.png");
	game_state_pointer_ = game_state_;

	if (System::GetAESysInitInfo().mCreateConsole)
		cout << "GameStateManager: Initialize." << endl;
}

void GameStateManager::Exit() {
	for (auto i = 0; i < NUM_OF_GAME_STATES; ++i)
		delete game_state_[i];

	if (System::GetAESysInitInfo().mCreateConsole)
		cout << "GameStateManager: Exit." << endl;
}
