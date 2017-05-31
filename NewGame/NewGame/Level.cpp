/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      关卡类实现文件
 */

#include "Level.h"
#include "Input.h"
#include "Wall.h"
#include "Aimiliya.h"

void Level::Load() {
	// 先设置本状态哪些键位是有效的
	Input::GetPressedKey(KEY_SPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_BACKSPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_ESC).SetIsValid(true);
	Input::GetPressedKey(KEY_A).SetIsValid(true);
	Input::GetPressedKey(KEY_S).SetIsValid(true);
	Input::GetPressedKey(KEY_UP).SetIsValid(true);
	Input::GetPressedKey(KEY_DOWN).SetIsValid(true);
	Input::GetPressedKey(KEY_LEFT).SetIsValid(true);
	Input::GetPressedKey(KEY_RIGHT).SetIsValid(true);

	// 把所有游戏对象信息加入链表保存
	for (auto i = 0; i < num_of_map_height_grid_; ++i) {
		for (auto j = 0; j < num_of_map_width_grid_; ++j) {
			int map_grid_info;
			map_config_file_ >> map_grid_info;
			switch (map_grid_info) {
				case ROAD:
					// do nothing
					break;
				case WALL: {
					Rect temp_rect(grid_size_, j * grid_size_, i * grid_size_, NONE);
					wall_list_.insert(make_pair(temp_rect, Wall(temp_rect, "picture\\ice.png")));
					wall_list_[temp_rect].Load();
					break;
				}
				case TRAP:
					break;
				case CHARACTER: {
					Rect temp_rect(grid_size_, j * grid_size_, i * grid_size_, DOWN);
					game_element_list_[CHARACTER].push_back(new Aimiliya(temp_rect, "picture\\aimiliya.png"));
					game_element_list_[CHARACTER].back()->Load();
					break;
				}
				case MONSTER:
					break;
				default:
					break;
			}

		}
	}
}

// 重置人物、怪兽、物品的初始状态
void Level::Reset() {
	game_element_list_[CHARACTER].back()->Reset();
	for (auto& i : game_element_list_[BULLET]) {
		i->Unload();
		delete i;
	}
	game_element_list_[BULLET].clear();
	//for (auto& i : game_element_list_[MONSTER])
	//	i->Reset();
	//game_element_list_[BUFF].back()->Reset();
}

void Level::Process() {
	while (!GetIsReadyForExit() && !GetIsReadyForRestart() && !GetIsReadyForNextGameState()) {
		AESysFrameStart();
		if (Input::GetPressedKey(KEY_ESC).GetIsPressed()) {
			SetIsReadyForExit();
			Input::GetPressedKey(KEY_ESC).SetIsPressed(false);
		}
		else if (Input::GetPressedKey(KEY_BACKSPACE).GetIsPressed()) {
			SetIsReadyForRestart();
			Input::GetPressedKey(KEY_BACKSPACE).SetIsPressed(false);
		}
		for (auto& list : game_element_list_)
			for (auto& i : list)
				i->Update();
		for (auto& list : game_element_list_)
			for (auto& i : list)
				i->Draw();
		for (auto& i : wall_list_)
			i.second.Draw();
		//if (IsReachEnd())
		//	SetIsReadyForNextGameState();
		AESysFrameEnd();
	}
}


void Level::Unload() {
	for (auto& list : game_element_list_)
		for (auto& i : list) {
			if (i != nullptr) {
				i->Unload();
				delete i;
			}
		}

	for (auto& list : game_element_list_)
		list.clear();
	wall_list_.clear();

	// 重置有效按键
	Input::ResetPressedKey();
}

bool Level::IsReachEnd() const {
	return false;
}
