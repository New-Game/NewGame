/**
 * Project:      NewGame
 * File Name:    Monster.cpp
 * Author:       Atlas/Long
 * Date:         2017/6/02
 * Purpose:      怪物类实现文件
 */

#include "Monster.h"

void Monster::Move() {
	if (front_ == UP) {
		if (rect_.GetY() > y_min_)
			rect_.MoveUp(speed_);
		else {
			if (x_max_ == x_min_)
				front_ = DOWN;
			else if (rect_.GetX() == x_max_)
				front_ = LEFT;
			else
				front_ = RIGHT;
		}
	}
	else if (front_ == DOWN) {
		if (rect_.GetY() < y_max_)
			rect_.MoveDown(speed_);
		else {
			if (x_max_ == x_min_)
				front_ = UP;
			else if (rect_.GetX() == x_max_)
				front_ = LEFT;
			else
				front_ = RIGHT;
		}
	}
	else if (front_ == LEFT) {
		if (rect_.GetX() > x_min_)
			rect_.MoveLeft(speed_);
		else {
			if (y_max_ == y_min_)
				front_ = RIGHT;
			else if (rect_.GetY() == y_max_)
				front_ = UP;
			else
				front_ = DOWN;
		}
	}
	else if (front_ == RIGHT) {
		if (rect_.GetX() < x_max_)
			rect_.MoveRight(speed_);
		else {
			if (y_max_ == y_min_)
				front_ = LEFT;
			else if (rect_.GetY() == y_max_)
				front_ = UP;
			else
				front_ = DOWN;
		}
	}
}

void Monster::DropBuff() {
	
}
