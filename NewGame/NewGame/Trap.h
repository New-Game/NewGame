/**
 * Project:      NewGame
 * File Name:    Trap.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      ������ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

enum Traps {
	NONE,
	KILL,
	SLOW,
	BACK,
	WEAKEN
};

// �����࣬�̳���GameElement�࣬ͬ�����ǳ����࣬�����������ɶ���
// �����������������࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class Trap : public GameElement {
public:
	Trap(Traps type, Rect rect, string picture_file_name, string attack_picture_file_name) :
			GameElement(rect, picture_file_name),
			type_(type),
			attack_picture_file_name_(attack_picture_file_name),
			attack_texture_(nullptr),
			timeadd_(0), 
			state_(false) {}

	Trap() : 
			type_(NONE), 
			attack_picture_file_name_(""),
			attack_texture_(nullptr), 
			timeadd_(0), 
			state_(false) {}

	~Trap() {}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

protected:
	Traps type_;		//�������� 
	string attack_picture_file_name_;
	AEGfxTexture* attack_texture_;
	int timeadd_;	//ѭ�������������ж������Ƿ񴥷� 
	bool state_;	//����״̬ 1=���崥����0=����ر� 

	void trigger();

	void ends();

};
