/**
 * Project:      NewGame
 * File Name:    Trap.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      陷阱类头文件
 */

#pragma once

#include "GameElement.h"

enum Traps {
	NONE,
	KILL,
	SLOW,
	BACK,
	WEAKEN
};

// 陷阱类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体陷阱类，成员函数使用虚函数来实现多态
class Trap : public GameElement {
public:
	Trap(Traps type, Rect rect, string picture_file_name, string attack_picture_file_name) :
			GameElement(rect, picture_file_name),
			type_(type),
			attack_picture_file_name_(attack_picture_file_name),
			attack_texture_(nullptr),
			timeadd_(0), 
			state_(false) {}

	Trap() : 
			type_(NONE), 
			attack_picture_file_name_(""),
			attack_texture_(nullptr), 
			timeadd_(0), 
			state_(false) {}

	~Trap() {}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

protected:
	Traps type_;		//陷阱种类 
	string attack_picture_file_name_;
	AEGfxTexture* attack_texture_;
	int timeadd_;	//循环计数，用于判断陷阱是否触发 
	bool state_;	//触发状态 1=陷阱触发，0=陷阱关闭 

	void trigger();

	void ends();

};
