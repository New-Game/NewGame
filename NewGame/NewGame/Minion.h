/**
 * Project:      NewGame
 * File Name:    Minion.h
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      普通怪兽类头文件
 */

#pragma once

#include "Monster.h"

class Minion : public Monster {
public:
	Minion(Rect rect, string picture_file_name) : Monster(rect, picture_file_name) {}
	Minion() {}
	~Minion() {}

	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
private:
};
