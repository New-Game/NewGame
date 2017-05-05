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
#include "GameElement.h"

enum GameElementType {
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
	GameElementManager() : config_file_() {}
	GameElementManager(string config_file_name) : config_file_(config_file_name, ios::in) {}
	~GameElementManager() {
		config_file_.close();
		for (auto& i : game_element_)
			i.clear();
	}

	void Load() override;
	void Initialize() override;
	void Update();
	void Draw();
	void Free() override;
	void Unload() override;

private:
	const int num_of_map_width_grid_ = 30;
	const int num_of_map_height_grid_ = 20;
	const float grid_size_ = 30.0f;
	const int character_status_bar_width_ = 100;
	ifstream config_file_;
	list<GameElement*> game_element_[NUM_OF_GAME_ELEMENT_TYPE];
};
