/**
 * Project:      NewGame
 * File Name:    Level.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ͷ�ļ�
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

// ��������game_element_list_[]�����±�
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

// ����ʶ���ͼ�����ļ��е�����
enum MapElements {
	ROAD,
	WALL,
	STARTING_POINT,
	ENDING_POINT,
	MINION,
	DEATHLESS,
	BOSS 
};

// �ؿ��࣬��ʵ���࣬ÿ���ؿ���������һ������
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

	// ����������ָ����ϷԪ�ض����ָ��
	static list<GameElement*> game_element_list_[NUM_OF_GAME_ELEMENT_TYPE];

	// ����������ָ��ǽ������ָ��
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
