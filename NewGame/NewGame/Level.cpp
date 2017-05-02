/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      关卡类实现文件
 */

#include "Level.h"
#include "Input.h"

void Level::Load() {}

void Level::Initialize() {}

void Level::Process() {
	while (!GetIsReadyForExit() && !GetIsReadyForRestart()) {
		AESysFrameStart();
		if (Input::GetPressedKey(KEY_ESC)) {
			SetIsReadyForExit();
			Input::ResetPressedKey();
		}
		else if (Input::GetPressedKey(KEY_BACKSPACE)) {
			SetIsReadyForRestart();
			Input::ResetPressedKey();
		}
		AESysFrameEnd();
	}
}

void Level::Free() {}

void Level::Unload() {}

void Level::Draw() {}
