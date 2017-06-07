/**
 * Project:      NewGame
 * File Name:    Global.h
 * Author:       Atlas Shen
 * Date:         2017/4/17
 * Purpose:      全局变量常量头文件
 */

#pragma once

#include <Windows.h>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"
#include "GameStateManager.h"
#include "Level.h"

// 必须为静态成员变量提供类外部的声明，否则链接时会出问题（不可被修改）
//
const int System::window_width_;
const int System::window_height_;
const unsigned System::frame_rate_;
AESysInitInfo System::sys_init_info_;
WNDCLASS System::win_class_;
HINSTANCE System::instance_;
HWND System::handle_;
//streambuf* System::streambuf_pointer_;
//ofstream System::console_out_;

KeyStatus Input::pressed_key_[NUM_OF_KEY];

GameState* GameStateManager::game_state_list_[NUM_OF_GAME_STATES];
GameState** GameStateManager::game_state_pointer_;

unordered_map<Rect, Wall> Level::wall_list_;
const string Level::number_picture_[10] = {
	"picture\\0.png", "picture\\1.png", "picture\\2.png", "picture\\3.png", "picture\\4.png",
	"picture\\5.png", "picture\\6.png", "picture\\7.png", "picture\\8.png", "picture\\9.png"};
