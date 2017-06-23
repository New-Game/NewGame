/**
* Project:      NewGame
* File Name:    Rem.cpp
* Author:       Atlas Shen
* Date:         2017/5/7
* Purpose:      雷姆类源文件
*/

#include "Rem.h"
#include "Input.h"

void Rem::Load() {
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

void Rem::Update() {
	Move();
	if (cold_down_ != 0) {
		++count_;
		if (count_ == System::GetFrameRate()) {
			count_ = 0;
			--cold_down_;
		}
	}
}

void Rem::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(float(rect_.GetX()), float(rect_.GetY()));
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Rem::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
}

Bullet* Rem::Attack() {
	string bullet_picture = "picture\\bullet.png";
	auto temp_size = 6;
	switch (front_) {
	case UP: {
		Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() / 2, rect_.GetY() - temp_size / 2);
		return new Bullet(UP, temp_rect, bullet_picture);
	}
	case DOWN: {
		Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() / 2, rect_.GetY() + rect_.GetSize() + temp_size / 2);
		return new Bullet(DOWN, temp_rect, bullet_picture);
	}
	case LEFT: {
		Rect temp_rect(temp_size, rect_.GetX() - temp_size / 2, rect_.GetY() + rect_.GetSize() / 2);
		return new Bullet(LEFT, temp_rect, bullet_picture);
	}
	case RIGHT: {
		Rect temp_rect(temp_size, rect_.GetX() + rect_.GetSize() + temp_size / 2, rect_.GetY() + rect_.GetSize() / 2);
		return new Bullet(RIGHT, temp_rect, bullet_picture);
	}
	default:
		return nullptr;
	}
}
