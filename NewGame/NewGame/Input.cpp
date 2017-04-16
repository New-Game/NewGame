/* Project:      NewGame
 * File Name:    Input.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      输入模块实现文件
 */

#include "Input.h"

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
LRESULT CALLBACK InputHandle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC dc;           // 设备
	PAINTSTRUCT ps;   // 重绘结构

					  // 签到
					  //fprintf(fp,"Input:Handle\n");

	switch (msg) {
		// 窗口创建
		case WM_CREATE:
			break;

		case WM_LBUTTONDOWN:
			//GS_Running = 0;
			break;

		case WM_MOUSEMOVE:
			break;

		// 重绘
		case WM_PAINT:
			dc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;

		// 窗口关闭
		case WM_DESTROY:
			key_pressed[KEY_ESC] = true;
			//fprintf(fp, "Input:Forcing Shut Down\n");
			break;

		case WM_KEYDOWN:
			if (wParam == VK_RETURN) {
				key_pressed[KEY_ENTER] = true;
				//...
			}
			if (wParam == VK_SPACE) {
				key_pressed[KEY_SPACE] = true;
				//...
			}
			if (wParam == VK_ESCAPE) {
				key_pressed[KEY_ESC] = true;
				//fprintf(fp, "Input:ESC\n");
			}
			if (wParam == 'A') {
				key_pressed[KEY_A] = true;
				//fprintf(fp, "Input:A\n");
			}
			if (wParam == 'S') {
				key_pressed[KEY_S] = true;
				//fprintf(fp, "Input:S\n");
			}
			if (wParam == VK_UP)
				key_pressed[KEY_UP] = true;
			if (wParam == VK_DOWN)
				key_pressed[KEY_DOWN] = true;
			if (wParam == VK_LEFT)
				key_pressed[KEY_LEFT] = true;
			if (wParam == VK_RIGHT)
				key_pressed[KEY_RIGHT] = true;
			break;

		// 窗口发生移动
		case WM_MOVE:
			break;

		// 调用默认窗口过程
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

void SetInput() {
	for (int i = 0; i < KEY_NUM; ++i)
		key_pressed[i] = false;
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Memeber Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
