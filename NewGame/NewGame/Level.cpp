/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ʵ���ļ�
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
	// �����ñ�״̬��Щ��λ����Ч��
	Input::GetPressedKey(KEY_SPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_BACKSPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_ESC).SetIsValid(true);
	//Input::GetPressedKey(KEY_A).SetIsValid(true);
	//Input::GetPressedKey(KEY_S).SetIsValid(true);
	//Input::GetPressedKey(KEY_UP).SetIsValid(true);
	//Input::GetPressedKey(KEY_DOWN).SetIsValid(true);
	//Input::GetPressedKey(KEY_LEFT).SetIsValid(true);
	//Input::GetPressedKey(KEY_RIGHT).SetIsValid(true);

	// ��ȡ�ļ��е����־��󣬰�������Ϸ������Ϣ���������棬ǽ���������ϣ����
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

	//  ��ȡ�Ĺ��޵ĺ����������Χ��Ϣ
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
	// ����ʱ�䣬����
	time_left_ = 60;
	score_ = 0;

	// ���������ʼ״̬����ɳ�ʼ��
	*character_ = *original_character_info_;

	// �ͷŵ���ǰ�����ɵ��ӵ�
	for (auto& i : game_element_list_[BULLET]) {
		i->Unload(); // Unload()�ӵ��Ļ�����Դ
		delete i;    // �ͷŵ���ǰ�ӵ�����
	}
	// ����ӵ���������Ϊ�������ŵ���ָ�������
	game_element_list_[BULLET].clear();

	// ���ù����ʼ״̬
	// ���ͷŵ�ʣ�µĹ���
	for (auto& i : game_element_list_[MONSTER]) {
		i->Unload();
		delete i;
	}
	game_element_list_[MONSTER].clear();
	//�������������в�����������ɳ�ʼ��
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

	// ����buff��ʼ״̬
	// ���ͷŵ�ʣ�µ�buff
	for (auto& i : game_element_list_[BUFF]) {
		i->Unload();
		delete i;
	}
	game_element_list_[BUFF].clear();
	// �����ʼ���Ǹ�λ��������ɸ�buff
	srand(unsigned(time(nullptr)));
	game_element_list_[BUFF].push_back(new Buff(static_cast<Buffs>(rand() % NUM_OF_BUFF_TYPES), buff_rect_));
	game_element_list_[BUFF].back()->Load();

	// ����trap��ʼ״̬
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

		// ������Ϸ״̬�л�
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
		// ��������Ƿ��Ѿ����յ���
		if (IsReachEnd()) {
			SetIsReadyForNextGameState();
			continue;
		}

		// �����ϴ�ѭ������ʱ��0ʱ�õ����ĻỰ��
		if (is_game_over_) {
			// ����game_over�Ự��
			DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_GAME_OVER), System::GetHandle(), Input::HandleForGameOver);
			is_game_over_ = false;
			continue;
		}

		// ������Ϸ����ʱ
		++count_;
		if (count_ == System::GetFrameRate()) {
			count_ = 0;
			--time_left_;
		}
		if (time_left_ == 0) {
			is_game_over_ = true;
			// ���´�ѭ��ʱ���ûỰ���Ա��ʱ�䵹��ʱ��0�����ֻ�����
		}

		// ������ϷԪ��
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

		// ��ײ��⣨�˺�ǽ�����ײ���д��Character::Move()���ˣ�
		BulletWallCollisionCheck();
		BulletMonsterCollisionCheck();
		CharacterMonsterCollisionCheck();
		CharacterBuffCollisionCheck();

		// �������º����ϷԪ��
		character_->Draw();
		for (auto& list : game_element_list_)
			for (auto& i : list)
				i->Draw();
		// ����ǽ��
		for (auto& i : wall_list_)
			i.second.Draw();
	
		// ��ʾʱ��
		Number time_left_tens_digit(time_left_ / 10, number_picture_[time_left_ / 10], 910, 10);
		time_left_tens_digit.Draw();
		Number time_left_units_digit(time_left_ % 10, number_picture_[time_left_ % 10], 925, 10);
		time_left_units_digit.Draw();

		// ��ʾ����
		// 

		// ��ʾ״̬��Ϣ
		// ����ʣ��������
		Number lives(character_->GetLives(), number_picture_[character_->GetLives()], 910, 100);
		lives.Draw();
		// ���﹥������ֵ
		int damage = character_->GetDamage();
		Number damage_tens_digit(damage / 10, number_picture_[damage / 10], 910, 120);
		damage_tens_digit.Draw();
		Number damage_units_digit(damage % 10, number_picture_[damage % 10], 925, 120);
		damage_units_digit.Draw();
		// �����ƶ��ٶ�
		Number speed(character_->GetSpeed(), number_picture_[character_->GetSpeed()], 910, 140);
		speed.Draw();
		// ���＼����ȴ����
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

	// ������Ч����
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
