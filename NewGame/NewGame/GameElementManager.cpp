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
			Position temp_position(j * grid_size_ + grid_size_ / 2, i * grid_size_ + grid_size_ / 2);
			switch(map_grid_info) {
				case ROAD:
					// do nothing
					break;
				case WALL:
					game_element_[temp_position] = new Wall(grid_size_, temp_position, "test2.png");
					game_element_[temp_position]->Load();
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
	for (auto& i : game_element_)
		i.second->Initialize();
}

void GameElementManager::Update() {
	for (auto& i : game_element_)
		i.second->Update();
}

void GameElementManager::Draw() {
	for (auto& i : game_element_)
		i.second->Draw();
}

// 释放游戏中途生成的对象（不释放在Load()中生成的对象）
void GameElementManager::Free() {
	for (auto& i : game_element_)
		i.second->Free();
}

void GameElementManager::Unload() {
	for (auto& i : game_element_) {
		i.second->Unload();
		delete i.second;
	}
}
