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
	Interval() : GameState() {}

	Interval(string name) : GameState(name) {}

	~Interval() {}

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

	void Draw() override {
		if (System::GetAESysInitInfo().mCreateConsole) {
			cout << name_ + ": Draw." << endl;
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
