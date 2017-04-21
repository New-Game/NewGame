/**
 * Project:      NewGame
 * File Name:    CharacterPick.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      人物选择类实现文件
 */

#include "CharacterPick.h"
#include "Input.h"

void CharacterPick::Process() {
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
