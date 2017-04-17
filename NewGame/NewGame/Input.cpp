/* Project:      NewGame
 * File Name:    Input.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ����ģ��ʵ���ļ�
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
	HDC dc;           // �豸
	PAINTSTRUCT ps;   // �ػ�ṹ

	// дlog
	System::out_file_log << "Input: Handle." << endl;

	switch (msg) {
		// ���ڴ���
		case WM_CREATE:
			break;

		case WM_LBUTTONDOWN:
			//GS_Running = 0;
			break;

		case WM_MOUSEMOVE:
			break;

		// �ػ�
		case WM_PAINT:
			dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;

		// ���ڹر�
		case WM_DESTROY:
			key_pressed[KEY_ESC] = true;
			// дlog
			System::out_file_log << "Input: Forcing Shut Down." << endl;
			break;

		case WM_KEYDOWN:
			if (wParam == VK_RETURN) {
				key_pressed[KEY_ENTER] = true;
				// дlog
				System::out_file_log << "Input: ENTER." << endl;
			}
			if (wParam == VK_SPACE) {
				key_pressed[KEY_SPACE] = true;
				// дlog
				System::out_file_log << "Input: SPACE." << endl;
			}
			if (wParam == VK_ESCAPE) {
				key_pressed[KEY_ESC] = true;
				// дlog
				System::out_file_log << "Input: ESC." << endl;
			}
			if (wParam == 'A') {
				key_pressed[KEY_A] = true;
				// дlog
				System::out_file_log << "Input: A" << endl;
			}
			if (wParam == 'S') {
				key_pressed[KEY_S] = true;
				// дlog
				System::out_file_log << "Input: S" << endl;
			}
			if (wParam == VK_UP) {
				key_pressed[KEY_UP] = true;
				// дlog
				System::out_file_log << "Input: UP" << endl;
			}
			if (wParam == VK_DOWN) {
				key_pressed[KEY_DOWN] = true;
				// дlog
				System::out_file_log << "Input: DOWN" << endl;
			}
			if (wParam == VK_LEFT) {
				key_pressed[KEY_LEFT] = true;
				// дlog
				System::out_file_log << "Input: LEFT" << endl;
			}
			if (wParam == VK_RIGHT) {
				key_pressed[KEY_RIGHT] = true;
				// дlog
				System::out_file_log << "Input: RIGHT" << endl;
			}
			break;

		// ���ڷ����ƶ�
		case WM_MOVE:
			break;

		// ����Ĭ�ϴ��ڹ���
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

void Input::Set() {
	for (int i = 0; i < KEY_NUM; ++i)
		key_pressed[i] = false;
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
