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

void GameStateManager::Start() {
	game_state_[GAME_PREFACE] = new Interval("picture\\game_preface.png");
	game_state_[BACKGROUND_STORY] = new Interval("picture\\background_story.png");
	game_state_[CHARACTER_PICK] = new CharacterPick("picture\\character_pick.png");
	game_state_[LEVEL1_PREFACE] = new Interval("picture\\level1_preface.png");
	game_state_[LEVEL1] = new Level("text\\level1.txt"); // level1  关卡1
	game_state_[LEVEL1_ENDING] = new Interval("picture\\level1_ending.png");
	game_state_[LEVEL2_PREFACE] = new Interval("picture\\level2_preface.png");
	game_state_[LEVEL2] = new Level("text\\level2.txt"); // level2 关卡2
	game_state_[LEVEL2_ENDING] = new Interval("picture\\level2_ending.png");
	game_state_[LEVEL3_PREFACE] = new Interval("picture\\level3_preface.png");
	game_state_[LEVEL3] = new Level("text\\level3.txt"); // level3 关卡3
	game_state_[LEVEL3_ENDING] = new Interval("picture\\level3_ending.png");
	game_state_[PRIZE] = new Interval("picture\\prize.png");
	game_state_[GAME_ENDING] = new Interval("picture\\game_ending.png");
	game_state_pointer_ = game_state_;

	if (System::GetAESysInitInfo().mCreateConsole)
		cout << "GameStateManager: Initialize." << endl;
}

void GameStateManager::End() {
	//for (auto i = 0; i < NUM_OF_GAME_STATES; ++i)
		//delete game_state_[i];
	for (auto& i : game_state_)
		delete i;

	if (System::GetAESysInitInfo().mCreateConsole)
		cout << "GameStateManager: Exit." << endl;
}
