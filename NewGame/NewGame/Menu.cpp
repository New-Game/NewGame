/**
 * Project:      NewGame
 * File Name:    Start.cpp
 * Author:       ChenKun
 * Date:         2017/6/11
 * Purpose:      开始菜单类实现文件
 */

#include "Menu.h"
#include "Input.h"
#include "music.h"
#include "resource.h"

void Menu::Load() {
	// 先设置本状态哪些键位是有效的
	Input::GetPressedKey(KEY_ENTER).SetIsValid(true);
	Input::GetPressedKey(KEY_ESC).SetIsValid(true);
	Input::GetPressedKey(KEY_MOUSE).SetIsValid(true);

	mciopen.lpstrDeviceType = "mpegvideo";
	mciopen.lpstrElementName = "music\\Redo";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciopen);
	device = mciopen.wDeviceID;
	mciSendCommand(device, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)&mciplay);

	AEGfxMeshStart();
	AEGfxTriAdd(
		1000.0f, 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
		0.0f, 600.0f, 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		1000.0f, 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		1000.0f, 600.0f, 0xFFFF0000, 1.0f, 1.0f,
		0.0f, 600.0f, 0xFFFF0000, 0.0f, 1.0f);
	mesh_ = AEGfxMeshEnd();
	texture_ = AEGfxTextureLoad(picture_file_name_.c_str());
}

void Menu::Reset() {}

void Menu::Process() {
	while (!GetIsReadyForExit() && !GetIsReadyForNextGameState()) {
		AESysFrameStart();
		if (Input::GetPressedKey(KEY_ESC).GetIsPressed()) {
			SetIsReadyForExit();
			Input::GetPressedKey(KEY_ESC).SetIsPressed(false);
		}
		else if (Input::GetPressedKey(KEY_ENTER).GetIsPressed()) {
			SetIsReadyForNextGameState();
			Input::GetPressedKey(KEY_ENTER).SetIsPressed(false);
		}

		// 退出游戏
		else if (Input::GetMousePos().x > 10 && Input::GetMousePos().x < 220
			&& Input::GetMousePos().y > 440 && Input::GetMousePos().y < 530) {
			if (Input::GetPressedKey(KEY_MOUSE).GetIsPressed()) {
				SetIsReadyForExit();
				Input::GetPressedKey(KEY_MOUSE).SetIsPressed(false);
			}
		}

		// 操作说明
		else if (Input::GetMousePos().x > 160 && Input::GetMousePos().x < 360
			&& Input::GetMousePos().y > 300 && Input::GetMousePos().y < 400) {
			if (Input::GetPressedKey(KEY_MOUSE).GetIsPressed()) {
				DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_OPERATION), System::GetHandle(), Input::HandleForInfo);
				Input::GetPressedKey(KEY_MOUSE).SetIsPressed(false);
			}
		}

		// 地图元素
		else if ((pow(Input::GetMousePos().x - 300, 2) +
			pow(Input::GetMousePos().y - 500, 2)) < 70*70) {
			if (Input::GetPressedKey(KEY_MOUSE).GetIsPressed()) {
				DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_MAP_ELEMENT), System::GetHandle(), Input::HandleForInfo);
				Input::GetPressedKey(KEY_MOUSE).SetIsPressed(false);
			}
		}

		// 资源说明
		else if (Input::GetMousePos().x > 380 && Input::GetMousePos().x <= 580
			&& Input::GetMousePos().y > 490 && Input::GetMousePos().y < 590) {
			if (Input::GetPressedKey(KEY_MOUSE).GetIsPressed()) {
				DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_RESOURCE), System::GetHandle(), Input::HandleForInfo);
				Input::GetPressedKey(KEY_MOUSE).SetIsPressed(false);
			}
		}

		// 开始游戏
		else if (Input::GetMousePos().x > 540 && Input::GetMousePos().x < 750
			&& Input::GetMousePos().y > 350 && Input::GetMousePos().y < 440) {
			if (Input::GetPressedKey(KEY_MOUSE).GetIsPressed()) {
				SetIsReadyForNextGameState();
				Input::GetPressedKey(KEY_MOUSE).SetIsPressed(false);
			}
		}

		// 关于我们
		else if (Input::GetMousePos().x > 770 && Input::GetMousePos().x < 980
			&& Input::GetMousePos().y > 430 && Input::GetMousePos().y < 520) {
			if (Input::GetPressedKey(KEY_MOUSE).GetIsPressed()) {
				DialogBox(System::GetHInstance(), MAKEINTRESOURCE(IDD_DIALOG_FOR_ABOUT), System::GetHandle(), Input::HandleForInfo);
				Input::GetPressedKey(KEY_MOUSE).SetIsPressed(false);
			}
		}
		
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetPosition(0.0f, 0.0f);
		AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
		AEGfxTextureSet(texture_, 0.0f, 0.0f);
		AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);

		AESysFrameEnd();
	}
}

void Menu::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
	// 重置有效按键
	Input::ResetPressedKey();
}