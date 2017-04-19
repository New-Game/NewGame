/**
 * Project:      NewGame
 * File Name:    GameStateManager.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      ��Ϸ״̬���������ʵ���ļ�
 */

#include "GameStateManager.h"
#include "CharacterPick.h"
#include "Interval.h"
#include "Level.h"
#include "System.h"

void GameStateManager::Initialize() {
	game_state_[GAME_PREFACE] = new Interval();
	game_state_[BACKGROUND_STORY] = new Interval();
	game_state_[CHARACTER_PICK] = new CharacterPick();
	game_state_[LEVEL1_PREFACE] = new Interval();
	game_state_[LEVEL1] = new Level(); // level1 �ؿ�1
	game_state_[LEVEL1_ENDING] = new Interval();
	game_state_[LEVEL2_PREFACE] = new Interval();
	game_state_[LEVEL2] = new Level(); // level2 �ؿ�2
	game_state_[LEVEL2_ENDING] = new Interval();
	game_state_[LEVEL3_PREFACE] = new Interval();
	game_state_[LEVEL3] = new Level(); // level3 �ؿ�3
	game_state_[LEVEL3_ENDING] = new Interval();
	game_state_[PRIZE] = new Interval();
	game_state_[GAME_ENDING] = new Interval();
	game_state_pointer_ = game_state_;

	// дlog
	System::GetLogFile() << "GameStateManager: Initialize." << endl;
}

void GameStateManager::Exit() {
	for (auto i = 0; i < NUM_OF_GAME_STATES; ++i)
		delete game_state_[i];

	// дlog
	System::GetLogFile() << "GameStateManager: Exit." << endl;
}
