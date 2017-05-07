/**
 * Project:      NewGame
 * File Name:    Aimiliya.h
 * Author:       Atlas Shen
 * Date:         2017/5/7
 * Purpose:      艾米莉亚类头文件
 */

#include "Aimiliya.h"

void Aimiliya::Load() {
	AEGfxMeshStart();
	AEGfxTriAdd(
		rect_.GetSize(), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
		0.0f, rect_.GetSize(), 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		rect_.GetSize(), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		rect_.GetSize(), rect_.GetSize(), 0xFFFF0000, 1.0f, 1.0f,
		0.0f, rect_.GetSize(), 0xFFFF0000, 0.0f, 1.0f);
	mesh_ = AEGfxMeshEnd();
	texture_ = AEGfxTextureLoad(picture_file_name_.c_str());
}

void Aimiliya::Initialize() {
	
}

void Aimiliya::Update() {
	Move();
}

void Aimiliya::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(rect_.GetX() - rect_.GetSize() /2, rect_.GetY() - rect_.GetSize() / 2);
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Aimiliya::Free() {
	
}

void Aimiliya::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
}
