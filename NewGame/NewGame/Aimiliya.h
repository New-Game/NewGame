/**
 * Project:      NewGame
 * File Name:    Aimiliya.h
 * Author:       Atlas Shen
 * Date:         2017/5/7
 * Purpose:      艾米莉亚类头文件
 */

#pragma once

#include "Character.h"

class Aimiliya : public Character {
public:
	Aimiliya(Rect rect) : Character(rect, "picture\\aimiliya.png") {}

	Aimiliya(const Aimiliya& aimiliya) : Character(aimiliya) {}
	
	Aimiliya() {}

	~Aimiliya() {}

	Aimiliya* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

private:
};
