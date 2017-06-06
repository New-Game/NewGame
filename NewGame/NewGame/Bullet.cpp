/**
 * Project:      NewGame
 * File Name:    Bullet.cpp
 * Author:       Atlas Shen
 * Date:         2017/5/29
 * Purpose:      子弹类实现文件
 */

#include "Bullet.h"

void Bullet::Load() {
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

void Bullet::Update() {
	switch (front_) {
		case UP:
			rect_.MoveUp(speed_);
			break;
		case DOWN:
			rect_.MoveDown(speed_);
			break;
		case LEFT:
			rect_.MoveLeft(speed_);
			break;
		case RIGHT:
			rect_.MoveRight(speed_);
			break;
		default:
			break;
	}
}

void Bullet::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(float(rect_.GetX()), float(rect_.GetY()));
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Bullet::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
}
