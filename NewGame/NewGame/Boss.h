/**
 * Project:      NewGame
 * File Name:    Boss.h
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      老怪类头文件
 */

#pragma once

#include "Monster.h"

class Boss : public Monster {
public:
	Boss(Rect rect) : Monster(rect, "picture\\boss.png") {}

	Boss(const Boss& boss) : Monster(boss) {}

	Boss() {}

	~Boss() {}
	
	Boss* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

private:
};
