/**
 * Project:      NewGame
 * File Name:    Character.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      人物类头文件
 */

#pragma once

#include <unordered_map>
#include "GameElement.h"
#include "Bullet.h"
#include "Skill.h"

// 人物类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体人物类，成员函数使用虚函数来实现多态
class Character : public GameElement {
public:
	Character(Rect rect, string picture) : 
			GameElement(rect, picture), 
			front_(DOWN), 
			lives_(3), 
			damage_(10), 
			speed_(1), 
			cold_down_(0) {}

	// 人物类的复制构造函数会复制所有信息（包括mesh_和texture_的信息)，而怪物类的不会
	Character(const Character& character) :
			GameElement(character), 
			front_(character.front_), 
			lives_(character.lives_), 
			damage_(character.damage_), 
			speed_(character.speed_), 
			cold_down_(character.cold_down_) {}

	Character() : 
			front_(DOWN), 
			lives_(3), 
			damage_(10), 
			speed_(1), 
			cold_down_(0) {}

	virtual ~Character() {}

	virtual Bullet* Attack() = 0;

	virtual Skill* UseSkill() = 0;

	Character* GetClassType() override {
		return this;
	}

	Directions GetFront() const {
		return front_;
	}
	
	int GetLives() const {
		return lives_;
	}

	int GetDamage() const {
		return damage_;
	}

	int GetSpeed() const {
		return speed_;
	}

	int GetColdDown() const {
		return cold_down_;
	}

	bool DecLives() {
		return --lives_ > 0 ? true : false;
	}

	void SetDamage(bool operation) {
		operation ? damage_ = 20 : damage_ = 10;
	}

	void SetSpeed(bool operation) {
		operation ? speed_ = 2 : speed_ = 1;
	}

	void SetColdDown(bool operation) {
		operation ? cold_down_ >>= 1 : cold_down_ <<= 1;
	}

	void SetStun(bool operation) {
		operation ? speed_ = 0 : speed_ = 1;
	}

	void SetWeak(bool operation) {
		operation ? damage_ = 5 : damage_ = 10;
	}

protected:
	Directions front_; // 面向方向
	int lives_; // 生命数
	int damage_;
	int speed_;
	int cold_down_;

	void Move();

};
