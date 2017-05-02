/**
 * Project:      NewGame
 * File Name:    CharacterPick.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      人物选择类实现文件
 */

#include "CharacterPick.h"
#include "Input.h"

void CharacterPick::Load() {}

void CharacterPick::Initialize() {}

void CharacterPick::Process() {
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

void CharacterPick::Free() {}

void CharacterPick::Unload() {}

void CharacterPick::Draw() {}
