/**
 * Project:      NewGame
 * File Name:    GameElementManager.h
 * Author:       Atlas Shen
 * Date:         2017/5/02
 * Purpose:      游戏元素管理器类头文件
 */

#pragma once

#include <fstream>
#include <list>
#include <vector>
#include "GameElement.h"

enum GameElements {
	ROAD,
	WALL,
	TRAP,
	CHARACTER,
	MONSTER,
	BULLET,
	TREASURE,
	BUFF,
	NUM_OF_GAME_ELEMENT_TYPE
};

class GameElementManager : public State {
public:
	GameElementManager() : num_of_map_width_grid_(30), 
	                       num_of_map_height_grid_(20),
	                       grid_size_(30.0f), 
	                       character_status_bar_width_(100),
	                       config_file_() {
		collision_data_ = new int*[num_of_map_height_grid_];
		for (auto i = 0; i < num_of_map_height_grid_; ++i)
			collision_data_[i] = new int[num_of_map_width_grid_];
	}
	GameElementManager(string config_file_name) : num_of_map_width_grid_(30), 
	                                              num_of_map_height_grid_(20),
	                                              grid_size_(30.0f),
	                                              character_status_bar_width_(100),
	                                              config_file_(config_file_name, ios::in) {
		collision_data_ = new int*[num_of_map_height_grid_];
		for (auto i = 0; i < num_of_map_height_grid_; ++i)
			collision_data_[i] = new int[num_of_map_width_grid_];
	}
	~GameElementManager() {}

	void Load() override;
	void Initialize() override;
	void Update();
	void Draw();
	void Free() override;
	void Unload() override;

	bool Check() const;

	const int num_of_map_width_grid_;
	const int num_of_map_height_grid_;
	const float grid_size_;
	const int character_status_bar_width_;
	static int** collision_data_;

private:
	ifstream config_file_;
	list<GameElement*> game_element_list_[NUM_OF_GAME_ELEMENT_TYPE];
	vector<Rect> position_list_[NUM_OF_GAME_ELEMENT_TYPE];
};
