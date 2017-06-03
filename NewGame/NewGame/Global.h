/**
 * Project:      NewGame
 * File Name:    Global.h
 * Author:       Atlas Shen
 * Date:         2017/4/17
 * Purpose:      ȫ�ֱ�������ͷ�ļ�
 */

#pragma once

#include <fstream>
#include <Windows.h>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"
#include "GameStateManager.h"
#include "Level.h"

// ����Ϊ��̬��Ա�����ṩ���ⲿ����������������ʱ������⣨���ɱ��޸ģ�
//
const int System::window_width_;
const int System::window_height_;
AESysInitInfo System::sys_init_info_;
WNDCLASS System::win_class_;
HINSTANCE System::h_instance_;
//ofstream System::log_file_;
streambuf* System::streambuf_pointer_;
ofstream System::console_out_;

KeyStatus Input::pressed_key_[NUM_OF_KEY];

GameState* GameStateManager::game_state_[NUM_OF_GAME_STATES];
GameState** GameStateManager::game_state_pointer_;

list<GameElement*> Level::game_element_list_[NUM_OF_GAME_ELEMENT_TYPE];
unordered_map<Rect, Wall> Level::wall_list_;
