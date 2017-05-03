/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ʵ���ļ�
 */

#include "Level.h"
#include "Input.h"

void Level::Load() {
	handle.Load();
}

void Level::Initialize() {
	handle.Initialize();
}

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
		handle.Update();
		handle.Draw();
		AESysFrameEnd();
	}
}

void Level::Free() {
	handle.Free();
}

void Level::Unload() {
	handle.Unload();
}
