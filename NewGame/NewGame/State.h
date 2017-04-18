/* Project:      NewGame
 * File Name:    State.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      状态类头文件
 */

#pragma once

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

// 状态类，这是一个纯抽象类，不能用于生成对象，所有成员函数都是纯虚函数
// 相当于一个接口，为所有游戏对象（包括游戏状态和游戏元素）提供实现所需的函数
class State {
public:
	virtual void Load() = 0;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Free() = 0;
	virtual void Unload() = 0;
protected:
	virtual ~State() = 0;
};

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

