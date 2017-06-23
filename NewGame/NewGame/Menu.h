/**
 * Project:      NewGame
 * File Name:    Gstart.h
 * Author:		ChenKun
 * Date:         2017/6/11
 * Purpose:      开始菜单类头文件
 */

#pragma once

#include "GameState.h"
#include "System.h"

// 开始菜单类
class Menu : public GameState {
public:
	Menu() : 
		picture_file_name_(nullptr), 
		mesh_(nullptr), 
		texture_(nullptr) {}

	Menu(string picture_file_name) : 
		picture_file_name_(picture_file_name),
		mesh_(nullptr),
		texture_(nullptr) {}

	~Menu() {}

	void Load() override;
	void Reset() override;
	void Process() override;
	void Unload() override;

private:
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
