/**
 * Project:      NewGame
 * File Name:    Buff.h
 * Author:       Long
 * Date:         2017/6/02
 * Purpose:      Buff类头文件
 */

#include "Buff.h"
#include "System.h"

void Buff::Load() {
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

void Buff::Update() {
	if (status_ != VANISHED) {
		++count_;
		if (count_ == System::GetFrameRate()) {
			count_ = 0;
			if (status_ == EXISTING)
				--existing_time_;
			else if (status_ == LASTING)
				--lasting_time_;
		}
		if (existing_time_ == 0)
			status_ = VANISHED;
		else if (lasting_time_ == 0)
			LoseEffect();
	}
}

void Buff::Draw() {
	if (status_ == EXISTING) {
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetPosition(float(rect_.GetX()), float(rect_.GetY()));
		AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
		AEGfxTextureSet(texture_, 0.0f, 0.0f);
		AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
	}
}

void Buff::Unload() {
	AEGfxTextureUnload(texture_);
	AEGfxMeshFree(mesh_);
}

void Buff::TakeEffect() {
	status_ = LASTING;
	switch(type_) {
		case SPEED:
			target_character_->SetSpeed(true);
			if (target_character_->GetRect().GetX() % 2 == 1)
				target_character_->GetRect().MoveLeft(1);
			if (target_character_->GetRect().GetY() % 2 == 1)
				target_character_->GetRect().MoveUp(1);
			break;
		case DAMAGE:
			target_character_->SetDamage(true);
			break;
		case CD:
			target_character_->SetColdDown(true);
			break;
		default:
			break;
	}
}

void Buff::LoseEffect() {
	status_ = VANISHED;
	switch(type_) {
		case SPEED:
			target_character_->SetSpeed(false);
			break;
		case DAMAGE:
			target_character_->SetDamage(false);
			break;
		case CD:
			target_character_->SetColdDown(false);
			break;
		default:
			break;
	}
}
