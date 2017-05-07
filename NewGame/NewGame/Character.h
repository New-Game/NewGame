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
	Character() : front_(DOWN), lives_(3), damage_(100), speed_(1), skill_cold_down_(0.0) {}
	Character(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name),
	          front_(DOWN), lives_(3), damage_(100), speed_(1), skill_cold_down_(0.0) {}
	virtual ~Character() {}

	void SetLives(int lives) {
		lives_ = lives;
	}

protected:
	enum Direction front_; // ������
	int lives_; // ������
	int damage_;
	int speed_;
	float skill_cold_down_;

	void Move();
	void Attack();
	void UseSkill();
	void GetBuff();
};
