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

// �꣨���Ե�����һЩ������
#define WINDOW_WIDTH   1200
#define WINDOW_HEIGHT  600

// ����Ϊ��̬��Ա�����ṩ���ⲿ����������������ʱ������⣨���ɱ��޸ģ�
//
AESysInitInfo System::sys_init_info_;
WNDCLASS System::win_class_;
HINSTANCE System::h_instance_;
std::ofstream System::log_file_;
std::streambuf* System::streambuf_pointer_;
std::ofstream System::console_out_;

bool Input::pressed_key_[NUM_OF_KEY];

GameState* GameStateManager::game_state_[NUM_OF_GAME_STATES];
GameState** GameStateManager::game_state_pointer_;
