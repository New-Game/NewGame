/**
 * Project:      NewGame
 * File Name:    State.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      状态类头文件
 */

#pragma once

// 状态类，这是一个抽象类（存在纯虚函数），不能用于生成对象，成员函数使用虚函数来实现多态
// 相当于一个接口，为所有游戏对象（包括游戏状态和游戏元素）提供实现所需的函数
class State {
public:
	virtual void Load() = 0;
	virtual void Reset() = 0;
	virtual void Unload() = 0;
protected:
	virtual ~State() {}
};
