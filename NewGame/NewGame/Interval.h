/**
 * Project:      NewGame
 * File Name:    Interval.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �����ͷ�ļ�
 */

#pragma once

#include <iostream>
#include "GameState.h"
#include "System.h"

using namespace std;

// ����࣬��ʵ���࣬ʵ��������
// ��Ϸǰ�򡢱������¡��ؿ�1ǰ�򡢹ؿ�1�������ؿ�2ǰ�򡢹ؿ�2�������ؿ�3ǰ�򡢹ؿ�3�������������ڡ���Ϸ���� ��Щ״̬
class Interval : public GameState {
public:
	Interval() : GameState(), picture_file_name_(nullptr), mesh_(nullptr), texture_(nullptr) {}
	Interval(string name, string picture_file_name) : GameState(name), 
	                                                  picture_file_name_(picture_file_name), 
	                                                  mesh_(nullptr),
	                                                  texture_(nullptr) {}
	~Interval() {}
	void Load() override;
	void Initialize() override;
	void Process() override;
	void Free() override;
	void Unload() override;

private:
	string picture_file_name_; // ����������ͼƬ���ļ���
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
