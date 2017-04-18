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
	System::GetLogFile() << "Input: Handle." << endl;

	switch (msg) {
		// ���ڴ���
		case WM_CREATE:
			// дlog
			System::GetLogFile() << "Input: Winodw is created." << endl;
			break;

		case WM_LBUTTONDOWN:
			// дlog
			System::GetLogFile() << "Input: Mouse Left Botton Down." << endl;
			break;

		case WM_MOUSEMOVE:
			// дlog
			System::GetLogFile() << "Input: Mouse Move." << endl;
			break;

		// �ػ�
		case WM_PAINT:
			dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			// дlog
			System::GetLogFile() << "Input: Paint." << endl;
			break;

		// ���ڹر�
		case WM_DESTROY:
			pressed_key_[KEY_ESC] = true;
			// дlog
			System::GetLogFile() << "Input: Forcing Shut Down." << endl;
			break;

		case WM_KEYDOWN:
			if (wParam == VK_RETURN) {
				pressed_key_[KEY_ENTER] = true;
				// дlog
				System::GetLogFile() << "Input: ENTER." << endl;
			}
			if (wParam == VK_SPACE) {
				pressed_key_[KEY_SPACE] = true;
				// дlog
				System::GetLogFile() << "Input: SPACE." << endl;
			}
			if (wParam == VK_ESCAPE) {
				pressed_key_[KEY_ESC] = true;
				// дlog
				System::GetLogFile() << "Input: ESC." << endl;
			}
			if (wParam == 'A') {
				pressed_key_[KEY_A] = true;
				// дlog
				System::GetLogFile() << "Input: A." << endl;
			}
			if (wParam == 'S') {
				pressed_key_[KEY_S] = true;
				// дlog
				System::GetLogFile() << "Input: S." << endl;
			}
			if (wParam == VK_UP) {
				pressed_key_[KEY_UP] = true;
				// дlog
				System::GetLogFile() << "Input: UP." << endl;
			}
			if (wParam == VK_DOWN) {
				pressed_key_[KEY_DOWN] = true;
				// дlog
				System::GetLogFile() << "Input: DOWN." << endl;
			}
			if (wParam == VK_LEFT) {
				pressed_key_[KEY_LEFT] = true;
				// дlog
				System::GetLogFile() << "Input: LEFT." << endl;
			}
			if (wParam == VK_RIGHT) {
				pressed_key_[KEY_RIGHT] = true;
				// дlog
				System::GetLogFile() << "Input: RIGHT." << endl;
			}
			break;

		// ���ڷ����ƶ�
		case WM_MOVE:
			// дlog
			System::GetLogFile() << "Input: Window Move." << endl;
			break;

		// ����Ĭ�ϴ��ڹ���
		default:
			// дlog
			System::GetLogFile() << "Input: Default." << endl;
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

void Input::SetPressedKey() {
	for (int i = 0; i < NUM_OF_KEY; ++i)
		pressed_key_[i] = false;

	// дlog
	System::GetLogFile() << "Input: Set" << endl;
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
