/**
* Project:      NewGame
* File Name:    ScoreBuff.h
* Author:       Atlas
* Date:         2017/6/02
* Purpose:      加分Buff类头文件
*/

#pragma once

#include "Buff.h"

class ScoreBuff : public Buff {
public:
	ScoreBuff (Rect rect, string picture_file_name) : Buff(rect, picture_file_name) {}
	ScoreBuff() {}
	~ScoreBuff() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
	void Affect(Character* p_character) override;
private:

};
