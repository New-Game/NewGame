/**
 * Project:      NewGame
 * File Name:    Resource.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      ��Ʒ��ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

// ��Ʒ�࣬�̳���GameElement�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������Ϸ��Ʒ�࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class Item : public GameElement {
public:
	virtual ~Item() {}
protected:
};
