/**
 * Project:      NewGame
 * File Name:    Level.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      �ؿ���ͷ�ļ�
 */

#pragma once

#include <iostream>
#include "GameState.h"
#include "System.h"

using namespace std;

// �ؿ��࣬��ʵ���࣬ÿ���ؿ���������һ������
class Level : public GameState {
public:
	Level() : GameState() {}

	explicit Level(string name) : GameState(name) {}

	~Level() {}

	void Load() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << name_ + ": Load." << endl;
		}
	}

	void Initialize() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << name_ + ": Initialize." << endl;
		}
	}

	void Process() override;

	void Free() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << name_ + ": Free." << endl;
		}
	}

	void Unload() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << name_ + ": Unload." << endl;
		}
	}

private:

};
