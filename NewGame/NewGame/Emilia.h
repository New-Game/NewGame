/**
 * Project:      NewGame
 * File Name:    Aimiliya.h
 * Author:       Atlas Shen
 * Date:         2017/5/7
 * Purpose:      艾米莉亚类头文件
 */

#pragma once

#include "Character.h"

class Emilia : public Character {
public:
	Emilia(Rect rect) : Character(rect, "picture\\emilia_small.png") {}

	Emilia(const Emilia& aimiliya) : Character(aimiliya) {}
	
	Emilia() : Character("picture\\emilia_small.png"){}

	~Emilia() {}

	Emilia* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

	Bullet* Attack() override;

private:
};
