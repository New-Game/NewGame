/**
 * Project:      NewGame
 * File Name:    GameElementManager.cpp
 * Author:       Atlas Shen
 * Date:         2017/5/02
 * Purpose:      游戏元素管理器类实现文件
 */

#include "GameElementManager.h"
#include "Wall.h"

void GameElementManager::Load() {
	for (auto i = 0; i < num_of_map_height_grid_; ++i) {
		for (auto j = 0; j < num_of_map_width_grid_; ++j) {
			int map_grid_info;
			config_file_ >> map_grid_info;
			auto temp_x = j * grid_size_ + grid_size_ / 2;
			auto temp_y = i * grid_size_ + grid_size_ / 2;
			switch(map_grid_info) {
				case ROAD:
					// do nothing
					break;
				case WALL:
					game_element_[WALL].push_back(new Wall(grid_size_, temp_x, temp_y, "picture\\wall.png"));
					game_element_[WALL].back()->Load();
					break;
				case TRAP:
					break;
				case CHARACTER:
					break;
				case MONSTER:
					break;
				default:
					break;
			}
		}
	}
}

// 设置人物、怪物、物品的初始状态
void GameElementManager::Initialize() {
	for (auto& list : game_element_)
		for (auto& i : list)
			i->Initialize();
}

void GameElementManager::Update() {
	for (auto& list : game_element_)
		for (auto& i : list)
			i->Update();
}

void GameElementManager::Draw() {
	for (auto& list : game_element_)
		for (auto& i : list)
			i->Draw();
}

// 释放游戏中途生成的对象（不释放在Load()中生成的对象）
void GameElementManager::Free() {
	for (auto& list : game_element_)
		for (auto& i : list)
			i->Free();
}

void GameElementManager::Unload() {
	for (auto& list : game_element_)
		for (auto& i : list) {
			i->Unload();
			delete i;
		}
}
