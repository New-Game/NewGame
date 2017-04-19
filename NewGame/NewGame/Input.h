/* Project:      NewGame
 * File Name:    Input.h
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      输入模块头文件
 */

#pragma once

#include <Windows.h>
#include <cstdlib>
#include "System.h"

//------------------------------------------------------------------------------
// Typedef:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

enum Key {
	KEY_ENTER,
	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_ESC,
	KEY_A,
	KEY_S,
	KEY_Y,
	KEY_N,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	NUM_OF_KEY
};

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Classes:
//------------------------------------------------------------------------------

// Input类的实现完全只是为了封装与它相关的状态量（成员变量）和行为（成员函数）
// 因此它的成员都是static的，static成员变量相当于全局变量，static成员函数相当于全局函数
// Input类不能用于生成对象（实例）
class Input {
public:
	// 处理、响应输入的回调函数
	static LRESULT CALLBACK Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	static bool GetPressedKey(enum Key key) {
		return pressed_key_[key];
	}

	// 用于重置key_pressed[]数组
	static void ResetPressedKey() {
		memset(pressed_key_, false, NUM_OF_KEY);

		// 写log
		System::GetLogFile() << "Input: Set" << endl;
	}

private:
	// 由于是全局变量，声明后自动全为false，因此不用特地初始化
	static bool pressed_key_[NUM_OF_KEY];
};

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
