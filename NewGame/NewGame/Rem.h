#pragma once
/**
* Project:      NewGame
* File Name:    Rem.h
* Author:       Atlas Shen
* Date:         2017/5/7
* Purpose:      雷姆类头文件
*/

#pragma once

#include "Character.h"

class Rem : public Character {
public:
	Rem(Rect rect) : Character(rect, "picture\\Rem_small.png") {
		cold_down_ = 6;
	}

	Rem(const Rem& rem) : Character(rem) {}

	Rem() : Character("picture\\Rem_small.png") {
		cold_down_ = 6;
	}

	~Rem() {}

	Rem* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

	Bullet* Attack() override;

private:
};
