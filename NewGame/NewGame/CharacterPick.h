/**
 * Project:      NewGame
 * File Name:    CharacterPick.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      ����ѡ����ͷ�ļ�
 */

#pragma once

#include "GameState.h"
#include "System.h"

using namespace std;

// ����ѡ���࣬��ʵ����
class CharacterPick : public GameState {
public:
	CharacterPick(string picture) : 
			picture_(picture), 
			mesh_(nullptr), 
			texture_(nullptr) {}

	CharacterPick() : picture_(nullptr), mesh_(nullptr), texture_(nullptr) {}

	~CharacterPick() {}

	void Load() override;

	void Reset() override;

	void Process() override;

	void Unload() override;

private:
	string picture_;
	AEGfxVertexList* mesh_;
	AEGfxTexture* texture_;
};
