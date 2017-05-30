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
	Bullet(Rect rect, string picture_file_name, enum Direction front) : 
	       Item(rect, picture_file_name), 
	       front_(front), 
	       speed_(6) {}
	Bullet() : front_(DOWN), speed_(0) {}
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
