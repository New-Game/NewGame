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
		float(size_), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
		0.0f, float(size_), 0xFFFF0000, 0.0f, 1.0f);
	AEGfxTriAdd(
		float(size_), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
		float(size_), float(size_), 0xFFFF0000, 1.0f, 1.0f,
		0.0f, float(size_), 0xFFFF0000, 0.0f, 1.0f);
	mesh_ = AEGfxMeshEnd();
	texture_ = AEGfxTextureLoad(picture_file_name_.c_str());
}

void Bullet::Reset() {}

void Bullet::Update() {
	switch (front_) {
		case UP:
			position_.MoveUp(speed_ * 3);
			break;
		case DOWN:
			position_.MoveDown(speed_ * 3);
			break;
		case LEFT:
			position_.MoveLeft(speed_ * 3);
			break;
		case RIGHT:
			position_.MoveRight(speed_ * 3);
			break;
		default:
			break;
	}
}

void Bullet::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(float(position_.GetX()), float(position_.GetY()));
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Bullet::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
}