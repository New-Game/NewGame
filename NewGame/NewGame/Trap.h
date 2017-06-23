/**
 * Project:      NewGame
 * File Name:    Trap.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      ������ͷ�ļ�
 */

#pragma once

#include "GameElement.h"
#include "Character.h"

enum Traps {
	STUN,
	KILL,
	BACK,
	WEAK
};

// �����࣬�̳���GameElement�࣬ͬ�����ǳ����࣬�����������ɶ���
// �����������������࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class Trap : public GameElement {
public:
	Trap(Traps type, Rect rect) :
			GameElement(rect, "picture\\trap.png"),
			type_(type),
			status_(false),
			count_(0),
			period_(3),
			lasting_time_(3),
			target_character_(nullptr),
			attack_texture_(nullptr), 
			AnimationController(80), 
			AnimationCurFrame(1) {
		switch(type) {
			case STUN:
				attack_picture_ = "picture\\stop.png";
				break;
			case KILL:
				attack_picture_ = "picture\\kill.png";
				break;
			case BACK:
				attack_picture_ = "picture\\back.png";
				break;
			case WEAK:
				// todo
				attack_picture_ = "picture\\back.png";
				break;
			default:
				break;
		}
	}

	Trap(const Trap& trap) : 
			GameElement(trap), 
			type_(trap.type_), 
			status_(trap.status_), 
			count_(trap.count_), 
			period_(trap.period_), 
			lasting_time_(trap.lasting_time_), 
			target_character_(trap.target_character_), 
			attack_picture_(trap.attack_picture_), 
			attack_texture_(trap.attack_texture_), 
			AnimationController(trap.AnimationController), 
			AnimationCurFrame(trap.AnimationCurFrame) {}

	Trap() : 
			type_(STUN), 
			status_(false), 
			count_(0), 
			period_(3), 
			lasting_time_(3), 
			target_character_(nullptr), 
			attack_picture_(""),
			attack_texture_(nullptr), 
			AnimationController(80), 
			AnimationCurFrame(1) {}

	~Trap() {}

	Traps GetType() const {
		return type_;
	}

	bool GetStatus() const {
		return status_;
	}

	void SetTargetCharacter(Character* p_character) {
		target_character_ = p_character;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

	void TakeEffect();

	void LoseEffect();

protected:
	Traps type_; // �������� 
	bool status_; // ����״̬ ���崥��Ϊtrue������ر�Ϊfalse 
	int count_;	// ѭ�������������ж������Ƿ񴥷� 
	int period_; // ��������
	int lasting_time_; // debuff����ʱ��
	Character* target_character_;
	string attack_picture_;
	AEGfxTexture* attack_texture_;

	int AnimationController;
	int AnimationCurFrame;
};
