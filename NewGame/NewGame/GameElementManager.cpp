/**
 * Project:      NewGame
 * File Name:    GameElementManager.cpp
 * Author:       Atlas Shen
 * Date:         2017/5/02
 * Purpose:      ��ϷԪ�ع�������ʵ���ļ�
 */

#include "GameElementManager.h"
#include "Wall.h"
#include "Aimiliya.h"

// ֻ����ǽ�塢���壬������������Ϣ�������鱣��
void GameElementManager::Load() {
	for (auto i = 0; i < num_of_map_height_grid_; ++i) {
		for (auto j = 0; j < num_of_map_width_grid_; ++j) {
			int map_grid_info;
			config_file_ >> map_grid_info;
			collision_data_[i][j] = map_grid_info;
			auto temp_x = j * grid_size_ + grid_size_ / 2;
			auto temp_y = i * grid_size_ + grid_size_ / 2;
			switch(map_grid_info) {
				case ROAD:
					// do nothing
					break;
				case WALL:
					game_element_list_[WALL].push_back(new Wall(grid_size_, temp_x, temp_y, "picture\\ice.png"));
					game_element_list_[WALL].back()->Load();
					break;
				case TRAP:
					break;
				case CHARACTER: {
					Rect temp_rect(grid_size_, temp_x, temp_y);
					position_list_[CHARACTER].push_back(temp_rect);
					break;
				}
				case MONSTER:
					break;
				default:
					break;
			}
		}
	}
}

// ������������Ʒ�ĳ�ʼ״̬
void GameElementManager::Initialize() {
	for (auto& i : position_list_[CHARACTER]) {
		game_element_list_[CHARACTER].push_back(new Aimiliya(i, "picture\\aimiliya.png"));
		game_element_list_[CHARACTER].back()->Load();
	}

	for (auto& list : game_element_list_)
		for (auto& i : list)
			i->Initialize();
}

void GameElementManager::Update() {
	for (auto& list : game_element_list_)
		for (auto& i : list)
			i->Update();
}

void GameElementManager::Draw() {
	for (auto& list : game_element_list_)
		for (auto& i : list)
			i->Draw();
}

// �ͷ���Ϸ��;���ɵĶ��󣨲��ͷ���Load()�����ɵĶ���
void GameElementManager::Free() {
	for (auto& list : game_element_list_)
		for (auto& i : list)
			i->Free();
}

void GameElementManager::Unload() {
	for (auto& list : game_element_list_)
		for (auto& i : list) {
			i->Unload();
			delete i;
		}
}

bool GameElementManager::Check() const {
	//x = 855
	//y = 45
	for (auto& i : game_element_list_[CHARACTER]) {
		if (abs(i->GetRect().GetX() - 255.0f) < 5.0f && abs(i->GetRect().GetY() - 45.0f) < 5.0f)
			return true;
	}
	return false;
}