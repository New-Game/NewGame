/**
 * Project:      NewGame
 * File Name:    Aimiliya.h
 * Author:       Atlas Shen
 * Date:         2017/5/7
 * Purpose:      ����������ͷ�ļ�
 */

#pragma once

#include "Character.h"

class Aimiliya : public Character {
public:
	Aimiliya(Rect rect, string picture_file_name) : Character(rect, picture_file_name) {}

	Aimiliya(const Aimiliya& aimiliya) : Character(aimiliya) {}
	
	Aimiliya() {}

	~Aimiliya() {}

	Aimiliya* GetClassType() override {
		return this;
	}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

private:
};
