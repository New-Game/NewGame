/**
 * Project:      NewGame
 * File Name:    InvincibleBuff.h
 * Author:       Atlas
 * Date:         2017/6/02
 * Purpose:      无敌Buff类头文件
 */

#pragma once

#include "Buff.h"

class InvincibleBuff : public Buff {
public:
	InvincibleBuff(Rect rect, string picture_file_name) : Buff(rect, picture_file_name) {}
	InvincibleBuff() {}
	~InvincibleBuff() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
	void Affect(Character* p_character) override;
private:

};
