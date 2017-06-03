/**
 * Project:      NewGame
 * File Name:    Minion.h
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      普通怪兽类头文件
 */

#pragma once

#include "Monster.h"

class Minion : public Monster {
public:
	Minion(Rect rect, string picture_file_name) : Monster(rect, picture_file_name) {}

	explicit Minion(const Minion* minion) {
		rect_ = minion->rect_;
		front_ = minion->front_;
		speed_ = minion->speed_;
		x_min_ = minion->x_min_;
		x_max_ = minion->x_max_;
		y_min_ = minion->y_min_;
		y_max_ = minion->y_max_;
	}

	Minion() {}
	~Minion() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
private:
};
