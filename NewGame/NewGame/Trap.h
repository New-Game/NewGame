/**
 * Project:      NewGame
 * File Name:    Trap.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      ������ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

class Character;

enum Traps {
	NONE,
	KILL,
	SLOW,
	BACK,
	WEAK
};

// �����࣬�̳���GameElement�࣬ͬ�����ǳ����࣬�����������ɶ���
// �����������������࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class Trap : public GameElement {
public:
	Trap(Traps type, Rect rect) :
			GameElement(rect, "picture\\wall.png"),
			type_(type),
			status_(false), 
			period_(3), 
			count_(0), 
			attack_picture_("picture\\minion.png"),
			attack_texture_(nullptr) {}

	Trap() : 
			type_(NONE), 
			status_(false), 
			period_(3), 
			count_(0), 
			attack_picture_(""),
			attack_texture_(nullptr) {}

	~Trap() {}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

protected:
	Traps type_; // �������� 
	bool status_; // ����״̬ ���崥��Ϊtrue������ر�Ϊfalse 
	int period_; // ��������
	int count_;	// ѭ�������������ж������Ƿ񴥷� 
	string attack_picture_;
	AEGfxTexture* attack_texture_;

	//void Active();

	//void Inactive();

	void TakeEffect(Character* p_character);

};
