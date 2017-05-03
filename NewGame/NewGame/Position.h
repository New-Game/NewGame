/**
 * Project:      NewGame
 * File Name:    Position.h
 * Author:       Atlas Shen
 * Date:         2017/5/03
 * Purpose:      位置类头文件
 */

#pragma once

class Position {
public:
	Position() : x_(0), y_(0) {}
	Position(float x, float y) : x_(x), y_(y) {}
	Position(Position& position) : x_(position.GetX()), y_(position.GetY()) {}
	~Position() {}

	void SetPosition(float x, float y) {
		x_ = x;
		y_ = y;
	}

	void SetPosition(Position& position) {
		x_ = position.GetX();
		y_ = position.GetY();
	}

	float GetX() const {
		return x_;
	}

	float GetY() const {
		return y_;
	}

private:
	float x_;
	float y_;
};
