/**
 * Project:      NewGame
 * File Name:    Deathless.cpp
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      不死怪兽类实现文件
 */

#include "Deathless.h"

void Deathless::Load() {
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
}

void Deathless::Update() {
	Move();

	if (speed_ == 0) status_ = 1;
	if (status_ == 1) {
		count_++;
		if (count_ == 120) {
			count_ = 0;
			time_++;
		}
		if (time_ == 3) {
			status_ = 0;
			time_ = 0;
			SetSpeed(2);
		}
	}
}

void Deathless::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(float(rect_.GetX()), float(rect_.GetY()));
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Deathless::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
}
