/**
* Project:      NewGame
* File Name:   Ram.h
* Author:       Atlas Shen
* Date:         2017/5/7
* Purpose:     拉姆类头文件
*/

#pragma once

#include "Character.h"

class Ram : public Character {
public:
	Ram(Rect rect) : Character(rect, "picture\\Ram_small.png") {}

	Ram(const Ram& ram) : Character(ram) {}

	Ram() : Character("picture\\Ram_small.png") {}

	~Ram() {}

	Ram* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

	Bullet* Attack() override;

private:
};
