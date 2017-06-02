/**
 * Project:      NewGame
 * File Name:    DamageBuff.h
 * Author:       Atlas
 * Date:         2017/6/02
 * Purpose:      加伤害Buff类头文件
 */

#pragma once

#include "Buff.h"

class DamageBuff : public Buff {
public:
	DamageBuff(Rect rect, string picture_file_name) : Buff(rect, picture_file_name) {}
	DamageBuff() {}
	~DamageBuff() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
	void Affect(Character* p_character) override;
private:

};
