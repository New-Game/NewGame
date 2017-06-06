/**
 * Project:      NewGame
 * File Name:    Buff.h
 * Author:       Long
 * Date:         2017/6/02
 * Purpose:      Buff类头文件
 */

#pragma once

#include "GameElement.h"

enum Buffs {
	TIME,
	SCORE,
	SPEED,
	DAMAGE,
	CD,
	INVINCIBLE,
	NUM_OF_BUFF_TYPES
};

class Buff : public GameElement {
public:
	Buff(Buffs type, Rect rect) : GameElement(rect, ""), type_(type), status_(true), count_(0), existing_time_(15) {
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
			case INVINCIBLE:
				picture_ = "picture\\invincible_buff.png";
				break;
			default:
				break;
		}
	}

	Buff() : type_(TIME), status_(true), count_(0), existing_time_(15) {}

	~Buff() {}

	Buffs GetType() const {
		return type_;
	}

	bool GetStatus() const {
		return status_;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

protected:
	Buffs type_;
	bool status_; // true表示存在且未被拾取，false表示存在时间结束后消失了
	int count_;
	int existing_time_;
};
