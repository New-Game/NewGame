/**
 * Project:      NewGame
 * File Name:    Character.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      人物类头文件
 */

#pragma once

#include "GameElement.h"

// 人物类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体人物类，成员函数使用虚函数来实现多态
class Character : public GameElement {
public:
	Character() : front_(DOWN), lives_(3), damage_(100), speed_(1), skill_cold_down_(0.0) {}
	Character(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name),
	          front_(DOWN), lives_(3), damage_(100), speed_(1), skill_cold_down_(0.0) {}
	virtual ~Character() {}

	void SetLives(int lives) {
		lives_ = lives;
	}

protected:
	enum Direction front_; // 面向方向
	int lives_; // 生命数
	int damage_;
	int speed_;
	float skill_cold_down_;

	void Move();
	void Attack();
	void UseSkill();
	void GetBuff();
};
