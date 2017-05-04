/**
 * Project:      NewGame
 * File Name:    GameElement.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      ��ϷԪ����ͷ�ļ�
 */

#pragma once

#include <string>
#include "State.h"
#include "AEEngine.h"
#include "Position.h"

using namespace std;

// ��ϷԪ���࣬�̳���State�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������ϷԪ���࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class GameElement : public State {
public:
	GameElement() : size_(0), position_(), picture_file_name_(nullptr), mesh_(nullptr), texture_(nullptr) {}
	GameElement(int size, const Position position, string picture_file_name) : 
	            size_(size), 
	            position_(position), 
	            picture_file_name_(picture_file_name), 
	            mesh_(nullptr), 
	            texture_(nullptr) {}
	virtual ~GameElement() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetSize() const {
		return size_;
	}

	Position GetPosition() const {
		return position_;
	}

	void SetSize(int size) {
		size_ = size;
	}

	void SetPosition(const Position position) {
		position_.SetPosition(position);
	}

protected:
	int size_;
	Position position_;
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
