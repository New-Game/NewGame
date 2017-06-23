/**
* Project:      NewGame
* File Name:    Felt.h
* Author:       Atlas Shen
* Date:         2017/5/7
* Purpose:      菲鲁特类头文件
*/

#pragma once

#include "Character.h"

class Felt : public Character {
public:
	Felt(Rect rect) : Character(rect, "picture\\Felt_small.png") {}

	Felt(const Felt& felt) : Character(felt) {}

	Felt() : Character("picture\\Felt_small.png") {}

	~Felt() {}

	Felt* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

	Bullet* Attack() override;

private:
};
