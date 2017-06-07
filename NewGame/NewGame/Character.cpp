/**
 * Project:      NewGame
 * File Name:    Character.cpp
 * Author:       Atlas Shen/Long
 * Date:         2017/5/07
 * Purpose:      人物类实现文件
 */

#include "Character.h"
#include "Input.h"
#include "Level.h"

void Character::Move() {
	if (AEInputCheckCurr(VK_UP)) {
		rect_.MoveUp(speed_);
		front_ = UP;
		// 向上移动的静态碰撞检测
		int size = rect_.GetSize();
		int temp_j = rect_.GetX() / size;
		int temp_i = rect_.GetY() / size;
		auto wall1 = Level::wall_list_.find(Rect(size, temp_j * size, temp_i * size));
		auto wall2 = Level::wall_list_.find(Rect(size, (temp_j + 1) * size, temp_i * size));
		if (wall1 != Level::wall_list_.end()) {
			if (rect_.IsCollision(wall1->second.GetRect()))
				rect_.MoveDown(speed_);
		}
		else if (wall2 != Level::wall_list_.end()) {
			if (rect_.IsCollision(wall2->second.GetRect()))
				rect_.MoveDown(speed_);
		}
	}
	else if (AEInputCheckCurr(VK_DOWN)) {
		rect_.MoveDown(speed_);
		front_ = DOWN;
		// 向下移动的静态碰撞检测
		int size = rect_.GetSize();
		int temp_j = rect_.GetX() / size;
		int temp_i = rect_.GetY() / size;
		auto wall1 = Level::wall_list_.find(Rect(size, temp_j * size, (temp_i + 1) * size));
		auto wall2 = Level::wall_list_.find(Rect(size, (temp_j + 1) * size, (temp_i + 1) * size));
		if (wall1 != Level::wall_list_.end()) {
			if (rect_.IsCollision(wall1->second.GetRect()))
				rect_.MoveUp(speed_);
		}
		else if (wall2 != Level::wall_list_.end()) {
			if (rect_.IsCollision(wall2->second.GetRect()))
				rect_.MoveUp(speed_);
		}
	}
	else if (AEInputCheckCurr(VK_LEFT)) {
		rect_.MoveLeft(speed_);
		front_ = LEFT;
		// 向左移动的静态碰撞检测
		int size = rect_.GetSize();
		int temp_j = rect_.GetX() / size;
		int temp_i = rect_.GetY() / size;
		auto wall1 = Level::wall_list_.find(Rect(size, temp_j * size, temp_i * size));
		auto wall2 = Level::wall_list_.find(Rect(size, temp_j * size, (temp_i + 1) * size));
		if (wall1 != Level::wall_list_.end()) {
			if (rect_.IsCollision(wall1->second.GetRect()))
				rect_.MoveRight(speed_);
		}
		else if (wall2 != Level::wall_list_.end()) {
			if (rect_.IsCollision(wall2->second.GetRect()))
				rect_.MoveRight(speed_);
		}
	}
	else if (AEInputCheckCurr(VK_RIGHT)) {
		rect_.MoveRight(speed_);
		front_ = RIGHT;
		// 向右移动的静态碰撞检测
		int size = rect_.GetSize();
		int temp_j = rect_.GetX() / size;
		int temp_i = rect_.GetY() / size;
		auto wall1 = Level::wall_list_.find(Rect(size, (temp_j + 1) * size, temp_i * size));
		auto wall2 = Level::wall_list_.find(Rect(size, (temp_j + 1) * size, (temp_i + 1) * size));
		if (wall1 != Level::wall_list_.end()) {
			if (rect_.IsCollision(wall1->second.GetRect()))
				rect_.MoveLeft(speed_);
		}
		else if (wall2 != Level::wall_list_.end()) {
			if (rect_.IsCollision(wall2->second.GetRect()))
				rect_.MoveLeft(speed_);
		}
	}
}
