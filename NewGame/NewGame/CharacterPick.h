/**
 * Project:      NewGame
 * File Name:    CharacterPick.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      人物选择类头文件
 */

#pragma once

#include <iostream>
#include "GameState.h"
#include "System.h"

using namespace std;

// 人物选择类，单实例类
class CharacterPick : public GameState {
public:
	CharacterPick() : picture_file_name_(nullptr), mesh_(nullptr), texture_(nullptr) {}
	CharacterPick(string picture_file_name) : picture_file_name_(picture_file_name),
	                                          mesh_(nullptr),
	                                          texture_(nullptr) {}
	~CharacterPick() {}

	void Load() override;
	void Reset() override;
	void Process() override;
	void Unload() override;

private:
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
