/**
* Project:      NewGame
* File Name:    Trap.cpp
* Author:       Long
* Date:         2017/6/05
* Purpose:      陷阱类实现文件
*/

#pragma once

#include "Trap.h"
#include "Level.h"
#include "System.h"

void Trap::Load() {
	AEGfxMeshStart();
	AEGfxTriAdd(
		float(rect_.GetSize()), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
		0.0f, float(rect_.GetSize()), 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		float(rect_.GetSize()), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		float(rect_.GetSize()), float(rect_.GetSize()), 0xFFFF0000, 1.0f, 1.0f,
		0.0f, float(rect_.GetSize()), 0xFFFF0000, 0.0f, 1.0f);
	mesh_ = AEGfxMeshEnd();
	texture_ = AEGfxTextureLoad(picture_.c_str());
	attack_texture_ = AEGfxTextureLoad(attack_picture_.c_str());
}

void Trap::Update() {
	++count_;
	if (count_ == System::GetFrameRate()) {
		count_ = 0;
		--period_;
	}
	if (period_ == 0) {
		if (status_)
			status_ = false;
		else
			status_ = true;
		period_ = 3;
	}
	//Active();
	//Inactive();
}

void Trap::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(float(rect_.GetX()), float(rect_.GetY()));
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	if (status_ == true)
		AEGfxTextureSet(attack_texture_, 0.0f, 0.0f);
	else
		AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Trap::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxTextureUnload(attack_texture_);
	AEGfxMeshFree(mesh_);
}


/*void Trap::Active() {
	++count_;
	if (type_ == KILL) {
		if (count_ % 600 == 10)
			state_ = true;
	}
	if (type_ == SLOW) {
		if (count_ % 600 == 20)
			state_ = true;
	}
	if (type_ == BACK) {
		if (count_ % 600 == 30)
			state_ = true;
	}
	if (type_ == WEAK) {
		if (count_ % 600 == 40)
			state_ = true;
	}
	if (count_>3600)
		count_ = 0;
}

void Trap::Inactive() {
	if (type_ == KILL) {
		if (count_ % 1200 == 10)
			state_ = false;
	}
	if (type_ == SLOW) {
		if (count_ % 1200 == 20)
			state_ = false;
	}
	if (type_ == BACK) {
		if (count_ % 1200 == 30)
			state_ = false;
	}
	if (type_ == WEAK) {
		if (count_ % 1200 == 40)
			state_ = false;
	}
}*/

void Trap::TakeEffect(Character* p_character) {
	
}
