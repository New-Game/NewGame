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
	~CharacterPick() {}

	void Load() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "CharacterPick: Load." << endl;
		}
	}

	void Initialize() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "CharacterPick: Initialize." << endl;
		}
	}

	void Draw() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "CharacterPick: Draw." << endl;
		}
	}

	void Process() override;

	void Free() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "CharacterPick: Free." << endl;
		}
	}

	void Unload() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "CharacterPick: Unload." << endl;
		}
	}

private:

};
