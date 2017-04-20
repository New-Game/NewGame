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

LRESULT CALLBACK Input::Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		// ���ڴ���
		case WM_CREATE:
			break;

		case WM_LBUTTONDOWN:
			break;

		case WM_MOUSEMOVE:
			break;

		// �ػ�
		case WM_PAINT: {
			PAINTSTRUCT ps; // �ػ�ṹ
			HDC dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		}

		// ���ڹر�
		case WM_DESTROY:
			DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_EXIT), hWnd, HandleForExit);
			break;

		case WM_KEYDOWN:
			if (wParam == VK_RETURN)
				pressed_key_[KEY_ENTER] = true;
			else if (wParam == VK_SPACE)
				pressed_key_[KEY_SPACE] = true;
			else if (wParam == VK_ESCAPE) {
				DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_EXIT), hWnd, HandleForExit);
				break;
			}
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
			if (LOWORD(wParam) == ID_RESTART)
				pressed_key_[KEY_BACKSPACE] = true;
			EndDialog(hDlg, LOWORD(wParam));
			return INT_PTR(true);

		default:
			return INT_PTR(false);
	}
}
