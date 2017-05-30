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
	Aimiliya() {}
	Aimiliya(int size, Position position, string picture_file_name) : 
	         Character(size, position, picture_file_name) {}
	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
private:
};
