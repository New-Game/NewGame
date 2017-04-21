/**
 * Project:      NewGame
 * File Name:    CharacterPick.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      ����ѡ����ʵ���ļ�
 */

#include "CharacterPick.h"
#include "Input.h"

void CharacterPick::Process() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << name_ + ": Process." << endl;
	}
	while (!GetIsReadyForExit() && !GetIsReadyForNextGameState()) {
		AESysFrameStart();
		if (Input::GetPressedKey(KEY_ESC)) {
			SetIsReadyForExit();
			Input::ResetPressedKey();
		}
		else if (Input::GetPressedKey(KEY_ENTER)) {
			SetIsReadyForNextGameState();
			Input::ResetPressedKey();
		}
		AESysFrameEnd();
	}
}
