/**
 * Project:      NewGame
 * File Name:    Input.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      输入模块实现文件
 */

#include <iostream>
#include "Input.h"
#include "System.h"

LRESULT CALLBACK Input::Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC dc;           // 设备
	PAINTSTRUCT ps;   // 重绘结构

	// 写log
	System::GetLogFile() << "Input: Handle." << std::endl;

	switch (msg) {
		// 窗口创建
		case WM_CREATE:
			// 写log
			System::GetLogFile() << "Input: Winodw is created." << std::endl;
			break;

		case WM_LBUTTONDOWN:
			// 写log
			System::GetLogFile() << "Input: Mouse Left Botton Down." << std::endl;
			break;

		case WM_MOUSEMOVE:
			// 写log
			System::GetLogFile() << "Input: Mouse Move." << std::endl;
			break;

			// 重绘
		case WM_PAINT:
			dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			// 写log
			System::GetLogFile() << "Input: Paint." << std::endl;
			break;

			// 窗口关闭
		case WM_DESTROY:
			pressed_key_[KEY_ESC] = true;
			// 写log
			System::GetLogFile() << "Input: Forcing Shut Down." << std::endl;
			break;

		case WM_KEYDOWN:
			if (wParam == VK_RETURN) {
				pressed_key_[KEY_ENTER] = true;
				// 写log
				System::GetLogFile() << "Input: ENTER." << std::endl;
			}
			if (wParam == VK_SPACE) {
				pressed_key_[KEY_SPACE] = true;
				// 写log
				System::GetLogFile() << "Input: SPACE." << std::endl;
			}
			if (wParam == VK_BACK) {
				pressed_key_[KEY_BACKSPACE] = true;
				// 写log
				System::GetLogFile() << "Input: BACKSPACE." << std::endl;
			}
			if (wParam == VK_ESCAPE) {
				pressed_key_[KEY_ESC] = true;
				// 写log
				System::GetLogFile() << "Input: ESC." << std::endl;
			}
			if (wParam == 'A') {
				pressed_key_[KEY_A] = true;
				// 写log
				System::GetLogFile() << "Input: A." << std::endl;
			}
			if (wParam == 'S') {
				pressed_key_[KEY_S] = true;
				// 写log
				System::GetLogFile() << "Input: S." << std::endl;
			}
			if (wParam == 'Y') {
				pressed_key_[KEY_Y] = true;
				// 写log
				System::GetLogFile() << "Input: Y." << std::endl;
			}
			if (wParam == 'N') {
				pressed_key_[KEY_N] = true;
				// 写log
				System::GetLogFile() << "Input: N." << std::endl;
			}
			if (wParam == VK_UP) {
				pressed_key_[KEY_UP] = true;
				// 写log
				System::GetLogFile() << "Input: UP." << std::endl;
			}
			if (wParam == VK_DOWN) {
				pressed_key_[KEY_DOWN] = true;
				// 写log
				System::GetLogFile() << "Input: DOWN." << std::endl;
			}
			if (wParam == VK_LEFT) {
				pressed_key_[KEY_LEFT] = true;
				// 写log
				System::GetLogFile() << "Input: LEFT." << std::endl;
			}
			if (wParam == VK_RIGHT) {
				pressed_key_[KEY_RIGHT] = true;
				// 写log
				System::GetLogFile() << "Input: RIGHT." << std::endl;
			}
			break;

		// 窗口发生移动
		case WM_MOVE:
			// 写log
			System::GetLogFile() << "Input: Window Move." << std::endl;
			break;

		// 调用默认窗口过程
		default:
			// 写log
			System::GetLogFile() << "Input: Default." << std::endl;
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}
