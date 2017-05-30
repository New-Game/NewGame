/**
 * Project:      NewGame
 * File Name:    Bullet.h
 * Author:       Atlas Shen
 * Date:         2017/5/29
 * Purpose:      子弹类头文件
 */

#pragma once

#include "Item.h"

class Bullet : public Item {
public:
	Bullet(int size, Position position, string picture_file_name, enum Direction front) : 
	       Item(size, position, picture_file_name), 
	       front_(front), 
	       speed_(1) {}
	Bullet() : front_(DOWN), speed_(1) {}
	~Bullet() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;

private:
	enum Direction front_;
	int speed_;
};
