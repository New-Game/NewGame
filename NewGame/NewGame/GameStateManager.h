/**
 * Project:      NewGame
 * File Name:    GameStateManager.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      游戏状态管理器类头文件
 */

#pragma once

#include "GameState.h"

enum GameStates {
	GAME_PREFACE,
	BACKGROUND_STORY,
	CHARACTER_PICK,
	LEVEL1_PREFACE,
	LEVEL1,
	LEVEL1_ENDING,
	LEVEL2_PREFACE,
	LEVEL2,
	LEVEL2_ENDING,
	LEVEL3_PREFACE,
	LEVEL3,
	LEVEL3_ENDING,
	PRIZE,
	GAME_ENDING,
	NUM_OF_GAME_STATES
};

// GameStateManager类的实现完全只是为了封装与它相关的状态量（成员变量）和行为（成员函数）
// 因此它的成员都是static的，static成员变量相当于全局变量，static成员函数相当于全局函数
// GameStateManeger类不能用于生成对象（实例）
class GameStateManager {
public:
	// 初始化游戏状态管理器
	static void Start();

	// 退出游戏状态管理器
	static void End();

	// 返回指向当前游戏状态的指针
	static GameState* GetGameState() {
		return *game_state_pointer_;
	}

	// 是否还有下一个游戏状态
	static bool HasNextGameState() {
		return game_state_pointer_ != game_state_ + GAME_ENDING;
	}

	// 把当前游戏状态更新为下一个状态（必须在HasNextGameState()返回true的情况下调用）
	static void NextGameState() {
		++game_state_pointer_;
	}

private:
	static GameState* game_state_[NUM_OF_GAME_STATES];
	static GameState** game_state_pointer_;
};
