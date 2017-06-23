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
#include "resource.h"
#include <winuser.h>

LRESULT CALLBACK Input::MainHandle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		// ���ڴ������Ѵ��ڷ��������룩
		case WM_CREATE: {
			RECT rect;
			// �����Ļ�ߴ�
			auto screen_width = GetSystemMetrics(SM_CXSCREEN);
			auto screen_height = GetSystemMetrics(SM_CYSCREEN);
			// ��ȡ����ߴ�
			GetWindowRect(hWnd, &rect);
			rect.left = (screen_width - rect.right) / 2;
			rect.top = (screen_height - rect.bottom) / 2;
			// ���ô���λ��
			SetWindowPos(hWnd, HWND_TOPMOST, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);
			break;
		}
		
		case WM_LBUTTONDOWN: {
			if (pressed_key_[KEY_MOUSE].GetIsValid())
				pressed_key_[KEY_MOUSE].SetIsPressed(true);
			break;
		}

		case WM_MOUSEMOVE:{
			GetCursorPos(&pos_mouse_);
			ScreenToClient(hWnd, &pos_mouse_);
			break;
		}
		// �����ػ�
		case WM_PAINT: {
			PAINTSTRUCT ps; // �ػ�ṹ
			HDC dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		}

		// ���ڹر�
		case WM_DESTROY:
			pressed_key_[KEY_ESC].SetIsValid(true);
			pressed_key_[KEY_ESC].SetIsPressed(true);
			break;

		// �����˼����ϵ�һ����
		case WM_KEYDOWN:
			if (wParam == VK_RETURN) {
				if (pressed_key_[KEY_ENTER].GetIsValid())
					pressed_key_[KEY_ENTER].SetIsPressed(true);
			}
			else if (wParam == VK_SPACE) {
				if (pressed_key_[KEY_SPACE].GetIsValid())
					DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_RESUME), hWnd, HandleForResume);
			}
			else if (wParam == VK_BACK) {
				if (pressed_key_[KEY_BACKSPACE].GetIsValid())
					DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_RESTART), hWnd, HandleForRestart);
			}
			else if (wParam == VK_ESCAPE) {
				if (pressed_key_[KEY_ESC].GetIsValid())
					DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_EXIT), hWnd, HandleForExit);
			}
			/*else {
				if (wParam == 'A') {
					if (pressed_key_[KEY_A].GetIsValid())
						pressed_key_[KEY_A].SetIsPressed(true);
				}
				else if (wParam == 'S') {
					if (pressed_key_[KEY_S].GetIsValid())
						pressed_key_[KEY_S].SetIsPressed(true);
				}
				if (wParam == VK_UP) {
					if (pressed_key_[KEY_UP].GetIsValid())
						pressed_key_[KEY_UP].SetIsPressed(true);
				}
				else if (wParam == VK_DOWN) {
					if (pressed_key_[KEY_DOWN].GetIsValid())
						pressed_key_[KEY_DOWN].SetIsPressed(true);
				}
				else if (wParam == VK_LEFT) {
					if (pressed_key_[KEY_LEFT].GetIsValid())
						pressed_key_[KEY_LEFT].SetIsPressed(true);
				}
				else if (wParam == VK_RIGHT) {
					if (pressed_key_[KEY_RIGHT].GetIsValid())
						pressed_key_[KEY_RIGHT].SetIsPressed(true);
				}
			}*/
			break;

		// ���ڷ����ƶ�
		case WM_MOVE:
			InvalidateRect(hWnd, nullptr, false);
			break;

		// ����Ĭ�ϴ��ڹ���
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
				pressed_key_[KEY_ESC].SetIsPressed(true);
			EndDialog(hDlg, LOWORD(wParam));
			return INT_PTR(true);
			
		default:
			return INT_PTR(false);
	}
}

INT_PTR CALLBACK Input::HandleForResume(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (msg) {
		case WM_INITDIALOG:
			return INT_PTR(true);

		case WM_COMMAND:
			if (LOWORD(wParam) == IDNO)
				pressed_key_[KEY_ESC].SetIsPressed(true);
			EndDialog(hDlg, LOWORD(wParam));
			return INT_PTR(true);

		default:
			return INT_PTR(false);
	}
}

INT_PTR CALLBACK Input::HandleForRestart(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch(msg) {
		case WM_INITDIALOG:
			return INT_PTR(true);

		case WM_COMMAND:
			if (LOWORD(wParam) == IDYES)
				pressed_key_[KEY_BACKSPACE].SetIsPressed(true);
			EndDialog(hDlg, LOWORD(wParam));
			return INT_PTR(true);

		default:
			return INT_PTR(false);
	}
}

INT_PTR CALLBACK Input::HandleForGameOver(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch(msg) {
		case WM_INITDIALOG:
			return INT_PTR(true);
		case WM_COMMAND:
			if (LOWORD(wParam) == IDRESTART) {
				pressed_key_[KEY_BACKSPACE].SetIsPressed(true);
				EndDialog(hDlg, LOWORD(wParam));
				return INT_PTR(true);
			}
			if (LOWORD(wParam) == IDEXIT) {
				pressed_key_[KEY_ESC].SetIsPressed(true);
				EndDialog(hDlg, LOWORD(wParam));
				return INT_PTR(true);
			}
		default:
			return INT_PTR(false);
	}
}

INT_PTR CALLBACK Input::HandleForInfo(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (msg) {
		case WM_INITDIALOG:
			return INT_PTR(true);
		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK) {
				EndDialog(hDlg, LOWORD(wParam));
				return INT_PTR(true);
			}
		default:
			return INT_PTR(false);
	}
}
