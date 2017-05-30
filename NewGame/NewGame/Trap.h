/**
 * Project:      NewGame
 * File Name:    Trap.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      陷阱类头文件
 */

#pragma once

#include "GameElement.h"

// 陷阱类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体陷阱类，成员函数使用虚函数来实现多态
class Trap : public GameElement {
public:
	Trap() {}
	virtual ~Trap() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;

protected:
};
