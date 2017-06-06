/**
 * Project:      NewGame
 * File Name:    Character.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      人物类头文件
 */

#pragma once

#include "GameElement.h"
#include "Buff.h"
#include "Trap.h"

// 人物类，继承了GameElement类，同样还是抽象类，不能用于生成对象
// 用于派生具体人物类，成员函数使用虚函数来实现多态
class Character : public GameElement {
public:
	Character(Rect rect, string picture) : 
			GameElement(rect, picture), 
			front_(DOWN), 
			lives_(3), 
			damage_(10), 
			speed_(4), 
			cold_down_(0), 
			count_(0), 
			buff_lasting_time_(15) {}

	// 人物类的复制构造函数会复制所有信息（包括mesh_和texture_的信息)，而怪物类的不会
	Character(const Character& character) :
			GameElement(character), 
			front_(character.front_), 
			lives_(character.lives_), 
			damage_(character.damage_), 
			speed_(character.speed_), 
			cold_down_(character.cold_down_),
			count_(character.count_), 
			buff_lasting_time_(character.buff_lasting_time_) {}

	Character() : 
			front_(DOWN), 
			lives_(3), 
			damage_(10), 
			speed_(4), 
			cold_down_(0), 
			count_(0), 
			buff_lasting_time_(15) {}

	virtual ~Character() {}

	Character* GetClassType() override {
		return this;
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

	/*void SetDamage(bool operation) {
		operation? damage_ <<= 1 : damage_ >>= 1;
	}

	void SetSpeed(bool operation) {
		operation? speed_ <<= 1 : speed_ >>= 1;
	}

	void SetColdDown() {
		cold_down_ = 50;
	}*/

	void GetBuff(Buffs type);

	void GetDebuff(Traps type);

protected:
	Directions front_; // 面向方向
	int lives_; // 生命数
	int damage_;
	int speed_;
	int cold_down_;
	int count_;
	int buff_lasting_time_;

	void Move();

	void Attack() const;

	void UseSkill();

};
