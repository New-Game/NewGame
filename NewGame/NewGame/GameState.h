/* Project:      NewGame
 * File Name:    GameState.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      游戏状态类头文件
 */

#pragma once

#include "State.h"

//------------------------------------------------------------------------------
// Typedef:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Classes:
//------------------------------------------------------------------------------

// 游戏状态类，继承了State类，同样还是抽象类，不能用于生成对象
// 用于派生具体游戏状态类，所有成员函数均为纯虚函数
class GameState : public State {
public:
	friend class GameStateManager; // 友元声明放在public或private或protected中都可以
	virtual void Process() = 0;
	bool GetIsReadyForNextGameState() const {
		return is_ready_for_next_game_state_;
	}
	void SetIsReadyForNextGameState() {
		is_ready_for_next_game_state_ = true;
	}
protected:
	bool is_ready_for_next_game_state_;
	GameState() : is_ready_for_next_game_state_(false) {}
	GameState(GameState& game_state) {
		is_ready_for_next_game_state_ = game_state.GetIsReadyForNextGameState();
	}
	virtual ~GameState() = 0;
};

// 以下为具体的游戏状态类，所有游戏状态可以抽象为三种类
// 第一种是在状态中按左右方向键来选择人物的
// 第二种是在状态中显示相关信息，按Enter可以进入下一状态的
// 第三种就是关卡状态，每个关卡都是关卡类的一个对象

// 人物选择类，单实例类
class CharacterPick : public GameState {
public:
	~CharacterPick() {}
	void Load() override;
	void Initialize() override;
	void Draw() override;
	void Process() override;
	void Free() override;
	void Unload() override;
private:

};

// 间隔类，多实例类，实例化出：
// 游戏前序、背景故事、关卡1前序、关卡1后续、关卡2前序、关卡2后续、关卡3前序、关卡3后续、奖励环节、游戏后续 这些状态
class Interval : public GameState {
public:
	~Interval() {}
	void Load() override;
	void Initialize() override;
	void Draw() override;
	void Process() override;
	void Free() override;
	void Unload() override;
private:

};

// 关卡类，多实例类，每个关卡都是它的一个对象
class Level : public GameState {
public:
	~Level() {}
	void Load() override;
	void Initialize() override;
	void Draw() override;
	void Process() override;
	void Free() override;
	void Unload() override;
private:

};

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
