/**
 * Project:      NewGame
 * File Name:    Wall.cpp
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      墙体类实现文件
 */

#include "Wall.h"

void Wall::Load() {
	AEGfxMeshStart();
	AEGfxTriAdd(
		rect_.GetRight(), rect_.GetTop(), 0xFFFF0000, 1.0f, 0.0f,
		rect_.GetLeft(), rect_.GetTop(), 0xFFFF0000, 0.0f, 0.0f,
		rect_.GetLeft(), rect_.GetBottom(), 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		rect_.GetRight(), rect_.GetTop(), 0xFFFF0000, 1.0f, 0.0f,
		rect_.GetRight(), rect_.GetBottom(), 0xFFFF0000, 1.0f, 1.0f,
		rect_.GetLeft(), rect_.GetBottom(), 0xFFFF0000, 0.0f, 1.0f);
	mesh_ = AEGfxMeshEnd();
	texture_ = AEGfxTextureLoad(picture_file_name_.c_str());
}

void Wall::Initialize() {}

void Wall::Update() {}

void Wall::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(0.0f, 0.0f);
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Wall::Free() {}

void Wall::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
}
