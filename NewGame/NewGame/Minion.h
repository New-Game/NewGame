/**
 * Project:      NewGame
 * File Name:    Minion.h
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      ��ͨ������ͷ�ļ�
 */

#pragma once

#include "Monster.h"

class Minion : public Monster {
public:
	Minion(Rect rect) : Monster(rect, "picture\\minion.png") {}

	Minion(const Minion& minion) : Monster(minion) {}

	Minion() {}

	~Minion() {}

	Minion* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

private:
};
