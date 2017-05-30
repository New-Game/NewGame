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

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum GameElements {
	ROAD,
	WALL,
	TRAP,
	CHARACTER,
	MONSTER,
	BULLET,
	TREASURE,
	BUFF,
	NUM_OF_GAME_ELEMENT_TYPE
};

// ��ϷԪ���࣬�̳���State�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������ϷԪ���࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class GameElement : public State {
public:
	GameElement(int size, int x, int y, string picture_file_name) :
		        size_(size),
	            position_(x, y),
                original_position_(position_),
	            picture_file_name_(picture_file_name), 
	            mesh_(nullptr), 
	            texture_(nullptr) {}
	GameElement(int size, Position position, string picture_file_name) :
		        size_(size),
	            position_(position),
	            original_position_(position_),
	            picture_file_name_(picture_file_name),
	            mesh_(nullptr),
	            texture_(nullptr) {}
	GameElement() : GameElement(0, 0, 0, nullptr) {}
	virtual ~GameElement() {}

	int GetSize() const {
		return size_;
	}

	Position GetPosition() const {
		return position_;
	}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	int size_;
	Position position_;
	const Position original_position_;
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
