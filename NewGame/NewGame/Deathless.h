/**
 * Project:      NewGame
 * File Name:    Deathless.h
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      ����������ͷ�ļ�
 */

#pragma once

#include "Monster.h"

class Deathless : public Monster {
public:
	Deathless(Rect rect, string picture_file_name) : Monster(rect, picture_file_name) {}

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