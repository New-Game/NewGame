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
			static_collision_data_[i][j] = map_grid_info;
			auto temp_x = j * grid_size_ + grid_size_ / 2;
			auto temp_y = i * grid_size_ + grid_size_ / 2;
			Rect temp_rect(grid_size_, temp_x, temp_y);
			switch (map_grid_info) {
				case ROAD:
					// do nothing
					break;
				case WALL:
					game_element_list_[WALL].push_back(new Wall(temp_rect, "picture\\ice.png"));
					game_element_list_[WALL].back()->Load();
					break;
				case TRAP:
					break;
				case CHARACTER:
					game_element_list_[CHARACTER].push_back(new Aimiliya(temp_rect, "picture\\aimiliya.png"));
					game_element_list_[CHARACTER].back()->Load();
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
		if (IsReachEnd())
			SetIsReadyForNextGameState();
		AESysFrameEnd();
	}
}


void Level::Unload() {
	for (auto& list : game_element_list_)
		for (auto& i : list) {
			i->Unload();
			delete i;
		}

	for (auto& list : game_element_list_)
		list.empty();

	// 重置有效按键
	Input::ResetPressedKey();
}

bool Level::IsReachEnd() const {
	//x = 855
	//y = 45
	auto pointer_to_character = game_element_list_[CHARACTER].back();
	if (abs(pointer_to_character->GetRect().GetX() - 255.0f) < 5.0f 
		&& abs(pointer_to_character->GetRect().GetY() - 45.0f) < 5.0f)
			return true;
	return false;
}
