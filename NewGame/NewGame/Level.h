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
#include <fstream>
#include "GameState.h"
#include "GameElement.h"
#include "Wall.h"
#include "Character.h"
#include "Monster.h"
#include "Trap.h"

namespace std {
	template<>
	struct hash<Rect> : _Bitwise_hash<Rect> {}; // hash functor for Rect
}

// 用来构造game_element_list_[]数组下标
enum GameElements {
	CHARACTER,
	MONSTER,
	BUFF,
	TRAP,
	BULLET,
	NUM_OF_GAME_ELEMENT_TYPES
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
			is_game_over_(false), 
			count_(0), 
			time_left_(60), 
			score_(0), 
			starting_rect_(), 
			ending_rect_(), 
			original_character_info_(nullptr) {}

	Level() : Level("") {}

	~Level() {}

	void Load() override;

	void Reset() override;

	void Process() override;

	void Unload() override;

	// 用来存所有指向游戏元素对象的指针
	static list<GameElement*> game_element_list_[NUM_OF_GAME_ELEMENT_TYPES];

	// 用来存所有指向墙体对象的指针
	static unordered_map<Rect, Wall> wall_list_;
	

private:
	// 用来识别地图配置文件中的数字
	enum MapElements {
		ROAD,
		WALL,
		STARTING_POINT,
		ENDING_POINT,
		MINION,
		DEATHLESS,
		BOSS,
		SLOW_TRAP,
		KILL_TRAP,
		BACK_TRAP,
		WEAK_TRAP,
		RANDOM_BUFF
	};

	const int grid_size_;
	const int num_of_map_width_grid_;
	const int num_of_map_height_grid_;
	const int character_status_bar_width_;

	ifstream map_config_file_;
	bool is_game_over_;
	int count_;
	int time_left_;
	int score_;
	Rect starting_rect_;
	Rect ending_rect_;
	Rect buff_rect_;
	Character* original_character_info_;
	list<Monster*> original_monster_info_;
	list<Trap> original_trap_info_;

	static const string number_picture_[10];

	bool IsReachEnd() const;
	
	void BulletWallCollisionCheck();
	
	void BulletMonsterCollisionCheck();

	void CharacterMonsterCollisionCheck();

	void CharacterBuffCollisionCheck();

};
