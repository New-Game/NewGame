/**
 * Project:      NewGame
 * File Name:    Buff.h
 * Author:       Long
 * Date:         2017/6/02
 * Purpose:      Buff��ͷ�ļ�
 */

#pragma once

#include "GameElement.h"
#include "Character.h"

class Buff : public GameElement {
public:
	Buff(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name),
	                                            existing_time_(15), 
	                                            lasting_time_(15),
	                                            status_(false) {}
	Buff() : existing_time_(15), lasting_time_(15), status_(false) {}
	virtual ~Buff() {}

	virtual void Affect(Character* p_character) = 0;

protected:
	int existing_time_;
	int lasting_time_;
	bool status_;      // false��ʾ���ڵ�����Ч��true��ʾ��������Ч
};
