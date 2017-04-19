/**
 * Project:      NewGame
 * File Name:    GlobalVariable.h
 * Author:       Atlas Shen
 * Date:         2017/4/17
 * Purpose:      全局变量常量头文件
 */

#pragma once

#include <fstream>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"
#include "GameStateManager.h"

// 必须为静态成员变量提供类外部的声明，否则链接时会出问题

std::ofstream System::log_file_;
AESysInitInfo System::sys_init_info_;
std::streambuf* System::streambuf_pointer_;
std::ofstream System::console_out_;

bool Input::pressed_key_[NUM_OF_KEY];

GameState* GameStateManager::game_state_[NUM_OF_GAME_STATES];
GameState** GameStateManager::game_state_pointer_;
