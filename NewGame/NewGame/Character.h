/**
 * Project:      NewGame
 * File Name:    Character.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      人物类头文件
 */

#pragma once

#include "GameElement.h"

// 人物类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体人物类，成员函数使用虚函数来实现多态
class Character : public GameElement {
public:

protected:
	virtual ~Character() {}
};
