/**
 * Project:      NewGame
 * File Name:    Level.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ͷ�ļ�
 */

#pragma once

#include <iostream>
#include <list>
#include "GameState.h"
#include "System.h"
#include "GameElement.h"

using namespace std;

// �ؿ��࣬��ʵ���࣬ÿ���ؿ���������һ������
class Level : public GameState {
public:
	Level() : GameState() {}

	explicit Level(string name) : GameState(name) {}

	~Level() {}

	void Load() override;
	void Initialize() override;
	void Process() override;
	void Free() override;
	void Unload() override;

private:
	void Draw() override;
};
