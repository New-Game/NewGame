/* Project:      NewGame
 * File Name:    Input.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      输入模块实现文件
 */

#include <iostream>
#include "Input.h"
#include "System.h"

using namespace std;

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Memeber Functions:
//------------------------------------------------------------------------------

LRESULT CALLBACK Input::Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC dc;           // 设备
	PAINTSTRUCT ps;   // 重绘结构

	// 写log
	System::log_file_ << "Input: Handle." << endl;

	switch (msg) {
		// 窗口创建
		case WM_CREATE:
			// 写log
			System::log_file_ << "Input: Winodw is created." << endl;
			break;

		case WM_LBUTTONDOWN:
			// 写log
			System::log_file_ << "Input: Mouse Left Botton Down." << endl;
			break;

		case WM_MOUSEMOVE:
			// 写log
			System::log_file_ << "Input: Mouse Move." << endl;
			break;

		// 重绘
		case WM_PAINT:
			dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			// 写log
			System::log_file_ << "Input: Paint." << endl;
			break;

		// 窗口关闭
		case WM_DESTROY:
			key_pressed_[KEY_ESC] = true;
			// 写log
			System::log_file_ << "Input: Forcing Shut Down." << endl;
			break;

		case WM_KEYDOWN:
			if (wParam == VK_RETURN) {
				key_pressed_[KEY_ENTER] = true;
				// 写log
				System::log_file_ << "Input: ENTER." << endl;
			}
			if (wParam == VK_SPACE) {
				key_pressed_[KEY_SPACE] = true;
				// 写log
				System::log_file_ << "Input: SPACE." << endl;
			}
			if (wParam == VK_ESCAPE) {
				key_pressed_[KEY_ESC] = true;
				// 写log
				System::log_file_ << "Input: ESC." << endl;
			}
			if (wParam == 'A') {
				key_pressed_[KEY_A] = true;
				// 写log
				System::log_file_ << "Input: A." << endl;
			}
			if (wParam == 'S') {
				key_pressed_[KEY_S] = true;
				// 写log
				System::log_file_ << "Input: S." << endl;
			}
			if (wParam == VK_UP) {
				key_pressed_[KEY_UP] = true;
				// 写log
				System::log_file_ << "Input: UP." << endl;
			}
			if (wParam == VK_DOWN) {
				key_pressed_[KEY_DOWN] = true;
				// 写log
				System::log_file_ << "Input: DOWN." << endl;
			}
			if (wParam == VK_LEFT) {
				key_pressed_[KEY_LEFT] = true;
				// 写log
				System::log_file_ << "Input: LEFT." << endl;
			}
			if (wParam == VK_RIGHT) {
				key_pressed_[KEY_RIGHT] = true;
				// 写log
				System::log_file_ << "Input: RIGHT." << endl;
			}
			break;

		// 窗口发生移动
		case WM_MOVE:
			// 写log
			System::log_file_ << "Input: Window Move." << endl;
			break;

		// 调用默认窗口过程
		default:
			// 写log
			System::log_file_ << "Input: Default." << endl;
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

void Input::Set() {
	for (int i = 0; i < NUM_OF_KEY; ++i)
		key_pressed_[i] = false;

	// 写log
	System::log_file_ << "Input: Set" << endl;
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
