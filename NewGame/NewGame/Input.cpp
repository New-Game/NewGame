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
#include "resource.h"
#include <winuser.h>

LRESULT CALLBACK Input::MainHandle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		// 窗口创建（把窗口放在正中央）
		case WM_CREATE: {
			RECT rect;
			// 获得屏幕尺寸
			auto screen_width = GetSystemMetrics(SM_CXSCREEN);
			auto screen_height = GetSystemMetrics(SM_CYSCREEN);
			// 获取窗体尺寸
			GetWindowRect(hWnd, &rect);
			rect.left = (screen_width - rect.right) / 2;
			rect.top = (screen_height - rect.bottom) / 2;
			// 设置窗体位置
			SetWindowPos(hWnd, HWND_TOPMOST, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);
			break;
		}

		// 按下了鼠标左键
		case WM_LBUTTONDOWN:
			break;

		// 鼠标移动了
		case WM_MOUSEMOVE:
			break;

		// 窗口重绘
		case WM_PAINT: {
			PAINTSTRUCT ps; // 重绘结构
			HDC dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		}

		// 窗口关闭
		case WM_DESTROY:
			pressed_key_[KEY_ESC] = true;
			break;

		// 按下了键盘上的一个键
		case WM_KEYDOWN:
			if (wParam == VK_RETURN)
				pressed_key_[KEY_ENTER] = true;
			else if (wParam == VK_SPACE)
				DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_RESUME), hWnd, HandleForResume);
			else if (wParam == VK_BACK)
				DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_RESTART), hWnd, HandleForRestart);
			else if (wParam == VK_ESCAPE)
				DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_EXIT), hWnd, HandleForExit);
			else {
				if (wParam == 'A')
					pressed_key_[KEY_A] = true;
				if (wParam == 'S')
					pressed_key_[KEY_S] = true;
				if (wParam == VK_UP)
					pressed_key_[KEY_UP] = true;
				if (wParam == VK_DOWN)
					pressed_key_[KEY_DOWN] = true;
				if (wParam == VK_LEFT)
					pressed_key_[KEY_LEFT] = true;
				if (wParam == VK_RIGHT)
					pressed_key_[KEY_RIGHT] = true;
			}
			break;

		// 窗口发生移动
		case WM_MOVE:
			InvalidateRect(hWnd, nullptr, false);
			break;

		// 调用默认窗口过程
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

INT_PTR CALLBACK Input::HandleForExit(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch(msg) {
		case WM_INITDIALOG:
			return INT_PTR(true);

		case WM_COMMAND:
			if (LOWORD(wParam) == IDYES)
				pressed_key_[KEY_ESC] = true;
			EndDialog(hDlg, LOWORD(wParam));
			return INT_PTR(true);
			
		default:
			return INT_PTR(false);
	}
}

INT_PTR Input::HandleForResume(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (msg) {
		case WM_INITDIALOG:
			return INT_PTR(true);

		case WM_COMMAND:
			if (LOWORD(wParam) == IDNO)
				pressed_key_[KEY_ESC] = true;
			EndDialog(hDlg, LOWORD(wParam));
			return INT_PTR(true);

		default:
			return INT_PTR(false);
	}
}

INT_PTR Input::HandleForRestart(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch(msg) {
		case WM_INITDIALOG:
			return INT_PTR(true);

		case WM_COMMAND:
			if (LOWORD(wParam) == IDYES)
				pressed_key_[KEY_BACKSPACE] = true;
			EndDialog(hDlg, LOWORD(wParam));
			return INT_PTR(true);

		default:
			return INT_PTR(false);
	}
}

