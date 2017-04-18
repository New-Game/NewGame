/* Project:      NewGame
 * File Name:    GameStateManager.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      游戏状态管理器类头文件
 */

#pragma once

#include "GameState.h"

//------------------------------------------------------------------------------
// Typedef:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

enum GameStates {
	MENU,
	BACKGROUND_STORY,
	CHARACTER_PICK,
	LEVEL1_PREFACE,
	LEVEL1,
	LEVEL2_PREFACE,
	LEVEL2,
	LEVEL3_PREFACE,
	LEVEL3,
	PRIZE,
	ENDING,
	GAME_OVER,
	NUM_OF_GAME_STATES
};

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Classes:
//------------------------------------------------------------------------------

// GameStateManager类的实现完全只是为了封装与它相关的状态量（成员变量）和行为（成员函数）
// 因此它的成员都是static的，static成员变量相当于全局变量，static成员函数相当于全局函数
// GameStateManeger类不能用于生成对象（实例）
class GameStateManager {
public:
	// 初始化游戏状态管理器
	static void Initialize();

	// 退出游戏状态管理器
	static void Exit();

	// 返回指向当前游戏状态的指针
	static GameState* GetGameState() {
		return *game_state_pointer_;
	}

	// 是否还有下一个游戏状态
	static bool HaveNextGameState() {
		return *game_state_pointer_ != game_state_[GAME_OVER];
	}

	// 把当前游戏状态更新为下一个状态（必须在HaveNextGameState()返回true的情况下调用）
	static void NextGameState() {
		++game_state_pointer_;
	}

	// 只能在当前状态为Level1或者Level2或者Level3时才能调用该函数
	// 从第一关重新开始（即先在当前状态执行Free()和Unload()，再把当前状态设为Level1）
	static void RestartFromBeginning();

	// 只能在当前状态为Level1或者Level2或者Level3时才能调用该函数
	// 从当前关重新开始（先在当前状态执行Free()，再从头开始执行该状态）
	static void RestartFromCurrentLevel();

	// 推出游戏
	static void Quit();

	// 暂停当前状态
	static void Pause();

	// 继续当前状态
	static void Resume();

private:
	static GameState* game_state_[NUM_OF_GAME_STATES];
	static GameState** game_state_pointer_;
};

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
