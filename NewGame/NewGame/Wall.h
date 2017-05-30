/**
 * Project:      NewGame
 * File Name:    Wall.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      墙体类头文件
 */

#pragma once

#include "GameElement.h"

// 墙体类，可直接生成对象
class Wall : public GameElement {
public:
	Wall() {}
	Wall(int size, Position position, string picture_file_name) : 
	     GameElement(size, position, picture_file_name) {}
	~Wall() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
private:

};
