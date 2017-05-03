/**
 * Project:      NewGame
 * File Name:    GameElementManager.h
 * Author:       Atlas Shen
 * Date:         2017/5/02
 * Purpose:      游戏元素管理器类头文件
 */

#pragma once

#include <fstream>
#include <unordered_map>
#include <vector>
#include "GameElement.h"
#include "Position.h"

enum GameElementType {
	ROAD,
	WALL,
	TRAP,
	CHARACTER,
	MONSTER,
	NUM_OF_GAME_ELEMENT_TYPE
};

namespace std {
	template<>
	struct hash<Position> : public _Bitwise_hash<Position> {}; // hash functor for Position

	inline bool operator == (const Position& position1, const Position& position2) _NOEXCEPT {
		return position1.GetX() == position2.GetX() && position1.GetY() == position2.GetY();
	}
}

class GameElementManager : public State {
public:
	GameElementManager() : config_file_() {}
	GameElementManager(string config_file_name) : config_file_(config_file_name, ios::in) {}
	~GameElementManager() {
		config_file_.close();
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
	const float grid_size_ = 30;
	const int character_status_bar_width_ = 100;
	ifstream config_file_;
	unordered_map<Position, GameElement*> game_element_;
};
