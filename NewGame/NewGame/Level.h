/**
 * Project:      NewGame
 * File Name:    Level.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ͷ�ļ�
 */

#pragma once

#include <list>
#include <vector>
#include "GameState.h"
#include "System.h"
#include "GameElement.h"

using namespace std;

// �ؿ��࣬��ʵ���࣬ÿ���ؿ���������һ������
class Level : public GameState {
public:
	Level(string config_file_name) : num_of_map_width_grid_(30),
	                                 num_of_map_height_grid_(20),
	                                 character_status_bar_width_(100),
	                                 map_config_file_(config_file_name) {
		static_collision_data_ = new int*[num_of_map_height_grid_];
		for (auto i = 0; i < num_of_map_height_grid_; ++i)
			static_collision_data_[i] = new int[num_of_map_width_grid_];
	}
	~Level() {}

	void Load() override;
	void Reset() override;
	void Process() override;
	void Unload() override;

	// ����������ָ����ϷԪ�ض����ָ��
	static list<GameElement*> game_element_list_[NUM_OF_GAME_ELEMENT_TYPE];

	// ��̬��ײ������
	static int **static_collision_data_;
	
	static const float grid_size_;

private:
	const int num_of_map_width_grid_;
	const int num_of_map_height_grid_;
	const int character_status_bar_width_;

	ifstream map_config_file_;

	bool IsReachEnd() const;
};
