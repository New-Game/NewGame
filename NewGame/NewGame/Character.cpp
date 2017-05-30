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
		rect_.MoveUp(speed_ * 2.0f);
		front_  = UP;
		Input::GetPressedKey(KEY_UP).SetIsPressed(false);
		int temp = rect_.GetY(); if (rect_.GetY() - temp > 0.5) temp++;
		if (temp % 30<=15) {
			if (Level::static_collision_data_[rect_.GetRawI() - 1][(rect_.GetRawJ())] == 1)
				rect_.MoveDown(speed_ * 2.0f);
		}
	}
	else if (Input::GetPressedKey(KEY_DOWN).GetIsPressed()) {
		rect_.MoveDown(speed_ * 2.0f);
		front_ = DOWN;
		Input::GetPressedKey(KEY_DOWN).SetIsPressed(false);
		int temp = rect_.GetY(); if (rect_.GetY() - temp > 0.5) temp++;
		if(temp%30>=15)
		if (Level::static_collision_data_[rect_.GetRawI() + 1][rect_.GetRawJ()] == 1)
			rect_.MoveUp(speed_ * 2.0f);
	}
	else if (Input::GetPressedKey(KEY_LEFT).GetIsPressed()) {
		rect_.MoveLeft(speed_ * 2.0f);
		front_ = LEFT;
		Input::GetPressedKey(KEY_LEFT).SetIsPressed(false);
		int temp = rect_.GetX(); if (rect_.GetX() - temp > 0.5) temp++;
		if (temp % 30 <= 15) {
			if (Level::static_collision_data_[rect_.GetRawI()][rect_.GetRawJ() - 1] == 1)
				rect_.MoveRight(speed_ * 2.0f);
		}
	}
	else if (Input::GetPressedKey(KEY_RIGHT).GetIsPressed()) {
		rect_.MoveRight(speed_ * 2.0f);
		front_ = RIGHT;
		Input::GetPressedKey(KEY_RIGHT).SetIsPressed(false);
		int temp = rect_.GetX(); if (rect_.GetX() - temp > 0.5) temp++;
		if(temp%30>=15)
		if (Level::static_collision_data_[rect_.GetRawI()][rect_.GetRawJ() + 1] == 1)
			rect_.MoveLeft(speed_ * 2.0f);
	}
}

void Character::Attack() const {
	if (Input::GetPressedKey(KEY_A).GetIsPressed()) {
		auto temp_size = 6.0f;
		switch (front_) {
			case UP: {
				Rect temp_rect(temp_size, rect_.GetX(), rect_.GetTop() - temp_size / 2);
				Level::game_element_list_[BULLET].push_back(new Bullet(temp_rect, "picture\\bullet.png", UP));
				Level::game_element_list_[BULLET].back()->Load();
				break;
			}
			case DOWN: {
				Rect temp_rect(temp_size, rect_.GetX(), rect_.GetBottom() + temp_size / 2);
				Level::game_element_list_[BULLET].push_back(new Bullet(temp_rect, "picture\\bullet.png", DOWN));
				Level::game_element_list_[BULLET].back()->Load();
				break;
			}
			case LEFT: {
				Rect temp_rect(temp_size, rect_.GetLeft() - temp_size / 2, rect_.GetY());
				Level::game_element_list_[BULLET].push_back(new Bullet(temp_rect, "picture\\bullet.png", LEFT));
				Level::game_element_list_[BULLET].back()->Load();
				break;
			}
			case RIGHT: {
				Rect temp_rect(temp_size, rect_.GetRight() + temp_size / 2, rect_.GetY());
				Level::game_element_list_[BULLET].push_back(new Bullet(temp_rect, "picture\\bullet.png", RIGHT));
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
