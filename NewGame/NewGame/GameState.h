/**
 * Project:      NewGame
 * File Name:    GameState.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      游戏状态类头文件
 */

#pragma once

#include "State.h"

// 游戏状态类，继承了State类，同样还是抽象类，不能用于生成对象
// 用于派生具体游戏状态类，成员函数使用虚函数来实现多态

// 所有游戏状态可以抽象为三种类
// 第一种是在状态中按左右方向键来选择人物的
// 第二种是在状态中显示相关信息，按Enter可以进入下一状态的
// 第三种就是关卡状态，每个关卡都是关卡类的一个对象

class GameState : public State {
public:
	GameState() : is_ready_for_next_game_state_(false),
	              is_ready_for_restart_(false),
	              is_ready_for_game_ending_(false) {}

	virtual ~GameState() {}

	// 用来给子类（派生类）重写的 纯虚函数，每个子类都必须重写这个函数来定义其游戏状态的运行方式
	virtual void Process() = 0;

	bool GetIsReadyForNextGameState() const {
		return is_ready_for_next_game_state_;
	}

	bool GetIsReadyForRestart() const {
		return is_ready_for_restart_;
	}

	bool GetIsReadyForGameEnding() const {
		return is_ready_for_game_ending_;
	}

	// 在非关卡状态时按下Enter键时调用，结束该状态，准备进入下一状态
	void SetIsReadyForNextGameState() {
		is_ready_for_next_game_state_ = true;
	}

	// 在关卡状态时按下Backspace时调用，准备重新开始本关
	void SetIsReadyForRestart() {
		is_ready_for_restart_ = true;
	}

	// 在已经重新进入本状态准备初始化本状态前调用，重置flag数值
	void ResetIsReadyForRestart() {
		is_ready_for_restart_ = false;
	}

	// 在任何状态下按下ESC键时调用，准备进入GameEnding状态
	void SetIsReadyForGameEnding() {
		is_ready_for_game_ending_ = true;
	}

protected:
	// 用来控制游戏流程的flag
	bool is_ready_for_next_game_state_;
	bool is_ready_for_restart_;
	bool is_ready_for_game_ending_;
};
