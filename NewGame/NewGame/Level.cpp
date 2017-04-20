/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ʵ���ļ�
 */

#include <Windows.h>
#include "Level.h"
#include "Input.h"
#include "resource.h"

void Level::Process() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Level: Process." << endl;
	}
	while (!GetIsReadyForGameEnding() && !GetIsReadyForRestart()) {
		AESysFrameStart();
		if (Input::GetPressedKey(KEY_ESC)) {
			SetIsReadyForGameEnding();
			Input::ResetPressedKey();
		}
		else if (Input::GetPressedKey(KEY_SPACE)) {
			HWND hWnd = FindWindow("NewGame", "���㿪ʼ���Թ�����ս");
			DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_RESUME), hWnd,
				      Input::HandleForResume);
			Input::ResetPressedKey();
		}
		if (Input::GetPressedKey(KEY_BACKSPACE)) {
			SetIsReadyForRestart();
			Input::ResetPressedKey();
		}
		AESysFrameEnd();
	}
}