/**
 * Project:      NewGame
 * File Name:    Character.cpp
 * Author:       Atlas Shen/Long
 * Date:         2017/5/07
 * Purpose:      ������ʵ���ļ�
 */

#include "Character.h"
#include "Input.h"
#include "Level.h"
#include "Bullet.h"

void Character::Move() {
	if (Input::GetPressedKey(KEY_UP).GetIsPressed()) {
		rect_.MoveUp(speed_);
		rect_.SetFront(UP);
		Input::GetPressedKey(KEY_UP).SetIsPressed(false);
		// �����ƶ��ľ�̬��ײ���
		auto size = rect_.GetSize();
		auto temp_j = rect_.GetX() / size;
		auto temp_i = rect_.GetY() / size;
		auto wall1 = Level::wall_list_.find(Rect(size, temp_j * size, temp_i * size, NONE));
		auto wall2 = Level::wall_list_.find(Rect(size, (temp_j + 1) * size, temp_i * size, NONE));
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
		rect_.SetFront(DOWN);
		Input::GetPressedKey(KEY_DOWN).SetIsPressed(false);
		// �����ƶ��ľ�̬��ײ���
		auto size = rect_.GetSize();
		auto temp_j = rect_.GetX() / size;
		auto temp_i = rect_.GetY() / size;
		auto wall1 = Level::wall_list_.find(Rect(size, temp_j * size, (temp_i + 1) * size, NONE));
		auto wall2 = Level::wall_list_.find(Rect(size, (temp_j + 1) * size, (temp_i + 1) * size, NONE));
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
		rect_.SetFront(LEFT);
		Input::GetPressedKey(KEY_LEFT).SetIsPressed(false);
		// �����ƶ��ľ�̬��ײ���
		auto size = rect_.GetSize();
		auto temp_j = rect_.GetX() / size;
		auto temp_i = rect_.GetY() / size;
		auto wall1 = Level::wall_list_.find(Rect(size, temp_j * size, temp_i * size, NONE));
		auto wall2 = Level::wall_list_.find(Rect(size, temp_j * size, (temp_i + 1) * size, NONE));
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
		rect_.SetFront(RIGHT);
		Input::GetPressedKey(KEY_RIGHT).SetIsPressed(false);
		// �����ƶ��ľ�̬��ײ���
		auto size = rect_.GetSize();
		auto temp_j = rect_.GetX() / size;
		auto temp_i = rect_.GetY() / size;
		auto wall1 = Level::wall_list_.find(Rect(size, (temp_j + 1) * size, temp_i * size, NONE));
		auto wall2 = Level::wall_list_.find(Rect(size, (temp_j + 1) * size, (temp_i + 1) * size, NONE));
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
	switch (rect_.GetFront()) {
		case UP: {
			Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() / 2, rect_.GetY() - temp_size / 2, UP);
			Level::game_element_list_[BULLET].push_back(new Bullet(temp_rect, "picture\\bullet.png"));
			Level::game_element_list_[BULLET].back()->Load();
			break;
		}
		case DOWN: {
			Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() / 2, rect_.GetY() + rect_.GetSize() + temp_size / 2, DOWN);
			Level::game_element_list_[BULLET].push_back(new Bullet(temp_rect, "picture\\bullet.png"));
			Level::game_element_list_[BULLET].back()->Load();
			break;
		}
		case LEFT: {
			Rect temp_rect(temp_size, rect_.GetX() - temp_size / 2, rect_.GetY() + rect_.GetSize() / 2, LEFT);
			Level::game_element_list_[BULLET].push_back(new Bullet(temp_rect, "picture\\bullet.png"));
			Level::game_element_list_[BULLET].back()->Load();
			break;
		}
		case RIGHT: {
			Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() + temp_size / 2, rect_.GetY() + rect_.GetSize() / 2, RIGHT);
			Level::game_element_list_[BULLET].push_back(new Bullet(temp_rect, "picture\\bullet.png"));
			Level::game_element_list_[BULLET].back()->Load();
			break;
		}
		default:
			break;
	}
}

void Character::UseSkill() {}

void Character::GetBuff() {}

void Character::BulletCollisionCheck() const {
	for (auto i = Level::game_element_list_[BULLET].begin(); i != Level::game_element_list_[BULLET].end();) {
		switch ((*i)->GetRect().GetFront()) {
			case UP: {
				auto size = rect_.GetSize();
				auto temp_j = (*i)->GetRect().GetX() / size;
				auto temp_i = (*i)->GetRect().GetY() / size;
				auto wall = Level::wall_list_.find(Rect(size, temp_j * size, temp_i * size, NONE));
				if (wall != Level::wall_list_.end()) {
					if ((*i)->GetRect().IsCollision(wall->second.GetRect())) {
						(*i)->Unload();
						delete *i;
						i = Level::game_element_list_[BULLET].erase(i);
					}
				}
				else
					++i;
				break;
			}
			case DOWN: {
				auto size = rect_.GetSize();
				auto temp_j = (*i)->GetRect().GetX() / size;
				auto temp_i = (*i)->GetRect().GetY() / size;
				auto wall = Level::wall_list_.find(Rect(size, temp_j * size, temp_i * size, NONE));
				if (wall != Level::wall_list_.end()) {
					if ((*i)->GetRect().IsCollision(wall->second.GetRect())) {
						(*i)->Unload();
						delete *i;
						i = Level::game_element_list_[BULLET].erase(i);
					}
				}
				else
					++i;
				break;
			}
			case LEFT: {
				auto size = rect_.GetSize();
				auto temp_j = (*i)->GetRect().GetX() / size;
				auto temp_i = (*i)->GetRect().GetY() / size;
				auto wall = Level::wall_list_.find(Rect(size, temp_j * size, temp_i * size, NONE));
				if (wall != Level::wall_list_.end()) {
					if ((*i)->GetRect().IsCollision(wall->second.GetRect())) {
						(*i)->Unload();
						delete *i;
						i = Level::game_element_list_[BULLET].erase(i);
					}
				}
				else
					++i;
				break;
			}
			case RIGHT: {
				auto size = rect_.GetSize();
				auto temp_j = (*i)->GetRect().GetX() / size;
				auto temp_i = (*i)->GetRect().GetY() / size;
				auto wall = Level::wall_list_.find(Rect(size, temp_j * size, temp_i * size, NONE));
				if (wall != Level::wall_list_.end()) {
					if ((*i)->GetRect().IsCollision(wall->second.GetRect())) {
						(*i)->Unload();
						delete *i;
						i = Level::game_element_list_[BULLET].erase(i);
					}
				}
				else
					++i;
				break;
			}
			default:
				break;
		}
	}
}
