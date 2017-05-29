/**
 * Project:      NewGame
 * File Name:    Level.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      关卡类实现文件
 */

#include "Level.h"
#include "Input.h"

void Level::Load() {
	// 先设置本状态哪些键位是有效的
	Input::GetPressedKey(KEY_SPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_BACKSPACE).SetIsValid(true);
	Input::GetPressedKey(KEY_ESC).SetIsValid(true);
	Input::GetPressedKey(KEY_A).SetIsValid(true);
	Input::GetPressedKey(KEY_S).SetIsValid(true);
	Input::GetPressedKey(KEY_UP).SetIsValid(true);
	Input::GetPressedKey(KEY_DOWN).SetIsValid(true);
	Input::GetPressedKey(KEY_LEFT).SetIsValid(true);
	Input::GetPressedKey(KEY_RIGHT).SetIsValid(true);

	handle.Load();
}

void Level::Initialize() {
	handle.Initialize();
}

void Level::Process() {
	while (!GetIsReadyForExit() && !GetIsReadyForRestart() && !GetIsReadyForNextGameState()) {
		AESysFrameStart();
		if (Input::GetPressedKey(KEY_ESC).GetIsPressed()) {
			SetIsReadyForExit();
			Input::GetPressedKey(KEY_ESC).SetIsPressed(false);
		}
		else if (Input::GetPressedKey(KEY_BACKSPACE).GetIsPressed()) {
			SetIsReadyForRestart();
			Input::GetPressedKey(KEY_BACKSPACE).SetIsPressed(false);
		}
		handle.Update();
		handle.Draw();
		if (handle.Check())
			SetIsReadyForNextGameState();
		AESysFrameEnd();
	}
}

void Level::Free() {
	handle.Free();
}

void Level::Unload() {
	handle.Unload();
	// 重置有效按键
	Input::ResetPressedKey();
}
