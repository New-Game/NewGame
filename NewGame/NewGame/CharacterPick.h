/**
 * Project:      NewGame
 * File Name:    CharacterPick.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      ����ѡ����ͷ�ļ�
 */

#pragma once

#include <iostream>
#include "GameState.h"
#include "System.h"

using namespace std;

// ����ѡ���࣬��ʵ����
class CharacterPick : public GameState {
public:
	CharacterPick() {}
	~CharacterPick() {}

	void Load() override;
	void Initialize() override;
	void Process() override;
	void Free() override;
	void Unload() override;

private:
};
