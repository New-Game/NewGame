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
	Aimiliya(Rect rect, string picture_file_name) : Character(rect, picture_file_name) {}

	explicit Aimiliya(const Aimiliya* aimiliya) {
		rect_ = aimiliya->rect_;
		front_ = aimiliya->front_;
		lives_ = aimiliya->lives_;
		damage_ = aimiliya->damage_;
		speed_ = aimiliya->speed_;
		skill_cold_down_ = aimiliya->skill_cold_down_;
	}

	Aimiliya() {}
	~Aimiliya() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
private:
};
