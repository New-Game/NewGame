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
	Buff(Buffs type, Rect rect, string picture_file_name) : 
			GameElement(rect, picture_file_name), 
			type_(type), 
			existing_time_(15), 
			lasting_time_(15), 
			status_(false) {}
	Buff() : type_(NONE), existing_time_(15), lasting_time_(15), status_(false) {}
	~Buff() {}

	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;

	void Affect(Character* p_character);

protected:
	Buffs type_;
	int existing_time_;
	int lasting_time_;
	bool status_;      // false表示存在但不生效，true表示存在且生效
};
