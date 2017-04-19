/**
 * Project:      NewGame
 * File Name:    Resource.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      资源类头文件
 */

#pragma once

#include "GameElement.h"

// 资源类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体资源类，成员函数使用虚函数来实现多态
class Resource : public GameElement {
public:

protected:
	virtual ~Resource() {}
};
