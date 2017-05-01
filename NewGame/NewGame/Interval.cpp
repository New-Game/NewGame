/**
 * Project:      NewGame
 * File Name:    Interval.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      间隔类实现文件
 */

#include "Interval.h"
#include "Input.h"

void Interval::Load() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << name_ + ": Load." << endl;
	}
	AEGfxMeshStart();
	AEGfxTriAdd(
		300.0f, 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
		0.0f, 300.0f, 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		300.0f, 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		300.0f, 300.0f, 0xFFFF0000, 1.0f, 1.0f,
		0.0f, 300.0f, 0xFFFF0000, 0.0f, 1.0f);
	mesh_ = AEGfxMeshEnd();
	texture_ = AEGfxTextureLoad(picture_file_name_.c_str());
}

void Interval::Initialize() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << name_ + ": Initialize." << endl;
	}
	//AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);  // 设置混色模式
}

void Interval::Draw() {
	if (System::GetAESysInitInfo().mCreateConsole) {
			cout << name_ + ": Draw." << endl;
	}
	
}

void Interval::Process() {
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
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE); // 设置绘制模式
		AEGfxSetPosition(0.0f, 0.0f); // 设置相对点坐标
		AEGfxTextureSet(texture_, 0.0f, 0.0f);
		AEGfxSetTransparency(1.0f);
		AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
		AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
		AESysFrameEnd();
	}
}

void Interval::Free() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << name_ + ": Free." << endl;
	}
}

void Interval::Unload() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << name_ + ": Unload." << endl;
	}
	AEGfxMeshFree(mesh_);
}
