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
		position_.MoveUp(speed_ * 2);
		front_ = UP;
		Input::GetPressedKey(KEY_UP).SetIsPressed(false);
		// 向上移动的静态碰撞检测
		auto temp_j = int(position_.GetX() / size_);
		auto temp_i = int(position_.GetY() / size_);
		auto wall1 = Level::wall_list_.find(Position(temp_j * size_, temp_i * size_));
		auto wall2 = Level::wall_list_.find(Position((temp_j + 1) * size_, temp_i * size_));
		if (wall1 != Level::wall_list_.end()) {
			if (position_.IsCollision(size_, wall1->second.GetPosition(), size_))
				position_.MoveDown(speed_ * 2);
		}
		else if (wall2 != Level::wall_list_.end()) {
			if (position_.IsCollision(size_, wall2->second.GetPosition(), size_))
				position_.MoveDown(speed_ * 2);
		}
	}
	else if (Input::GetPressedKey(KEY_DOWN).GetIsPressed()) {
		position_.MoveDown(speed_ * 2);
		front_ = DOWN;
		Input::GetPressedKey(KEY_DOWN).SetIsPressed(false);
		// 向下移动的静态碰撞检测
		auto temp_j = int(position_.GetX() / size_);
		auto temp_i = int(position_.GetY() / size_);
		auto wall1 = Level::wall_list_.find(Position(temp_j * size_, (temp_i + 1) * size_));
		auto wall2 = Level::wall_list_.find(Position((temp_j + 1) * size_, (temp_i + 1) * size_));
		if (wall1 != Level::wall_list_.end()) {
			if (position_.IsCollision(size_, wall1->second.GetPosition(), size_))
				position_.MoveUp(speed_ * 2);
		}
		else if (wall2 != Level::wall_list_.end()) {
			if (position_.IsCollision(size_, wall2->second.GetPosition(), size_))
				position_.MoveUp(speed_ * 2);
		}
	}
	else if (Input::GetPressedKey(KEY_LEFT).GetIsPressed()) {
		position_.MoveLeft(speed_ * 2);
		front_ = LEFT;
		Input::GetPressedKey(KEY_LEFT).SetIsPressed(false);
		// 向左移动的静态碰撞检测
		auto temp_j = int(position_.GetX() / size_);
		auto temp_i = int(position_.GetY() / size_);
		auto wall1 = Level::wall_list_.find(Position(temp_j * size_, temp_i * size_));
		auto wall2 = Level::wall_list_.find(Position(temp_j * size_, (temp_i + 1) * size_));
		if (wall1 != Level::wall_list_.end()) {
			if (position_.IsCollision(size_, wall1->second.GetPosition(), size_))
				position_.MoveRight(speed_ * 2);
		}
		else if (wall2 != Level::wall_list_.end()) {
			if (position_.IsCollision(size_, wall2->second.GetPosition(), size_))
				position_.MoveRight(speed_ * 2);
		}
	}
	else if (Input::GetPressedKey(KEY_RIGHT).GetIsPressed()) {
		position_.MoveRight(speed_ * 2);
		front_ = RIGHT;
		Input::GetPressedKey(KEY_RIGHT).SetIsPressed(false);
		// 向右移动的静态碰撞检测
		auto temp_j = int(position_.GetX() / size_);
		auto temp_i = int(position_.GetY() / size_);
		auto wall1 = Level::wall_list_.find(Position((temp_j + 1) * size_, temp_i * size_));
		auto wall2 = Level::wall_list_.find(Position((temp_j + 1) * size_, (temp_i + 1) * size_));
		if (wall1 != Level::wall_list_.end()) {
			if (position_.IsCollision(size_, wall1->second.GetPosition(), size_))
				position_.MoveLeft(speed_ * 2);
		}
		else if (wall2 != Level::wall_list_.end()) {
			if (position_.IsCollision(size_, wall2->second.GetPosition(), size_))
				position_.MoveLeft(speed_ * 2);
		}
	}
}

void Character::Attack() const {
	if (Input::GetPressedKey(KEY_A).GetIsPressed()) {
		auto temp_size = 6;
		switch (front_) {
			case UP: {
				Position temp_position(position_.GetX() + size_ / 2, position_.GetY() - temp_size / 2);
				Level::game_element_list_[BULLET].push_back(new Bullet(temp_size, temp_position,
					                                        "picture\\bullet.png", UP));
				Level::game_element_list_[BULLET].back()->Load();
				break;
			}
			case DOWN: {
				Position temp_position(position_.GetX() + size_ / 2, position_.GetY() + size_ + temp_size / 2);
				Level::game_element_list_[BULLET].push_back(new Bullet(temp_size, temp_position,
					                                        "picture\\bullet.png", DOWN));
				Level::game_element_list_[BULLET].back()->Load();
				break;
			}
			case LEFT: {
				Position temp_position(position_.GetX() - temp_size / 2, position_.GetY() + size_ / 2);
				Level::game_element_list_[BULLET].push_back(new Bullet(temp_size, temp_position,
					                                        "picture\\bullet.png", LEFT));
				Level::game_element_list_[BULLET].back()->Load();
				break;
			}
			case RIGHT: {
				Position temp_position(position_.GetX() + size_ + temp_size / 2, position_.GetY() + size_ / 2);
				Level::game_element_list_[BULLET].push_back(new Bullet(temp_size, temp_position,
					                                        "picture\\bullet.png", RIGHT));
				Level::game_element_list_[BULLET].back()->Load();
				break;
			}
			default:
				break;
		}
		Input::GetPressedKey(KEY_A).SetIsPressed(false);
	}
}

void Character::UseSkill() {}

void Character::GetBuff() {}
