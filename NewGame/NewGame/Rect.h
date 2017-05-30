/**
 * Project:      NewGame
 * File Name:    Rect.h
 * Author:       Atlas Shen/Long
 * Date:         2017/5/07
 * Purpose:      位置矩形类头文件
 */

#pragma once

class Rect {
public:
	Rect(float size, float x, float y) : size_(size), x_(x), y_(y) {
		Update(x_, y_);
	}
	Rect() : Rect(0.0, 0.0, 0.0) {}
	Rect(const Rect& rect) : Rect(rect.size_, rect.x_, rect.y_) {}
	~Rect() {}

	bool IsCollision(Rect rect) const {
		return right_ > rect.left_ || left_ < rect.right_ || top_ > rect.bottom_ || bottom_ < rect.top_;
	}

	void MoveLeft(float distance) {
		x_ -= distance;
		Update(x_, y_);
	}
	
	void MoveRight(float distance) {
		x_ += distance;
		Update(x_, y_);
	}

	void MoveUp(float distance) {
		y_ -= distance;
		Update(x_, y_);
	}

	void MoveDown(float distance) {
		y_ += distance;
		Update(x_, y_);
	}

	float GetSize() const {
		return size_;
	}

	float GetX() const {
		return x_;
	}

	float GetY() const {
		return y_;
	}

	float GetLeft() const {
		return left_;
	}

	float GetRight() const {
		return right_;
	}

	float GetTop() const {
		return top_;
	}

	float GetBottom() const {
		return bottom_;
	}

private:
	float size_;
	float x_;
	float y_;
	float left_;
	float right_;
	float top_;
	float bottom_;

	void Update(float x, float y) {
		left_ = x - size_ / 2;
		right_ = x + size_ / 2;
		top_ = y - size_ / 2;
		bottom_ = y + size_ / 2;
	}
};
