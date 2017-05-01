/**
 * Project:      NewGame
 * File Name:    Interval.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      间隔类头文件
 */

#pragma once

#include <iostream>
#include "GameState.h"
#include "System.h"

using namespace std;

// 间隔类，多实例类，实例化出：
// 游戏前序、背景故事、关卡1前序、关卡1后续、关卡2前序、关卡2后续、关卡3前序、关卡3后续、奖励环节、游戏后续 这些状态
class Interval : public GameState {
public:
	Interval() : GameState(), picture_file_name_(nullptr), mesh_(nullptr), texture_(nullptr) {}
	Interval(string name, string picture_file_name) : GameState(name), 
	                                                  picture_file_name_(picture_file_name), 
	                                                  mesh_(nullptr),
	                                                  texture_(nullptr) {}
	~Interval() {}
	void Load() override;
	void Initialize() override;
	void Process() override;
	void Free() override;
	void Unload() override;

private:
	string picture_file_name_; // 用来存纹理图片的文件名
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
