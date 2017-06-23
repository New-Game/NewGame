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
#include <mmsystem.h>
#include <Digitalv.h>
#include <windows.h>
#include "Menu.h"
#pragma comment(lib,"WinMM.Lib")

void GameStateManager::Start() {
	/*for(int i=0;i<=9;i++) {
		GameState::mciopen[i].lpstrDeviceType = "mpegvedio";
		GameState::mciopen[i].lpstrElementName = music[i];
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)& GameState::mciopen[i]);
		GameState::ID[i] = GameState::mciopen[i].wDeviceID;
	}*/
	game_state_list_[GAME_PREFACE] = new Interval("picture\\game_preface.png");
	game_state_list_[MENU] = new Menu("picture\\game_start.png");
	game_state_list_[BACKGROUND_STORY] = new Interval("picture\\story1.png");
	game_state_list_[EMILIA] = new Interval("picture\\introduction2.png");
	game_state_list_[REMRAM] = new Interval("picture\\introduction1.png");
	game_state_list_[CHARACTER_PICK] = new CharacterPick();
	game_state_list_[LEVEL1_PREFACE] = new Interval("picture\\level1_preface.png");
	game_state_list_[LEVEL1] = new Level("text\\level1.txt"); // level1  关卡1
	game_state_list_[LEVEL1_ENDING] = new Interval("picture\\level1_ending.png");
	game_state_list_[LEVEL2_PREFACE] = new Interval("picture\\level2_preface.png");
	game_state_list_[LEVEL2] = new Level("text\\level2.txt"); // level2 关卡2
	game_state_list_[LEVEL2_ENDING] = new Interval("picture\\level2_ending.png");
	game_state_list_[LEVEL3_PREFACE] = new Interval("picture\\level3_preface.png");
	game_state_list_[LEVEL3] = new Level("text\\level3.txt"); // level3 关卡3
	game_state_list_[LEVEL3_ENDING] = new Interval("picture\\level3_ending.png");
	game_state_list_[PRIZE] = new Interval("picture\\prize.png");
	game_state_list_[GAME_ENDING] = new Interval("picture\\game_ending.png");
	game_state_pointer_ = game_state_list_;

	//if (System::GetAESysInitInfo().mCreateConsole)
	//	cout << "GameStateManager: Initialize." << endl;
}

void GameStateManager::End() {
	for (auto& i : game_state_list_)
		delete i;

	//if (System::GetAESysInitInfo().mCreateConsole)
	//	cout << "GameStateManager: Exit." << endl;
}
