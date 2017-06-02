/**
 * Project:      NewGame
 * File Name:    Aimiliya.h
 * Author:       Atlas Shen
 * Date:         2017/5/7
 * Purpose:      艾米莉亚类头文件
 */

#pragma once

#include "Character.h"

class Aimiliya : public Character {
public:
	Aimiliya(Rect rect, string picture_file_name) : Character(rect, picture_file_name) {}
	Aimiliya() {}
	~Aimiliya() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
private:
};
