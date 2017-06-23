/**
* Project:      NewGame
* File Name:    Picture.h
* Author:       Atlas Shen
* Date:         2017/6/14
* Purpose:      图片显示类头文件
*/

#pragma once

#include <string>
#include "AEEngine.h"

class Picture {
public:
	Picture(std::string picture, int x, int y) : x_(x), y_(y), width_(80), height_(50) {
		AEGfxMeshStart();
		AEGfxTriAdd(
			float(width_), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
			0.0f, 0.0f, 0xFFFF0000, 0.0f, 0.0f,
			0.0f, float(height_), 0xFFFF0000, 0.0f, 1.0f);
		AEGfxTriAdd(
			float(width_), 0.0f, 0xFFFF0000, 1.0f, 0.0f,
			float(width_), float(height_), 0xFFFF0000, 1.0f, 1.0f,
			0.0f, float(height_), 0xFFFF0000, 0.0f, 1.0f);
		mesh_ = AEGfxMeshEnd();
		texture_ = AEGfxTextureLoad(picture.c_str());
	}

	Picture() : picture_(""), x_(0), y_(0), width_(80), height_(50), mesh_(nullptr), texture_(nullptr) {}

	~Picture() {
		AEGfxTextureUnload(texture_);
		AEGfxMeshFree(mesh_);
	}

	void Draw() const {
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		AEGfxSetPosition(float(x_), float(y_));
		AEGfxSetTextureMode(AE_GFX_TM_AVERAGE);
		AEGfxTextureSet(texture_, 0.0f, 0.0f);
		AEGfxMeshDraw(mesh_, AE_GFX_MDM_TRIANGLES);
	}

private:
	const std::string picture_;
	const int x_; // 左上角横坐标
	const int y_; // 左上角纵坐标
	const int width_;
	const int height_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
