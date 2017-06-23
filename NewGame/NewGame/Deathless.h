/**
 * Project:      NewGame
 * File Name:    Deathless.h
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      不死怪兽类头文件
 */

#pragma once

#include "Monster.h"

class Deathless : public Monster {
public:
	Deathless(Rect rect) : Monster(rect, "picture\\minion.png") {}

	Deathless(const Deathless& deathless) : Monster(deathless) {}

	Deathless() {}

	~Deathless() {}

	Deathless* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

private:
};
