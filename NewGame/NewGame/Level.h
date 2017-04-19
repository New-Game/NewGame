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

 // 关卡类，多实例类，每个关卡都是它的一个对象
class Level : public GameState {
public:
	~Level() {}

	void Load() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Level: Load." << endl;
		}
	}

	void Initialize() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Level: Initialize." << endl;
		}
	}

	void Draw() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Level: Draw." << endl;
		}
	}

	void Process() override;

	void Free() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Level: Free." << endl;
		}
	}

	void Unload() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Level: Unload." << endl;
		}
	}

private:

};
