/**
 * Project:      NewGame
 * File Name:    Input.h
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      输入模块头文件
 */

#pragma once

#include <Windows.h>
#include "System.h"

enum Keys {
	KEY_ENTER,
	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_ESC,
	KEY_A,
	KEY_S,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	NUM_OF_KEY
};

class KeyStatus {
public:
	KeyStatus() : is_valid_(false), is_pressed_(false) {}

	KeyStatus(const KeyStatus& key_status) : 
	          is_valid_(key_status.GetIsValid()), is_pressed_(key_status.GetIsPressed()) {}

	~KeyStatus() {}

	bool GetIsValid() const {
		return is_valid_;
	}

	bool GetIsPressed() const {
		return is_pressed_;
	}

	void SetIsValid(bool boolean_value) {
		is_valid_ = boolean_value;
	}

	void SetIsPressed(bool boolean_value) {
		is_pressed_ = boolean_value;
	}

private:
	bool is_valid_;
	bool is_pressed_;
};

// Input类的实现完全只是为了封装与它相关的状态量（成员变量）和行为（成员函数）
// 因此它的成员都是static的，static成员变量相当于全局变量，static成员函数相当于全局函数
// Input类不能用于生成对象（实例）
class Input {
public:
	// 处理、响应输入的回调函数
	//
	static LRESULT CALLBACK MainHandle(HWND, UINT, WPARAM, LPARAM);

	static INT_PTR CALLBACK HandleForExit(HWND, UINT, WPARAM, LPARAM);

	static INT_PTR CALLBACK HandleForResume(HWND, UINT, WPARAM, LPARAM);
	
	static INT_PTR CALLBACK HandleForRestart(HWND, UINT, WPARAM, LPARAM);

	static KeyStatus& GetPressedKey(Keys keys) {
		return pressed_key_[keys];
	}

	// 用于在每个状态退出时重置pressed_key_数组
	static void ResetPressedKey() {
		for (auto& i : pressed_key_)
			i.SetIsValid(false);
	}

private:
	static KeyStatus pressed_key_[NUM_OF_KEY];
};
