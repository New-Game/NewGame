/**
* Project:      NewGame
* File Name:   Ram.h
* Author:       Atlas Shen
* Date:         2017/5/7
* Purpose:     ��ķ��ͷ�ļ�
*/

#pragma once

#include "Character.h"

class Ram : public Character {
public:
	Ram(Rect rect) : Character(rect, "picture\\Ram_small.png") {
		cold_down_ = 12;
	}

	Ram(const Ram& ram) : Character(ram) {}

	Ram() : Character("picture\\Ram_small.png") {
		cold_down_ = 12;
	}

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
