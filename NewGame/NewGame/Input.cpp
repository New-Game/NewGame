/**
 * Project:      NewGame
 * File Name:    Input.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ����ģ��ʵ���ļ�
 */

#include <iostream>
#include "Input.h"
#include "System.h"

LRESULT CALLBACK Input::Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC dc;           // �豸
	PAINTSTRUCT ps;   // �ػ�ṹ

	// дlog
	System::GetLogFile() << "Input: Handle." << std::endl;

	switch (msg) {
		// ���ڴ���
		case WM_CREATE:
			// дlog
			System::GetLogFile() << "Input: Winodw is created." << std::endl;
			break;

		case WM_LBUTTONDOWN:
			// дlog
			System::GetLogFile() << "Input: Mouse Left Botton Down." << std::endl;
			break;

		case WM_MOUSEMOVE:
			// дlog
			System::GetLogFile() << "Input: Mouse Move." << std::endl;
			break;

			// �ػ�
		case WM_PAINT:
			dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			// дlog
			System::GetLogFile() << "Input: Paint." << std::endl;
			break;

			// ���ڹر�
		case WM_DESTROY:
			pressed_key_[KEY_ESC] = true;
			// дlog
			System::GetLogFile() << "Input: Forcing Shut Down." << std::endl;
			break;

		case WM_KEYDOWN:
			if (wParam == VK_RETURN) {
				pressed_key_[KEY_ENTER] = true;
				// дlog
				System::GetLogFile() << "Input: ENTER." << std::endl;
			}
			if (wParam == VK_SPACE) {
				pressed_key_[KEY_SPACE] = true;
				// дlog
				System::GetLogFile() << "Input: SPACE." << std::endl;
			}
			if (wParam == VK_BACK) {
				pressed_key_[KEY_BACKSPACE] = true;
				// дlog
				System::GetLogFile() << "Input: BACKSPACE." << std::endl;
			}
			if (wParam == VK_ESCAPE) {
				pressed_key_[KEY_ESC] = true;
				// дlog
				System::GetLogFile() << "Input: ESC." << std::endl;
			}
			if (wParam == 'A') {
				pressed_key_[KEY_A] = true;
				// дlog
				System::GetLogFile() << "Input: A." << std::endl;
			}
			if (wParam == 'S') {
				pressed_key_[KEY_S] = true;
				// дlog
				System::GetLogFile() << "Input: S." << std::endl;
			}
			if (wParam == 'Y') {
				pressed_key_[KEY_Y] = true;
				// дlog
				System::GetLogFile() << "Input: Y." << std::endl;
			}
			if (wParam == 'N') {
				pressed_key_[KEY_N] = true;
				// дlog
				System::GetLogFile() << "Input: N." << std::endl;
			}
			if (wParam == VK_UP) {
				pressed_key_[KEY_UP] = true;
				// дlog
				System::GetLogFile() << "Input: UP." << std::endl;
			}
			if (wParam == VK_DOWN) {
				pressed_key_[KEY_DOWN] = true;
				// дlog
				System::GetLogFile() << "Input: DOWN." << std::endl;
			}
			if (wParam == VK_LEFT) {
				pressed_key_[KEY_LEFT] = true;
				// дlog
				System::GetLogFile() << "Input: LEFT." << std::endl;
			}
			if (wParam == VK_RIGHT) {
				pressed_key_[KEY_RIGHT] = true;
				// дlog
				System::GetLogFile() << "Input: RIGHT." << std::endl;
			}
			break;

		// ���ڷ����ƶ�
		case WM_MOVE:
			// дlog
			System::GetLogFile() << "Input: Window Move." << std::endl;
			break;

		// ����Ĭ�ϴ��ڹ���
		default:
			// дlog
			System::GetLogFile() << "Input: Default." << std::endl;
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}
