/**
 * Project:      NewGame
 * File Name:    Rect.h
 * Author:       Atlas Shen
 * Date:         2017/5/30
 * Purpose:      位置尺寸信息类头文件
 */

#pragma once

class Rect {
public:
	Rect(int size, int x, int y) : size_(size), x_(x), y_(y) {}
	Rect(const Rect& rect) : size_(rect.size_), x_(rect.x_), y_(rect.y_) {}
	Rect() : size_(0), x_(0), y_(0) {}
	~Rect() {}

	bool IsCollision(Rect rect) const {
		return y_ + size_ > rect.y_ && y_ < rect.y_ + rect.size_
			&& x_ + size_ > rect.x_ && x_ < rect.x_ + rect.size_;
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

	int GetSize() const {
		return size_;
	}

	int GetX() const {
		return x_;
	}

	int GetY() const {
		return y_;
	}

private:
	int size_; // 正方形边长
	int x_;    // 正方形左上角定点横坐标
	int y_;    // 正方形左上角定点纵坐标
};
