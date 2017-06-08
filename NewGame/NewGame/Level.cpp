/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      关卡类实现文件
 */

#include <ctime>
#include "resource.h"
#include "Level.h"
#include "Input.h"
#include "Number.h"
#include "Aimiliya.h"
#include "Minion.h"
#include "Deathless.h"
#include "Boss.h"
#include "Trap.h"
#include "Buff.h"

void Level::Load() {
	// 先设置本状态哪些键位是有效的
	Input::GetPressedKey(KEY_SPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_BACKSPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_ESC).SetIsValid(true);
	//Input::GetPressedKey(KEY_A).SetIsValid(true);
	//Input::GetPressedKey(KEY_S).SetIsValid(true);
	//Input::GetPressedKey(KEY_UP).SetIsValid(true);
	//Input::GetPressedKey(KEY_DOWN).SetIsValid(true);
	//Input::GetPressedKey(KEY_LEFT).SetIsValid(true);
	//Input::GetPressedKey(KEY_RIGHT).SetIsValid(true);

	// 读取文件中的数字矩阵，把所有游戏对象信息加入链表保存，墙体对象放入哈希表保存
	for (auto i = 0; i < num_of_map_height_grid_; ++i) {
		for (auto j = 0; j < num_of_map_width_grid_; ++j) {
			int map_grid_info;
			map_config_file_ >> map_grid_info;
			Rect temp_rect(grid_size_, j * grid_size_, i * grid_size_);
			switch (map_grid_info) {
				case ROAD:
					// do nothing
					break;
				case WALL:
					wall_list_.insert(make_pair(temp_rect, Wall(temp_rect)));
					wall_list_[temp_rect].Load();
					break;
				case STARTING_POINT:
					starting_rect_ = temp_rect;
					character_ = new Aimiliya(temp_rect);
					character_->Load();
					original_character_info_ = new Aimiliya(*dynamic_cast<Aimiliya*>(character_));
					break;
				case ENDING_POINT:
					ending_rect_ = temp_rect;
					break;
				case MINION:
					game_element_list_[MONSTER].push_back(new Minion(temp_rect));
					game_element_list_[MONSTER].back()->Load();
					break;
				case DEATHLESS:
					break;
				case BOSS:
					break;
				case SLOW_TRAP:
					game_element_list_[TRAP].push_back(new Trap(SLOW, temp_rect));
					game_element_list_[TRAP].back()->Load();
					original_trap_info_.push_back(*dynamic_cast<Trap*>(game_element_list_[TRAP].back()));
					break;
				case KILL_TRAP:
					game_element_list_[TRAP].push_back(new Trap(KILL, temp_rect));
					game_element_list_[TRAP].back()->Load();
					original_trap_info_.push_back(*dynamic_cast<Trap*>(game_element_list_[TRAP].back()));
					break;
				case BACK_TRAP:
					game_element_list_[TRAP].push_back(new Trap(BACK, temp_rect));
					game_element_list_[TRAP].back()->Load();
					original_trap_info_.push_back(*dynamic_cast<Trap*>(game_element_list_[TRAP].back()));
					break;
				case WEAK_TRAP:
					game_element_list_[TRAP].push_back(new Trap(WEAK, temp_rect));
					game_element_list_[TRAP].back()->Load();
					original_trap_info_.push_back(*dynamic_cast<Trap*>(game_element_list_[TRAP].back()));
					break;
				case RANDOM_BUFF:
					buff_rect_ = temp_rect;
					srand(unsigned(time(nullptr)));
					game_element_list_[BUFF].push_back(new Buff(static_cast<Buffs>(rand() % NUM_OF_BUFF_TYPES), temp_rect));
					game_element_list_[BUFF].back()->Load();
					break;
				default:
					break;
			}
		}
	}

	//  读取的怪兽的横向和纵向活动范围信息
	int j_min, j_max, i_min, i_max, front;
	for (auto& i : game_element_list_[MONSTER]) {
		map_config_file_ >> j_min >> j_max >> i_min >> i_max >> front;
		dynamic_cast<Monster*>(i)->SetXRange(j_min, j_max);
		dynamic_cast<Monster*>(i)->SetYRange(i_min, i_max);
		dynamic_cast<Monster*>(i)->SetFront(static_cast<Directions>(front));
		if (typeid(*(i->GetClassType())) == typeid(Minion))
			original_monster_info_.push_back(new Minion(*dynamic_cast<Minion*>(i)));
		else if (typeid(*(i->GetClassType())) == typeid(Deathless))
			original_monster_info_.push_back(new Deathless(*dynamic_cast<Deathless*>(i)));
		else if (typeid(*(i->GetClassType())) == typeid(Boss))
			original_monster_info_.push_back(new Boss(*dynamic_cast<Boss*>(i)));
	}
}

void Level::Reset() {
	// 重置时间，分数
	time_left_ = 60;
	score_ = 0;

	// 重置人物初始状态并完成初始化
	*character_ = *original_character_info_;

	// 释放掉当前已生成的子弹
	for (auto& i : game_element_list_[BULLET]) {
		i->Unload(); // Unload()子弹的绘制资源
		delete i;    // 释放掉当前子弹对象
	}
	// 清空子弹的链表（因为链表里存放的是指针变量）
	game_element_list_[BULLET].clear();

	// 重置怪物初始状态
	// 先释放掉剩下的怪物
	for (auto& i : game_element_list_[MONSTER]) {
		i->Unload();
		delete i;
	}
	game_element_list_[MONSTER].clear();
	//再重新向链表中插入怪物对象并完成初始化
	for (auto i : original_monster_info_) {
		if (typeid(*(i->GetClassType())) == typeid(Minion)) {
			game_element_list_[MONSTER].push_back(new Minion(*dynamic_cast<Minion*>(i)));
			game_element_list_[MONSTER].back()->Load();
		}
		else if (typeid(*(i->GetClassType())) == typeid(Deathless)) {
			game_element_list_[MONSTER].push_back(new Deathless(*dynamic_cast<Deathless*>(i)));
			game_element_list_[MONSTER].back()->Load();
		}
		else if (typeid(*(i->GetClassType())) == typeid(Boss)) {
			game_element_list_[MONSTER].push_back(new Boss(*dynamic_cast<Boss*>(i)));
			game_element_list_[MONSTER].back()->Load();
		}
	}

	// 重置buff初始状态
	// 先释放掉剩下的buff
	for (auto& i : game_element_list_[BUFF]) {
		i->Unload();
		delete i;
	}
	game_element_list_[BUFF].clear();
	// 再在最开始的那个位置随机生成个buff
	srand(unsigned(time(nullptr)));
	game_element_list_[BUFF].push_back(new Buff(static_cast<Buffs>(rand() % NUM_OF_BUFF_TYPES), buff_rect_));
	game_element_list_[BUFF].back()->Load();

	// 重置trap初始状态
	auto i = game_element_list_[TRAP].begin();
	auto j = original_trap_info_.begin();
	while (i != game_element_list_[TRAP].end()) {
		*dynamic_cast<Trap*>(*i) = *j;
		++i;
		++j;
	}
}

void Level::Process() {
	while (!GetIsReadyForExit() && !GetIsReadyForRestart() && !GetIsReadyForNextGameState()) {
		AESysFrameStart();
		AEInputUpdate();

		// 处理游戏状态切换
		if (Input::GetPressedKey(KEY_ESC).GetIsPressed()) {
			SetIsReadyForExit();
			Input::GetPressedKey(KEY_ESC).SetIsPressed(false);
			continue;
		}
		if (Input::GetPressedKey(KEY_BACKSPACE).GetIsPressed()) {
			SetIsReadyForRestart();
			Input::GetPressedKey(KEY_BACKSPACE).SetIsPressed(false);
			continue;
		}
		// 检查人物是否已经到终点了
		if (IsReachEnd()) {
			SetIsReadyForNextGameState();
			continue;
		}

		// 处理上次循环倒计时到0时该弹出的会话框
		if (is_game_over_) {
			// 调用game_over会话框
			DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_GAME_OVER), System::GetHandle(), Input::HandleForGameOver);
			is_game_over_ = false;
			continue;
		}

		// 处理游戏倒计时
		++count_;
		if (count_ == System::GetFrameRate()) {
			count_ = 0;
			--time_left_;
		}
		if (time_left_ == 0) {
			is_game_over_ = true;
			// 在下次循环时调用会话框，以便把时间倒计时到0的数字画出来
		}

		// 更新游戏元素
		character_->Update();
		if (AEInputCheckTriggered('A')) {
			game_element_list_[BULLET].push_back(character_->Attack());
			game_element_list_[BULLET].back()->Load();
		}
		else if (AEInputCheckTriggered('S')) {
			//game_element_list_[SKILL].push_back(character_->UseSkill());
			//game_element_list_[SKILL].back()->Load();
		}
		for (auto& list : game_element_list_)
			for (auto& i : list)
				i->Update();

		// 碰撞检测（人和墙体的碰撞检测写在Character::Move()里了）
		BulletWallCollisionCheck();
		BulletMonsterCollisionCheck();
		CharacterMonsterCollisionCheck();
		CharacterBuffCollisionCheck();

		// 画出更新后的游戏元素
		character_->Draw();
		for (auto& list : game_element_list_)
			for (auto& i : list)
				i->Draw();
		// 画出墙体
		for (auto& i : wall_list_)
			i.second.Draw();
	
		// 显示时间
		Number time_left_tens_digit(time_left_ / 10, number_picture_[time_left_ / 10], 910, 10);
		time_left_tens_digit.Draw();
		Number time_left_units_digit(time_left_ % 10, number_picture_[time_left_ % 10], 925, 10);
		time_left_units_digit.Draw();

		// 显示分数
		// 

		// 显示状态信息
		// 人物剩余生命数
		Number lives(character_->GetLives(), number_picture_[character_->GetLives()], 910, 100);
		lives.Draw();
		// 人物攻击力数值
		int damage = character_->GetDamage();
		Number damage_tens_digit(damage / 10, number_picture_[damage / 10], 910, 120);
		damage_tens_digit.Draw();
		Number damage_units_digit(damage % 10, number_picture_[damage % 10], 925, 120);
		damage_units_digit.Draw();
		// 人物移动速度
		Number speed(character_->GetSpeed(), number_picture_[character_->GetSpeed()], 910, 140);
		speed.Draw();
		// 人物技能冷却缩减
		//

		AESysFrameEnd();
	}
}


void Level::Unload() {
	character_->Unload();
	delete character_;
	for (auto& list : game_element_list_) {
		for (auto& i : list) {
			i->Unload();
			delete i;
		}
		list.clear();
	}
	wall_list_.clear();

	delete original_character_info_;
	for (auto& i : original_monster_info_)
		delete i;
	original_monster_info_.clear();
	original_trap_info_.clear();

	// 重置有效按键
	Input::ResetPressedKey();
}

bool Level::IsReachEnd() const {
	return character_->GetRect() == ending_rect_;
}

void Level::BulletWallCollisionCheck() {
	for (auto i = game_element_list_[BULLET].begin(); i != game_element_list_[BULLET].end();) {
		auto temp_j = (*i)->GetRect().GetX() / grid_size_;
		auto temp_i = (*i)->GetRect().GetY() / grid_size_;
		auto wall = wall_list_.find(Rect(grid_size_, temp_j * grid_size_, temp_i * grid_size_));
		if (wall != wall_list_.end()) {
			if ((*i)->GetRect().IsCollision(wall->second.GetRect())) {
				(*i)->Unload();
				delete *i;
				i = game_element_list_[BULLET].erase(i);
			}
		}
		else
			++i;
	}
}

void Level::BulletMonsterCollisionCheck() {
	bool flag = true;
	for (auto i = game_element_list_[BULLET].begin(); flag && i != game_element_list_[BULLET].end();) {
		bool i_should_increase = true;
		for (auto j = game_element_list_[MONSTER].begin(); flag && j != game_element_list_[MONSTER].end();) {
			if (i != game_element_list_[BULLET].end()) {
				if ((*i)->GetRect().IsCollision((*j)->GetRect())) {
					int damage = character_->GetDamage();
					if (!dynamic_cast<Monster*>(*j)->DecHealth(damage)) {
						Rect temp_monster_rect = (*j)->GetRect();
						(*j)->Unload();
						delete *j;
						j = game_element_list_[MONSTER].erase(j);
						srand(unsigned(time(nullptr)));
						game_element_list_[BUFF].push_back(new Buff(static_cast<Buffs>(rand() % NUM_OF_BUFF_TYPES), temp_monster_rect));
						game_element_list_[BUFF].back()->Load();
					}
					if (j != game_element_list_[MONSTER].end())
						++j;
					(*i)->Unload();
					delete *i;
					i = game_element_list_[BULLET].erase(i);
					i_should_increase = false;
				}
				else
					++j;
			}
			else
				flag = false;
		}
		if (i_should_increase)
			++i;
	}
}

void Level::CharacterMonsterCollisionCheck() {
	for (auto& i : game_element_list_[MONSTER]) {
		if (character_->GetRect().IsCollision(i->GetRect())) {
			if (character_->DecLives()) {
				character_->SetRect(starting_rect_);
			}
			else
 				is_game_over_ = true;
			break;
		}
	}
}

void Level::CharacterBuffCollisionCheck() {
	for (auto& i : game_element_list_[BUFF]) {
		if (dynamic_cast<Buff*>(i)->GetStatus() == EXISTING) {
			if (character_->GetRect().IsCollision(i->GetRect())) {
				Buff* p_buff = dynamic_cast<Buff*>(i);
				switch (p_buff->GetType()) {
					case TIME:
						time_left_ += 15;
						p_buff->SetVanished();
						break;
					case SCORE:
						score_ += 100;
						p_buff->SetVanished();
						break;
					default:
						p_buff->SetTargetCharacter(character_);
						p_buff->TakeEffect();
						break;
				}
			}
		}
	}
}
