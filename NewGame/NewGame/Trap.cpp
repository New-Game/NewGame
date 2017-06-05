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

void Trap::Load() {
	AEGfxMeshStart();
	AEGfxTriAdd(
		float(rect_.GetX() + rect_.GetSize()), float(rect_.GetY()), 0xFFFF0000, 1.0f, 0.0f,
		float(rect_.GetX()), float(rect_.GetY()), 0xFFFF0000, 0.0f, 0.0f,
		float(rect_.GetX()), float(rect_.GetY() + rect_.GetSize()), 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		float(rect_.GetX() + rect_.GetSize()), float(rect_.GetY()), 0xFFFF0000, 1.0f, 0.0f,
		float(rect_.GetX() + rect_.GetSize()), float(rect_.GetY() + rect_.GetSize()), 0xFFFF0000, 1.0f, 1.0f,
		float(rect_.GetX()), float(rect_.GetY() + rect_.GetSize()), 0xFFFF0000, 0.0f, 1.0f);
	mesh_ = AEGfxMeshEnd();
	texture_ = AEGfxTextureLoad(picture_file_name_.c_str());
	attack_texture_ = AEGfxTextureLoad(attack_picture_file_name_.c_str());
}

void Trap::Update() {
	trigger();
	ends();
}

void Trap::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(0.0f, 0.0f);
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	if (state_ == false)
		AEGfxTextureSet(texture_, 0.0f, 0.0f);
	else
		AEGfxTextureSet(attack_texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Trap::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxTextureUnload(attack_texture_);
	AEGfxMeshFree(mesh_);
}


void Trap::trigger() {
	timeadd_++;
	if (type_ == KILL)
	{
		if (timeadd_ % 600 == 10)
			state_ = true;
	}
	if (type_ == SLOW)
	{
		if (timeadd_ % 600 == 20)
			state_ = true;
	}
	if (type_ == BACK)
	{
		if (timeadd_ % 600 == 30)
			state_ = true;
	}
	if (type_ == WEAKEN)
	{
		if (timeadd_ % 600 == 40)
			state_ = true;
	}
	if (timeadd_>3600)
		timeadd_ = 0;
}

void Trap::ends() {
	if (type_ == KILL)
	{
		if (timeadd_ % 1200 == 10)
			state_ = false;
	}
	if (type_ == SLOW)
	{
		if (timeadd_ % 1200 == 20)
			state_ = false;
	}
	if (type_ == BACK)
	{
		if (timeadd_ % 1200 == 30)
			state_ = false;
	}
	if (type_ == WEAKEN)
	{
		if (timeadd_ % 1200 == 40)
			state_ = false;
	}
}
