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
#include "Rect.h"

using namespace std;

// ��ϷԪ���࣬�̳���State�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������ϷԪ���࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class GameElement : public State {
public:
	GameElement(float size, float x, float y, string picture_file_name) :
                rect_(size, x, y),
	            picture_file_name_(picture_file_name), 
	            mesh_(nullptr), 
	            texture_(nullptr) {}
	GameElement() : GameElement(0.0, 0.0, 0.0, nullptr) {}
	virtual ~GameElement() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	Rect rect_;
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
