/**
 * Project:      NewGame
 * File Name:    Resource.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      ��Ʒ��ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

// ��Ʒ�࣬�̳���GameElement�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������Ϸ��Ʒ�࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class Item : public GameElement {
public:
	Item(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name) {}
	Item() {}
	virtual ~Item() {}
protected:
};

