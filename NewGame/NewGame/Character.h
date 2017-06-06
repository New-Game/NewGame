/**
 * Project:      NewGame
 * File Name:    Character.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      ������ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

// �����࣬�̳���GameElement�࣬ͬ�����ǳ����࣬�����������ɶ���
// �����������������࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class Character : public GameElement {
public:
	Character(Rect rect, string picture) : 
			GameElement(rect, picture), 
			front_(DOWN), 
			lives_(3), 
			damage_(10), 
			speed_(3), 
			cold_down_(0) {}

	// ������ĸ��ƹ��캯���Ḵ��������Ϣ������mesh_��texture_����Ϣ)����������Ĳ���
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
			speed_(3), 
			cold_down_(0) {}

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

	void SetDamage(bool operation) {
		operation ? damage_ <<= 1 : damage_ >>= 1;
	}

	void SetSpeed(bool operation) {
		operation ? speed_ <<= 1 : speed_ >>= 1;
	}

	void SetColdDown(bool operation) {
		operation ? cold_down_ = 50 : cold_down_ = 0;
	}

protected:
	Directions front_; // ������
	int lives_; // ������
	int damage_;
	int speed_;
	int cold_down_;

	void Move();

	void Attack() const;

	void UseSkill();

};
