/**
 * Project:      NewGame
 * File Name:    Interval.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �����ʵ���ļ�
 */

#include "Interval.h"
#include "Input.h"

void Interval::Load() {
	// �����ñ�״̬��Щ��λ����Ч��
	Input::GetPressedKey(KEY_ENTER).SetIsValid(true);
	Input::GetPressedKey(KEY_ESC).SetIsValid(true);

	AEGfxMeshStart();
	AEGfxTriAdd(
		1000.0f, 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
		0.0f, 250.0f, 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		1000.0f, 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		1000.0f, 250.0f, 0xFFFF0000, 1.0f, 1.0f,
		0.0f, 250.0f, 0xFFFF0000, 0.0f, 1.0f);
	mesh_ = AEGfxMeshEnd();
	texture_ = AEGfxTextureLoad(picture_file_name_.c_str());
}

//void Interval::Initialize() {
	//AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	//AEGfxSetBlendMode(AE_GFX_BM_BLEND);  // ���û�ɫģʽ
//}

void Interval::Reset() {}

void Interval::Process() {
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

		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE); // ���û���ģʽ
		AEGfxSetPosition(0.0f, 0.0f); // ������Ե�����
		AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
		AEGfxTextureSet(texture_, 0.0f, 0.0f);
		//AEGfxSetTransparency(1.0f);
		//AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
		AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);

		AESysFrameEnd();
	}
}

void Interval::Unload() {
	AEGfxMeshFree(mesh_);
	// ������Ч����
	Input::ResetPressedKey();
}
