/**
 * Project:      NewGame
 * File Name:    Monster.h
 * Author:       Atlas/Long
 * Date:         2017/4/18
 * Purpose:      ������ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

// �����࣬�̳���GameElement�࣬ͬ�����ǳ����࣬�����������ɶ���
// ����������������࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class Monster : public GameElement {
public:
	Monster(Rect rect, string picture_file_name) : 
			GameElement(rect, picture_file_name), 
			front_(DOWN), 
			speed_(1), 
			x_min_(0), 
			x_max_(0), 
			y_min_(0), 
			y_max_(0) {}

	// �����ิ�ƹ��캯�����Ḵ��mesh_��texture_����Ϣ����������Ļ�
	Monster(const Monster& monster) : 
			GameElement(monster.rect_, monster.picture_file_name_), 
			front_(monster.front_), 
			speed_(monster.speed_), 
			x_min_(monster.x_min_),
			x_max_(monster.x_max_),
			y_min_(monster.y_min_),
			y_max_(monster.y_max_) {}

	Monster() : front_(DOWN), speed_(1), x_min_(0), x_max_(0), y_min_(0), y_max_(0) {}

	virtual ~Monster() {}

	Monster* GetClassType() override {
		return this;
	}

	void SetFront(Directions front) {
		front_ = front;
	}

	void SetXRange(int j_min, int j_max) {
		x_min_ = j_min * rect_.GetSize();
		x_max_ = j_max * rect_.GetSize();
	}

	void SetYRange(int i_min, int i_max) {
		y_min_ = i_min * rect_.GetSize();
		y_max_ = i_max * rect_.GetSize();
	}

protected:
	Directions front_;
	int speed_;
	int x_min_;
	int x_max_;
	int y_min_;
	int y_max_;

	void Move();

	void DropBuff();

};
