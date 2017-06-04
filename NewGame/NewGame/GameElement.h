/**
 * Project:      NewGame
 * File Name:    GameElement.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      游戏元素类头文件
 */

#pragma once

#include <string>
#include "AEEngine.h"
#include "Rect.h"

using namespace std;

// 游戏元素的面向方向
enum Directions {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// 游戏元素类，继承了State类，同样还是抽象类，不能用于生成对象
// 用于派生具体游戏元素类，成员函数使用虚函数来实现多态
class GameElement {
public:
	GameElement(int size, int x, int y, string picture_file_name) : 
			rect_(size, x, y), 
			picture_file_name_(picture_file_name), 
			mesh_(nullptr), 
			texture_(nullptr) {}

	GameElement(Rect rect, string picture_file_name) : 
			rect_(rect), 
			picture_file_name_(picture_file_name), 
			mesh_(nullptr), 
			texture_(nullptr) {}

	GameElement(const GameElement& game_element) : 
			rect_(game_element.rect_), 
			picture_file_name_(game_element.picture_file_name_), 
			mesh_(game_element.mesh_), 
			texture_(game_element.texture_) {}

	GameElement() : GameElement(0, 0, 0, "") {}

	virtual ~GameElement() {}

	virtual GameElement* GetClassType() {
		return this;
	}

	Rect GetRect() const {
		return rect_;
	}

	virtual void Load() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Unload() = 0;

protected:
	Rect rect_;
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
