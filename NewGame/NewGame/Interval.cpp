/**
 * Project:      NewGame
 * File Name:    Interval.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �����ʵ���ļ�
 */

#include "Interval.h"
#include "Input.h"

void Interval::Process() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << name_ + ": Process." << endl;
	}
	while (!GetIsReadyForGameEnding() && !GetIsReadyForNextGameState()) {
		AESysFrameStart();
		if (Input::GetPressedKey(KEY_ESC)) {
			SetIsReadyForGameEnding();
			Input::ResetPressedKey();
		}
		else if (Input::GetPressedKey(KEY_ENTER)) {
			SetIsReadyForNextGameState();
			Input::ResetPressedKey();
		}
		AESysFrameEnd();
	}
}
