/**
 * Project:      NewGame
 * File Name:    GameElement.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      游戏元素类头文件
 */

#pragma once

#include <string>
#include "State.h"
#include "AEEngine.h"
#include "Rect.h"

using namespace std;

// 游戏元素类，继承了State类，同样还是抽象类，不能用于生成对象
// 用于派生具体游戏元素类，成员函数使用虚函数来实现多态
class GameElement : public State {
public:
	GameElement(float size, float x, float y, string picture_file_name) :
                rect_(size, x, y),
	            picture_file_name_(picture_file_name), 
	            mesh_(nullptr), 
	            texture_(nullptr) {}
	GameElement() : GameElement(0.0, 0.0, 0.0, nullptr) {}
	virtual ~GameElement() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	Rect rect_;
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
