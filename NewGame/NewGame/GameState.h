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
protected:
	virtual ~GameState() = 0;
};

// 以下为具体的游戏状态类

// 菜单类，单实例类
class Menu : public GameState {
public:
	~Menu() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// 背景故事类，单实例类
class BackgroundStory : public GameState {
public:
	~BackgroundStory() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// 人物选择类，单实例类
class CharacterPick : public GameState {
public:
	~CharacterPick() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// 关卡前序类，多实例类，每个关卡前的序都是它带的一个对象
class LevelPreface : public GameState {
public:
	~LevelPreface() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
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
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// 奖励类，单实例类
class Prize : public GameState {
public:
	~Prize() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;
	
private:

};

// 结尾花絮类，单实例类
class Ending : public GameState {
public:
	~Ending() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// 最终结尾类，单实例类
class GameOver : public GameState {
public:
	~GameOver() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
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
