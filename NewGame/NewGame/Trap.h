/**
 * Project:      NewGame
 * File Name:    Trap.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      陷阱类头文件
 */

#pragma once

#include "GameElement.h"

class Character;

enum Traps {
	NONE,
	KILL,
	SLOW,
	BACK,
	WEAK
};

// 陷阱类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体陷阱类，成员函数使用虚函数来实现多态
class Trap : public GameElement {
public:
	Trap(Traps type, Rect rect) :
			GameElement(rect, "picture\\wall.png"),
			type_(type),
			status_(false), 
			period_(3), 
			count_(0), 
			attack_picture_("picture\\minion.png"),
			attack_texture_(nullptr) {}

	Trap() : 
			type_(NONE), 
			status_(false), 
			period_(3), 
			count_(0), 
			attack_picture_(""),
			attack_texture_(nullptr) {}

	~Trap() {}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

protected:
	Traps type_; // 陷阱种类 
	bool status_; // 触发状态 陷阱触发为true，陷阱关闭为false 
	int period_; // 陷阱周期
	int count_;	// 循环计数，用于判断陷阱是否触发 
	string attack_picture_;
	AEGfxTexture* attack_texture_;

	//void Active();

	//void Inactive();

	void TakeEffect(Character* p_character);

};
