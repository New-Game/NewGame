/**
 * Project:      NewGame
 * File Name:    Resource.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      物品类头文件
 */

#pragma once

#include "GameElement.h"

// 物品类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体游戏物品类，成员函数使用虚函数来实现多态
class Item : public GameElement {
public:
	Item(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name) {}
	Item() {}
	virtual ~Item() {}
protected:
};

