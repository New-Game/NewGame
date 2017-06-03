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
			switch (map_grid_info) {
				case ROAD:
					// do nothing
					break;
				case WALL: {
					Rect temp_rect(grid_size_, j * grid_size_, i * grid_size_);
					wall_list_.insert(make_pair(temp_rect, Wall(temp_rect, "picture\\ice.png")));
					wall_list_[temp_rect].Load();
					break;
				}
				case TRAP:
					break;
				case CHARACTER: {
					Rect temp_rect(grid_size_, j * grid_size_, i * grid_size_);
					game_element_list_[CHARACTER].push_back(new Aimiliya(temp_rect, "picture\\aimiliya.png"));
					game_element_list_[CHARACTER].back()->Load();
					break;
				}
				case MONSTER:
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
	//for (auto& i : game_element_list_[MONSTER])
	//	i->Reset();

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
	return false;
}
