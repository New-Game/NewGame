/**
 * Project:      NewGame
 * File Name:    Minion.cpp
 * Author:       Atlas
 * Date:         2017/6/03
 * Purpose:      普通怪兽类实现文件
 */

#include "Minion.h"

void Minion::Load() {
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
	original_ = new Minion(this);
}

void Minion::Reset() {
	// 重置rect, front, speed, x_min, x_max, y_min, y_max
	rect_ = dynamic_cast<Minion*>(original_)->rect_;
	front_ = dynamic_cast<Minion*>(original_)->front_;
	speed_ = dynamic_cast<Minion*>(original_)->speed_;
	x_min_ = dynamic_cast<Minion*>(original_)->x_min_;
	x_max_ = dynamic_cast<Minion*>(original_)->x_max_;
	y_min_ = dynamic_cast<Minion*>(original_)->y_min_;
	y_max_ = dynamic_cast<Minion*>(original_)->y_max_;
}

void Minion::Update() {
	Move();
}

void Minion::Draw() {
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	AEGfxSetPosition(float(rect_.GetX()), float(rect_.GetY()));
	AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
	AEGfxTextureSet(texture_, 0.0f, 0.0f);
	AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
}

void Minion::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
	delete original_;
}
