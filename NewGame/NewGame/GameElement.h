/**
 * Project:      NewGame
 * File Name:    GameElement.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      游戏元素类头文件
 */

#pragma once

#include "State.h"
#include "Level.h"

// 游戏元素类，继承了State类，同样还是抽象类，不能用于生成对象
// 用于派生具体游戏元素类，成员函数使用虚函数来实现多态
class GameElement : public State {
public:
	GameElement() : picture_file_name_(nullptr), mesh_(nullptr), texture_(nullptr) {}
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	virtual ~GameElement() {}
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
