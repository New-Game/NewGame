/**
 * Project:      NewGame
 * File Name:    Rect.h
 * Author:       Atlas Shen
 * Date:         2017/5/30
 * Purpose:      λ�óߴ���Ϣ��ͷ�ļ�
 */

#pragma once

enum Direction {
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Rect {
public:
	Rect(int size, int x, int y, enum Direction front) : size_(size), x_(x), y_(y), front_(front) {}
	Rect(const Rect& rect) : size_(rect.size_), x_(rect.x_), y_(rect.y_), front_(rect.front_) {}
	Rect() : size_(0), x_(0), y_(0), front_(NONE) {}
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

	void SetFront(enum Direction front) {
		front_ = front;
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

	enum Direction GetFront() const {
		return front_;
	}

private:
	int size_;             // �����α߳�
	int x_;                // ���������ϽǶ��������
	int y_;                // ���������ϽǶ���������
	enum Direction front_; // ������
};