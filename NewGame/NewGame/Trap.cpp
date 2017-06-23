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
	/*AEGfxTriAdd(
		float(rect_.GetSize()), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
		0.0f, float(rect_.GetSize()), 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		float(rect_.GetSize()), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		float(rect_.GetSize()), float(rect_.GetSize()), 0xFFFF0000, 1.0f, 1.0f,
		0.0f, float(rect_.GetSize()), 0xFFFF0000, 0.0f, 1.0f);*/
	AEGfxTriAdd(
		float(rect_.GetSize()), 0.0f, 0x00FF00FF, 0.0f, 0.0f,
		0.0f, 0.0f, 0x00FFFF00, 0.125f, 0.0f,
		0.0f, float(rect_.GetSize()), 0x00F00FFF, 0.125f, 1.0f);
	AEGfxTriAdd(
		float(rect_.GetSize()), 0.0f, 0xFFFF0000, 0.125f, 0.0f,
		float(rect_.GetSize()), float(rect_.GetSize()), 0xFFFF0000, 0.125f, 1.0f,
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
		if (target_character_ != nullptr)
			--lasting_time_;
	}
	if (period_ == 0) {
		if (status_)
			status_ = false;
		else
			status_ = true;
		period_ = 3;
	}
	if (lasting_time_ == 0) {
		LoseEffect();
		lasting_time_ = 3;
		target_character_ = nullptr;
	}
}

void Trap::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(float(rect_.GetX()), float(rect_.GetY()));
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	if (status_ == true) {
		//AEGfxTextureSet(attack_texture_, 0.0f, 0.0f);
		// Set texture for object 2
		if (AnimationCurFrame < AnimationController)
		{
			AEGfxTextureSet(attack_texture_, AnimationCurFrame*0.125f, 0.0f);
			AnimationCurFrame += 1;
		}
		else
		{
			AEGfxTextureSet(attack_texture_, 0.0f, 0.0f); // 参数1：纹理，偏移量(x,y)
			AnimationCurFrame = 1;
		}
	}
	else
		AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Trap::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxTextureUnload(attack_texture_);
	AEGfxMeshFree(mesh_);
}

void Trap::TakeEffect() {
	switch(type_) {
		case STUN:
			target_character_->SetStun(true);
			break;
		case WEAK:
			target_character_->SetWeak(true);
			break;
		default:
			break;
	}
}

void Trap::LoseEffect() {
	switch(type_) {
		case STUN:
			target_character_->SetStun(false);
			break;
		case WEAK:
			target_character_->SetWeak(false);
			break;
		default:
			break;
	}
}
