/**
 * Project:      NewGame
 * File Name:    TimeBuff.h
 * Author:       Atlas
 * Date:         2017/6/02
 * Purpose:      加时间Buff类头文件
 */

#pragma once

#include "Buff.h"

class TimeBuff : public Buff {
public:
	TimeBuff(Rect rect, string picture_file_name) : Buff(rect, picture_file_name) {}
	TimeBuff() {}
	~TimeBuff() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
	void Affect(Character* p_character) override;
private:
	
};
