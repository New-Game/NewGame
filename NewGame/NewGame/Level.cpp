/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ʵ���ļ�
 */

#include "Level.h"
#include "Input.h"
#include "Wall.h"
#include "Aimiliya.h"
#include "Monster.h"
#include "Minion.h"

void Level::Load() {
	// �����ñ�״̬��Щ��λ����Ч��
	Input::GetPressedKey(KEY_SPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_BACKSPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_ESC).SetIsValid(true);
	Input::GetPressedKey(KEY_A).SetIsValid(true);
	Input::GetPressedKey(KEY_S).SetIsValid(true);
	Input::GetPressedKey(KEY_UP).SetIsValid(true);
	Input::GetPressedKey(KEY_DOWN).SetIsValid(true);
	Input::GetPressedKey(KEY_LEFT).SetIsValid(true);
	Input::GetPressedKey(KEY_RIGHT).SetIsValid(true);

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
					wall_list_.insert(make_pair(temp_rect, Wall(temp_rect, "picture\\ice.png")));
					wall_list_[temp_rect].Load();
					break;
				case TRAP:
					break;
				case CHARACTER:
					game_element_list_[CHARACTER].push_back(new Aimiliya(temp_rect, "picture\\aimiliya.png"));
					game_element_list_[CHARACTER].back()->Load();
					break;
				case MONSTER:
					game_element_list_[MONSTER].push_back(new Minion(temp_rect, "picture\\minion.png"));
					break;
				case Ending:
					ending_ = temp_rect;
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
		i->Load();
	}
}

// ����������ޡ���Ʒ�ĳ�ʼ״̬
void Level::Reset() {
	// ���������ʼ״̬
	game_element_list_[CHARACTER].back()->Reset();

	// �ͷŵ���ǰ�����ɵ��ӵ�
	for (auto& i : game_element_list_[BULLET]) {
		i->Unload(); // Unload()�ӵ��Ļ�����Դ
		delete i;    // �ͷŵ���ǰ�ӵ�����
	}
	// ����ӵ���������Ϊ�������ŵ���ָ�������
	game_element_list_[BULLET].clear();

	// ���ù����ʼ״̬
	for (auto& i : game_element_list_[MONSTER])
		i->Reset();

	// ����buff��ʼ״̬
	//game_element_list_[BUFF].back()->Reset();
}

void Level::Process() {
	while (!GetIsReadyForExit() && !GetIsReadyForRestart() && !GetIsReadyForNextGameState()) {
		AESysFrameStart();

		// ������Ϸ״̬�л�
		if (Input::GetPressedKey(KEY_ESC).GetIsPressed()) {
			SetIsReadyForExit();
			Input::GetPressedKey(KEY_ESC).SetIsPressed(false);
		}
		else if (Input::GetPressedKey(KEY_BACKSPACE).GetIsPressed()) {
			SetIsReadyForRestart();
			Input::GetPressedKey(KEY_BACKSPACE).SetIsPressed(false);
		}
		// ��������Ƿ��Ѿ����յ���
		if (IsReachEnd())
			SetIsReadyForNextGameState();
		
		// ������ϷԪ��
		for (auto& list : game_element_list_)
			for (auto& i : list)
				i->Update();

		// ��ײ��⣨�����ǽ�����ײ��ⲻ�����У�
		BulletWallCollisionCheck();
		BulletMonsterCollisionCheck();
		CharacterMonsterCollisionCheck();

		// �������º����ϷԪ��
		for (auto& list : game_element_list_)
			for (auto& i : list)
				i->Draw();
		// ����ǽ��
		for (auto& i : wall_list_)
			i.second.Draw();
		
		AESysFrameEnd();
	}
}


void Level::Unload() {
	for (auto& list : game_element_list_)
		for (auto& i : list) {
			if (i != nullptr) {
				i->Unload();
				delete i;
			}
		}

	for (auto& list : game_element_list_)
		list.clear();
	wall_list_.clear();

	// ������Ч����
	Input::ResetPressedKey();
}

bool Level::IsReachEnd() const {
	return game_element_list_[CHARACTER].back()->GetRect() == ending_;
}

void Level::BulletWallCollisionCheck() const {
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

void Level::BulletMonsterCollisionCheck() const {
	bool i_should_increase = true;
	for (auto i = game_element_list_[BULLET].begin(); i != game_element_list_[BULLET].end();) {
		for (auto j = game_element_list_[MONSTER].begin(); j != game_element_list_[MONSTER].end();) {
			if (i != game_element_list_[BULLET].end()) {
				if ((*i)->GetRect().IsCollision((*j)->GetRect())) {
					(*i)->Unload();
					delete *i;
					i = game_element_list_[BULLET].erase(i);
					i_should_increase = false;
					(*j)->Unload();
					delete *j;
					j = game_element_list_[MONSTER].erase(j);
				}
				else
					++j;
			}
			else
				goto END;
		}
		if (i_should_increase)
			++i;
	}
END:;
}

void Level::CharacterMonsterCollisionCheck() {
	for (auto& i : game_element_list_[MONSTER]) {
		if (game_element_list_[CHARACTER].back()->GetRect().IsCollision(i->GetRect()))
			Reset();
	}
}
