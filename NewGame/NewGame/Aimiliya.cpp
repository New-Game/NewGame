/**
 * Project:      NewGame
 * File Name:    Aimiliya.h
 * Author:       Atlas Shen
 * Date:         2017/5/7
 * Purpose:      艾米莉亚类头文件
 */

#include "Aimiliya.h"
#include "Input.h"

void Aimiliya::Load() {
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
	texture_ = AEGfxTextureLoad(picture_file_name_.c_str());
	original_ = new Aimiliya(rect_);
}

void Aimiliya::Reset() {
	// 重置rect, front, lives, damage, speed, skill_cold_down
	rect_ = dynamic_cast<Aimiliya*>(original_)->rect_;
	front_ = dynamic_cast<Aimiliya*>(original_)->front_;
	lives_ = dynamic_cast<Aimiliya*>(original_)->lives_;
	damage_ = dynamic_cast<Aimiliya*>(original_)->damage_;
	speed_ = dynamic_cast<Aimiliya*>(original_)->speed_;
	skill_cold_down_ = dynamic_cast<Aimiliya*>(original_)->skill_cold_down_;
}

void Aimiliya::Update() {
	Move();
	BulletCollisionCheck();
	if (Input::GetPressedKey(KEY_A).GetIsPressed()) {
		Attack();
		Input::GetPressedKey(KEY_A).SetIsPressed(false);
	}
	else if (Input::GetPressedKey(KEY_S).GetIsPressed()) {
		UseSkill();
		Input::GetPressedKey(KEY_S).SetIsPressed(false);
	}
}

void Aimiliya::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(float(rect_.GetX()), float(rect_.GetY()));
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Aimiliya::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
	delete original_;
}
