/* Project:      NewGame
 * File Name:    GameState.cpp
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      游戏状态类实现文件
 */

#include "GameState.h"

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

// 必须提供纯虚析构函数的定义，否则链接时会出问题
// 这个定义是必需的，因为虚析构函数工作的方式是：
// 最底层的派生类的析构函数最先被调用，然后各个基类的析构函数被调用。
// 这就是说，即使是抽象类，编译器也会产生对~GameState()的调用，所以要保证为它提供函数体
GameState::~GameState() {}

void Menu::Load() {}
void Menu::Initialize() {}
void Menu::Update() {}
void Menu::Draw() {}
void Menu::Free() {}
void Menu::Unload() {}

void BackgroundStory::Load() {}
void BackgroundStory::Initialize() {}
void BackgroundStory::Update() {}
void BackgroundStory::Draw() {}
void BackgroundStory::Free() {}
void BackgroundStory::Unload() {}

void CharacterPick::Load() {}
void CharacterPick::Initialize() {}
void CharacterPick::Update() {}
void CharacterPick::Draw() {}
void CharacterPick::Free() {}
void CharacterPick::Unload() {}

void LevelPreface::Load() {}
void LevelPreface::Initialize() {}
void LevelPreface::Update() {}
void LevelPreface::Draw() {}
void LevelPreface::Free() {}
void LevelPreface::Unload() {}

void Prize::Load() {}
void Prize::Initialize() {}
void Prize::Update() {}
void Prize::Draw() {}
void Prize::Free() {}
void Prize::Unload() {}

void Ending::Load() {}
void Ending::Initialize() {}
void Ending::Update() {}
void Ending::Draw() {}
void Ending::Free() {}
void Ending::Unload() {}

void GameOver::Load() {}
void GameOver::Initialize() {}
void GameOver::Update() {}
void GameOver::Draw() {}
void GameOver::Free() {}
void GameOver::Unload() {}

//------------------------------------------------------------------------------
// Private Member Functions:
//------------------------------------------------------------------------------
