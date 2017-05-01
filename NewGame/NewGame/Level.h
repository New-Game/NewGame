/**
 * Project:      NewGame
 * File Name:    Level.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      关卡类头文件
 */

#pragma once

#include <iostream>
#include "GameState.h"
#include "System.h"

using namespace std;

// 关卡类，多实例类，每个关卡都是它的一个对象
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
