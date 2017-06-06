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
#include "Bullet.h"

void Character::Move() {
	if (Input::GetPressedKey(KEY_UP).GetIsPressed()) {
		rect_.MoveUp(speed_);
		front_ = UP;
		Input::GetPressedKey(KEY_UP).SetIsPressed(false);
		// 向上移动的静态碰撞检测
		auto size = rect_.GetSize();
		auto temp_j = rect_.GetX() / size;
		auto temp_i = rect_.GetY() / size;
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
	else if (Input::GetPressedKey(KEY_DOWN).GetIsPressed()) {
		rect_.MoveDown(speed_);
		front_ = DOWN;
		Input::GetPressedKey(KEY_DOWN).SetIsPressed(false);
		// 向下移动的静态碰撞检测
		auto size = rect_.GetSize();
		auto temp_j = rect_.GetX() / size;
		auto temp_i = rect_.GetY() / size;
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
	else if (Input::GetPressedKey(KEY_LEFT).GetIsPressed()) {
		rect_.MoveLeft(speed_);
		front_ = LEFT;
		Input::GetPressedKey(KEY_LEFT).SetIsPressed(false);
		// 向左移动的静态碰撞检测
		auto size = rect_.GetSize();
		auto temp_j = rect_.GetX() / size;
		auto temp_i = rect_.GetY() / size;
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
	else if (Input::GetPressedKey(KEY_RIGHT).GetIsPressed()) {
		rect_.MoveRight(speed_);
		front_ = RIGHT;
		Input::GetPressedKey(KEY_RIGHT).SetIsPressed(false);
		// 向右移动的静态碰撞检测
		auto size = rect_.GetSize();
		auto temp_j = rect_.GetX() / size;
		auto temp_i = rect_.GetY() / size;
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

void Character::Attack() const {
	auto temp_size = 6;
	switch (front_) {
		case UP: {
			Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() / 2, rect_.GetY() - temp_size / 2);
			Level::game_element_list_[BULLET].push_back(new Bullet(UP, temp_rect, "picture\\bullet.png"));
			Level::game_element_list_[BULLET].back()->Load();
			break;
		}
		case DOWN: {
			Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() / 2, rect_.GetY() + rect_.GetSize() + temp_size / 2);
			Level::game_element_list_[BULLET].push_back(new Bullet(DOWN, temp_rect, "picture\\bullet.png"));
			Level::game_element_list_[BULLET].back()->Load();
			break;
		}
		case LEFT: {
			Rect temp_rect(temp_size, rect_.GetX() - temp_size / 2, rect_.GetY() + rect_.GetSize() / 2);
			Level::game_element_list_[BULLET].push_back(new Bullet(LEFT, temp_rect, "picture\\bullet.png"));
			Level::game_element_list_[BULLET].back()->Load();
			break;
		}
		case RIGHT: {
			Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() + temp_size / 2, rect_.GetY() + rect_.GetSize() / 2);
			Level::game_element_list_[BULLET].push_back(new Bullet(RIGHT, temp_rect, "picture\\bullet.png"));
			Level::game_element_list_[BULLET].back()->Load();
			break;
		}
		default:
			break;
	}
}

void Character::UseSkill() {}
