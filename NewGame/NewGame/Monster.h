/**
 * Project:      NewGame
 * File Name:    Monster.h
 * Author:       Atlas/Long
 * Date:         2017/4/18
 * Purpose:      怪物类头文件
 */

#pragma once

#include "GameElement.h"

// 怪物类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体怪物类，成员函数使用虚函数来实现多态
class Monster : public GameElement {
public:
	Monster(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name), speed_(2) {}
	Monster() : speed_(2) {}
	virtual ~Monster() {}

protected:
	int speed_;

	void Move();
	void DropBuff();
};
