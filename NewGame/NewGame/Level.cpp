/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ʵ���ļ�
 */

#include "Level.h"
#include "Input.h"

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
		else if (Input::GetPressedKey(KEY_BACKSPACE)) {
			SetIsReadyForRestart();
			Input::ResetPressedKey();
		}
		AESysFrameEnd();
	}
}