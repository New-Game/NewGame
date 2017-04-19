/**
 * Project:      NewGame
 * File Name:    GlobalVariable.h
 * Author:       Atlas Shen
 * Date:         2017/4/17
 * Purpose:      ȫ�ֱ�������ͷ�ļ�
 */

#pragma once

#include <fstream>
#include "AEEngine.h"
#include "System.h"
#include "Input.h"
#include "GameStateManager.h"

// ����Ϊ��̬��Ա�����ṩ���ⲿ����������������ʱ�������

std::ofstream System::log_file_;
AESysInitInfo System::sys_init_info_;
std::streambuf* System::streambuf_pointer_;
std::ofstream System::console_out_;

bool Input::pressed_key_[NUM_OF_KEY];

GameState* GameStateManager::game_state_[NUM_OF_GAME_STATES];
GameState** GameStateManager::game_state_pointer_;
