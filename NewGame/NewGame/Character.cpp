/**
 * Project:      NewGame
 * File Name:    Character.cpp
 * Author:       Atlas Shen
 * Date:         2017/5/7
 * Purpose:      人物类实现文件
 */

#include "Character.h"
#include "Input.h"
#include "Level.h"

void Character::Move() {
	if (Input::GetPressedKey(KEY_UP).GetIsPressed()) {
		rect_.MoveUp(speed_ * 2.0f);
		Input::GetPressedKey(KEY_UP).SetIsPressed(false);
		int temp = rect_.GetY(); if (rect_.GetY() - temp > 0.5) temp++;
		if (temp % 30<=15) {
			if (Level::static_collision_data_[rect_.GetRawI() - 1][(rect_.GetRawJ())] == 1)
				rect_.MoveDown(speed_ * 2.0f);
		}
	}
	else if (Input::GetPressedKey(KEY_DOWN).GetIsPressed()) {
		rect_.MoveDown(speed_ * 2.0f);
		Input::GetPressedKey(KEY_DOWN).SetIsPressed(false);
		int temp = rect_.GetY(); if (rect_.GetY() - temp > 0.5) temp++;
		if(temp%30>=15)
		if (Level::static_collision_data_[rect_.GetRawI()+1][rect_.GetRawJ()] == 1)
			rect_.MoveUp(speed_ * 2.0f);
	}
	else if (Input::GetPressedKey(KEY_LEFT).GetIsPressed()) {
		rect_.MoveLeft(speed_ * 2.0f);
		
		Input::GetPressedKey(KEY_LEFT).SetIsPressed(false);
		int temp = rect_.GetX(); if (rect_.GetX() - temp > 0.5) temp++;
		if (temp % 30 <= 15) {
			if (Level::static_collision_data_[rect_.GetRawI()][rect_.GetRawJ()-1] == 1)
				rect_.MoveRight(speed_ * 2.0f);
		}
	}
	else if (Input::GetPressedKey(KEY_RIGHT).GetIsPressed()) {
		rect_.MoveRight(speed_ * 2.0f);
		Input::GetPressedKey(KEY_RIGHT).SetIsPressed(false);
		int temp = rect_.GetX(); if (rect_.GetX() - temp > 0.5) temp++;
		if(temp%30>=15)
		if (Level::static_collision_data_[rect_.GetRawI()][rect_.GetRawJ()+1] == 1)
			rect_.MoveLeft(speed_ * 2.0f);
	}
}

void Character::Attack() {
	if (Input::GetPressedKey(KEY_A).GetIsPressed()) {
		
	}
}

void Character::UseSkill() {}

void Character::GetBuff() {}
