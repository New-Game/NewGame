/* Project:      NewGame
 * File Name:    GameState.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      游戏状态类实现文件
 */

#include <iostream>
#include "GameState.h"
#include "System.h"

using namespace std;

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Memeber Functions:
//------------------------------------------------------------------------------

// CharacterPick成员函数
void CharacterPick::Load() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "CharacterPick: Load." << endl;
	}
}

void CharacterPick::Initialize() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "CharacterPick: Initialize." << endl;
	}
}

void CharacterPick::Draw() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "CharacterPick: Draw." << endl;
	}
}

void CharacterPick::Process() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "CharacterPick: Process." << endl;
	}
}

void CharacterPick::Free() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "CharacterPick: Free." << endl;
	}
}

void CharacterPick::Unload() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "CharacterPick: Unload." << endl;
	}
}

// Interval成员函数
void Interval::Load() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Interval: Load." << endl;
	}
}

void Interval::Initialize() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Interval: Initialize." << endl;
	}
}

void Interval::Draw() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Interval: Draw." << endl;
	}
}

void Interval::Process() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Interval: Process." << endl;
	}
}

void Interval::Free() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Interval: Free." << endl;
	}
}

void Interval::Unload() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Interval: Unload." << endl;
	}
}

// Level成员函数
void Level::Load() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Level: Load." << endl;
	}
}

void Level::Initialize() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Level: Initialize." << endl;
	}
}

void Level::Draw() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Level: Draw." << endl;
	}
}

void Level::Process() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Level: Process." << endl;
	}
}

void Level::Free() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Level: Free." << endl;
	}
}

void Level::Unload() {
	if (System::GetAESysInitInfo().mCreateConsole) {
		cout << "Level: Unload." << endl;
	}
}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
