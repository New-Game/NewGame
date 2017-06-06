/**
 * Project:      NewGame
 * File Name:    Buff.h
 * Author:       Long
 * Date:         2017/6/02
 * Purpose:      Buff类头文件
 */

#pragma once

#include "GameElement.h"
#include "Character.h"

enum Buffs {
	TIME,
	SCORE,
	SPEED,
	DAMAGE,
	CD,
	//INVINCIBLE,
	NUM_OF_BUFF_TYPES
};

enum BuffStatus {
	VANISHED,
	EXISTING,
	LASTING
};

class Buff : public GameElement {
public:
	Buff(Buffs type, Rect rect) : 
			GameElement(rect, ""), 
			type_(type), 
			status_(EXISTING), 
			count_(0), 
			existing_time_(15), 
			lasting_time_(15), 
			target_character_(nullptr) {
		switch(type) {
			case TIME:
				picture_ = "picture\\time_buff.png";
				break;
			case SCORE:
				picture_ = "picture\\score_buff.png";
				break;
			case SPEED:
				picture_ = "picture\\speed_buff.png";
				break;
			case DAMAGE:
				picture_ = "picture\\damage_buff.png";
				break;
			case CD:
				picture_ = "picture\\cd_buff.png";
				break;
			//case INVINCIBLE:
			//	picture_ = "picture\\invincible_buff.png";
			//	break;
			default:
				break;
		}
	}

	Buff() : 
			type_(TIME), 
			status_(EXISTING), 
			count_(0), 
			existing_time_(15), 
			lasting_time_(15), 
			target_character_(nullptr) {}

	~Buff() {}

	Buffs GetType() const {
		return type_;
	}

	BuffStatus GetStatus() const {
		return status_;
	}

	void SetVanished() {
		status_ = VANISHED;
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
	Buffs type_;
	BuffStatus status_;
	int count_;
	int existing_time_;
	int lasting_time_;
	Character* target_character_;
};
