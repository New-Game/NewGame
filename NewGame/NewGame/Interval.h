/**
 * Project:      NewGame
 * File Name:    Interval.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      间隔类头文件
 */

#pragma once

#include <iostream>
#include "GameState.h"
#include "System.h"

// 间隔类，多实例类，实例化出：
// 游戏前序、背景故事、关卡1前序、关卡1后续、关卡2前序、关卡2后续、关卡3前序、关卡3后续、奖励环节、游戏后续 这些状态
class Interval : public GameState {
public:
	~Interval() {}

	void Load() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Interval: Load." << endl;
		}
	}

	void Initialize() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Interval: Initialize." << endl;
		}
	}

	void Draw() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Interval: Draw." << endl;
		}
	}

	void Process() override;

	void Free() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Interval: Free." << endl;
		}
	}

	void Unload() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << "Interval: Unload." << endl;
		}
	}

private:

};
