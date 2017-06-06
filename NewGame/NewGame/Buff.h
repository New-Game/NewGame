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
	NONE,
	TIME,
	SCORE,
	SPEED,
	DAMAGE,
	CD,
	INVINCIBLE
};

class Buff : public GameElement {
public:
	Buff(Buffs type, Rect rect, string picture) : 
			GameElement(rect, picture), 
			type_(type), 
			status_(false), 
			count_(0), 
			existing_time_(15), 
			lasting_time_(15) {}

	Buff() : 
			type_(NONE), 
			status_(false), 
			count_(0), 
			existing_time_(15), 
			lasting_time_(15) {}

	~Buff() {}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

	void TakeEffect(Character* p_character);

protected:
	Buffs type_;
	bool status_; // false表示existing（存在但被拾取），true表示lasting（存在且被拾取）
	int count_;
	int existing_time_;
	int lasting_time_;
};
