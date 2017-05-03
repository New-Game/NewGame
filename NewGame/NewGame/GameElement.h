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

using namespace std;

// ��ϷԪ���࣬�̳���State�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������ϷԪ���࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class GameElement : public State {
public:
	GameElement() : picture_file_name_(nullptr), mesh_(nullptr), texture_(nullptr) {}
	virtual ~GameElement() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	string picture_file_name_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
