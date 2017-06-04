/**
 * Project:      NewGame
 * File Name:    Boss.h
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      �Ϲ���ͷ�ļ�
 */

#pragma once

#include "Monster.h"

class Boss : public Monster {
public:
	Boss(Rect rect, string picture_file_name) : Monster(rect, picture_file_name) {}

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
