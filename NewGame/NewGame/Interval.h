/**
 * Project:      NewGame
 * File Name:    Interval.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �����ͷ�ļ�
 */

#pragma once

#include "GameState.h"
#include "System.h"

using namespace std;

// ����࣬��ʵ���࣬ʵ��������
// ��Ϸǰ�򡢱������¡��ؿ�1ǰ�򡢹ؿ�1�������ؿ�2ǰ�򡢹ؿ�2�������ؿ�3ǰ�򡢹ؿ�3�������������ڡ���Ϸ���� ��Щ״̬
class Interval : public GameState {
public:
	Interval(string picture) : 
			picture_(picture), 
			mesh_(nullptr), 
			texture_(nullptr) {}

	Interval() : picture_(nullptr), mesh_(nullptr), texture_(nullptr) {}

	~Interval() {}
	
	void Load() override;

	void Reset() override;

	void Process() override;

	void Unload() override;

private:
	string picture_; // ����������ͼƬ���ļ���
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;

};
