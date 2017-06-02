/**
 * Project:      NewGame
 * File Name:    SpeedBuff.h
 * Author:       Atlas
 * Date:         2017/6/02
 * Purpose:      加速Buff类头文件
 */

#pragma once

#include "Buff.h"

class SpeedBuff : public Buff {
public:
	SpeedBuff(Rect rect, string picture_file_name) : Buff(rect, picture_file_name) {}
	SpeedBuff() {}
	~SpeedBuff() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
	void Affect(Character* p_character) override;
private:

};
