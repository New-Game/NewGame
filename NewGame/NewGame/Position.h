/**
 * Project:      NewGame
 * File Name:    Position.h
 * Author:       Atlas Shen
 * Date:         2017/5/30
 * Purpose:      位置类头文件
 */

#pragma once

class Position {
public:
	Position(int x, int y) : x_(x), y_(y) {}
	Position(const Position& position) : Position(position.x_, position.y_) {}
	Position() : x_(0), y_(0) {}
	~Position() {}

	bool IsCollision(int size, Position position, int target_size) const {
		return y_ + size > position.y_ && y_ < position.y_ + target_size
			&& x_ + size > position.x_ && x_ < position.x_ + target_size;
	}

	void MoveLeft(int distance) {
		x_ -= distance;
	}

	void MoveRight(int distance) {
		x_ += distance;
	}

	void MoveUp(int distance) {
		y_ -= distance;
	}

	void MoveDown(int distance) {
		y_ += distance;
	}

	int GetX() const {
		return x_;
	}

	int GetY() const {
		return y_;
	}

private:
	int x_; // 矩形的左上角横坐标
	int y_; // 矩形的左上角纵坐标
};
