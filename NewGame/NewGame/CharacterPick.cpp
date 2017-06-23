/**
 * Project:      NewGame
 * File Name:    CharacterPick.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      人物选择类实现文件
 */

#include "CharacterPick.h"
#include "Input.h"
#include "Emilia.h"
#include "Felt.h"
#include "Fillis.h"
#include "Ram.h"
#include "Rem.h"

void CharacterPick::Load() {
	// 先设置本状态哪些键位是有效的
	Input::GetPressedKey(KEY_ESC).SetIsValid(true);
	Input::GetPressedKey(KEY_MOUSE).SetIsValid(true);
	for (int i = 0; i < NUM_OF_CHARACTERS; ++i) {
		AEGfxMeshStart();
		AEGfxTriAdd(
			164.0f, 0.0f, 0xFFFF0000, 1.0f, 0.0f,
			0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
			0.0f, 360.0f, 0xFFFF0000, 0.0f, 1.0f);
		AEGfxTriAdd(
			164.0f, 0.0f, 0xFFFF0000, 1.0f, 0.0f,
			164.0f, 360.0f, 0xFFFF0000, 1.0f, 1.0f,
			0.0f, 360.0f, 0xFFFF0000, 0.0f, 1.0f);
		mesh_[i] = AEGfxMeshEnd();
		texture_[i] = AEGfxTextureLoad(picture_[i].c_str());
	}
}

void CharacterPick::Reset() {}

void CharacterPick::Process() {
	while (!GetIsReadyForExit() && !GetIsReadyForNextGameState()) {
		AESysFrameStart();

		if (Input::GetPressedKey(KEY_ESC).GetIsPressed()) {
			SetIsReadyForExit();
			Input::GetPressedKey(KEY_ESC).SetIsPressed(false);
			continue;
		}

		for (int i = 0; i < NUM_OF_CHARACTERS; ++i) {
			AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
			AEGfxSetPosition(float((i + 1) * 30 + i * 164), 0.0f);
			AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
			AEGfxTextureSet(texture_[i], 0.0f, 0.0f);
			AEGfxMeshDraw(mesh_[i], AE_GFX_MDM_TRIANGLES);
		}


		if (Input::GetPressedKey(KEY_MOUSE).GetIsPressed()) {
			if (Input::GetMousePos().x >= 30 && Input::GetMousePos().x <= 194)
				picked_character_ = new Emilia();
			else if (Input::GetMousePos().x >= 224 && Input::GetMousePos().x <= 388)
				picked_character_ = new Rem();
			else if (Input::GetMousePos().x >= 418 && Input::GetMousePos().x <= 582)
				picked_character_ = new Ram();
			else if (Input::GetMousePos().x >= 612 && Input::GetMousePos().x <= 776)
				picked_character_ = new Fillis();
			else if (Input::GetMousePos().x >= 806 && Input::GetMousePos().x <= 970)
				picked_character_ = new Felt();
			SetIsReadyForNextGameState();
			Input::GetPressedKey(KEY_MOUSE).SetIsPressed(false);
			continue;
		}

		AESysFrameEnd();
	}
}

void CharacterPick::Unload() {
	for (int i = 0; i < NUM_OF_CHARACTERS; ++i) {
		AEGfxTextureUnload(texture_[i]);
		AEGfxMeshFree(mesh_[i]);
	}
	// 重置有效按键
	Input::ResetPressedKey();
}
