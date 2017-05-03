/**
 * Project:      NewGame
 * File Name:    GameElementManager.h
 * Author:       Atlas Shen
 * Date:         2017/5/02
 * Purpose:      游戏元素管理器类头文件
 */

#pragma once

#include <unordered_map>
#include "GameElement.h"
#include "Position.h"

enum GameElementType {
	CHARACTER,
	MONSTER,
	WALL,
	TRAP,
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
	GameElementManager() {}
	GameElementManager(string config_file_name) : config_file_name_(config_file_name) {}
	~GameElementManager() {}

	void Load() override;
	void Initialize() override;
	void Update();
	void Draw();
	void Free() override;
	void Unload() override;

private:
	string config_file_name_;
	unordered_map<Position, GameElement*> game_element_map_;
};
