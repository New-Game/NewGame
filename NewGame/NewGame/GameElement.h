/**
 * Project:      NewGame
 * File Name:    GameElement.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      ��ϷԪ����ͷ�ļ�
 */

#pragma once

#include "State.h"
#include "Level.h"

// ��ϷԪ���࣬�̳���State�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������ϷԪ���࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class GameElement : public State {
public:
	GameElement() : picture_file_name_(nullptr), mesh_(nullptr), texture_(nullptr) {}
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	virtual ~GameElement() {}
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
