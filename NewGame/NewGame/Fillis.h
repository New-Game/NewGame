/**
* Project:      NewGame
* File Name:    Fillis.h
* Author:       Atlas Shen
* Date:         2017/5/7
* Purpose:      ����˹��ͷ�ļ�
*/

#pragma once

#include "Character.h"

class Fillis : public Character {
public:
	Fillis(Rect rect) : Character(rect, "picture\\Fillis_small.png") {}

	Fillis(const Fillis& fillis) : Character(fillis) {}

	Fillis() : Character("picture\\Fillis_small.png") {}

	~Fillis() {}

	Fillis* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

	Bullet* Attack() override;

private:
};
