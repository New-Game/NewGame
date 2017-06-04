/**
 * Project:      NewGame
 * File Name:    GameElement.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      ��ϷԪ����ͷ�ļ�
 */

#pragma once

#include <string>
#include "AEEngine.h"
#include "Rect.h"

using namespace std;

// ��ϷԪ�ص�������
enum Directions {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// ��ϷԪ���࣬�̳���State�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������ϷԪ���࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class GameElement {
public:
	GameElement(int size, int x, int y, string picture_file_name) : 
			rect_(size, x, y), 
			picture_file_name_(picture_file_name), 
			mesh_(nullptr), 
			texture_(nullptr) {}

	GameElement(Rect rect, string picture_file_name) : 
			rect_(rect), 
			picture_file_name_(picture_file_name), 
			mesh_(nullptr), 
			texture_(nullptr) {}

	GameElement(const GameElement& game_element) : 
			rect_(game_element.rect_), 
			picture_file_name_(game_element.picture_file_name_), 
			mesh_(game_element.mesh_), 
			texture_(game_element.texture_) {}

	GameElement() : GameElement(0, 0, 0, "") {}

	virtual ~GameElement() {}

	virtual GameElement* GetClassType() {
		return this;
	}

	Rect GetRect() const {
		return rect_;
	}

	virtual void Load() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Unload() = 0;

protected:
	Rect rect_;
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
