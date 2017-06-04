/**
 * Project:      NewGame
 * File Name:    Level.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      关卡类头文件
 */

#pragma once

#include <list>
#include <unordered_map>
#include "GameState.h"
#include "System.h"
#include "GameElement.h"
#include "Wall.h"
#include "Character.h"
#include "Monster.h"

namespace std {
	template<>
	struct hash<Rect> : _Bitwise_hash<Rect> {}; // hash functor for Rect
}

// 用来构造game_element_list_[]数组下标
enum GameElements {
	//ROAD,
	//WALL,
	TRAP,
	CHARACTER,
	MONSTER,
	BULLET,
	//TREASURE,
	BUFF,
	NUM_OF_GAME_ELEMENT_TYPE,
};

// 用来识别地图配置文件中的数字
enum MapElements {
	ROAD,
	WALL,
	STARTING_POINT,
	ENDING_POINT,
	MINION,
	DEATHLESS,
	BOSS 
};

// 关卡类，多实例类，每个关卡都是它的一个对象
class Level : public GameState {
public:
	Level(string config_file_name) : 
			grid_size_(30), 
			num_of_map_width_grid_(30), 
			num_of_map_height_grid_(20), 
			character_status_bar_width_(100), 
			map_config_file_(config_file_name), 
			starting_rect_(), 
			ending_rect_(), 
			original_character_info_(nullptr) {}
	Level() : 
			grid_size_(30), 
			num_of_map_width_grid_(30), 
			num_of_map_height_grid_(20), 
			character_status_bar_width_(100), 
			map_config_file_(), 
			starting_rect_(), 
			ending_rect_(), 
			original_character_info_(nullptr) {}
	~Level() {}

	void Load() override;
	void Reset() override;
	void Process() override;
	void Unload() override;

	// 用来存所有指向游戏元素对象的指针
	static list<GameElement*> game_element_list_[NUM_OF_GAME_ELEMENT_TYPE];

	// 用来存所有指向墙体对象的指针
	static unordered_map<Rect, Wall> wall_list_;
	

private:
	const int grid_size_;
	const int num_of_map_width_grid_;
	const int num_of_map_height_grid_;
	const int character_status_bar_width_;

	ifstream map_config_file_;
	Rect starting_rect_;
	Rect ending_rect_;
	Character* original_character_info_;
	list<Monster*> original_monster_info_;

	bool IsReachEnd() const;
	void BulletWallCollisionCheck() const;
	void BulletMonsterCollisionCheck() const;
	void CharacterMonsterCollisionCheck();

};
