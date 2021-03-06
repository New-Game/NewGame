/**
 * Project:      NewGame
 * File Name:    Bullet.h
 * Author:       Atlas Shen
 * Date:         2017/5/29
 * Purpose:      子弹类头文件
 */

#pragma once

#include "GameElement.h"

class Bullet : public GameElement {
public:
	Bullet(Directions front, Rect rect, string picture) : 
			GameElement(rect, picture), 
			front_(front), 
			speed_(6) {}

	Bullet() : front_(DOWN), speed_(6) {}

	~Bullet() {}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

private:
	Directions front_;
	int speed_;
};
