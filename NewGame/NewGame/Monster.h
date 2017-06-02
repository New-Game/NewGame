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
	Monster(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name), speed_(2) {}
	Monster() : speed_(2) {}
	virtual ~Monster() {}

protected:
	int speed_;

	void Move();
	void DropBuff();
};
