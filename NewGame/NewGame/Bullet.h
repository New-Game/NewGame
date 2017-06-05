/**
 * Project:      NewGame
 * File Name:    Bullet.h
 * Author:       Atlas Shen
 * Date:         2017/5/29
 * Purpose:      �ӵ���ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

class Bullet : public GameElement {
public:
	Bullet(Directions front, Rect rect, string picture_file_name) : 
			GameElement(rect, picture_file_name), 
			front_(front), 
			speed_(4) {}

	Bullet() : front_(DOWN), speed_(4) {}

	~Bullet() {}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

private:
	Directions front_;
	int speed_;
};
