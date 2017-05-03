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
	Wall(int size, const Position position) : GameElement(size, position) {}
	~Wall() {}

	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;
private:

};
