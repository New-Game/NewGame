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
	Bullet(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name), speed_(6) {}
	Bullet() : speed_(0) {}
	~Bullet() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;

private:
	int speed_;
};