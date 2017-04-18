/* Project:      NewGame
 * File Name:    GameState.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      ��Ϸ״̬��ͷ�ļ�
 */

#pragma once

#include "State.h"

//------------------------------------------------------------------------------
// Typedef:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Classes:
//------------------------------------------------------------------------------

// ��Ϸ״̬�࣬�̳���State�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������Ϸ״̬�࣬���г�Ա������Ϊ���麯��
class GameState : public State {
public:
	friend class GameStateManager; // ��Ԫ��������public��private��protected�ж�����
protected:
	virtual ~GameState() = 0;
};

// ����Ϊ�������Ϸ״̬��

// �˵��࣬��ʵ����
class Menu : public GameState {
public:
	~Menu() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// ���������࣬��ʵ����
class BackgroundStory : public GameState {
public:
	~BackgroundStory() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// ����ѡ���࣬��ʵ����
class CharacterPick : public GameState {
public:
	~CharacterPick() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// �ؿ�ǰ���࣬��ʵ���࣬ÿ���ؿ�ǰ������������һ������
class LevelPreface : public GameState {
public:
	~LevelPreface() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// �ؿ��࣬��ʵ���࣬ÿ���ؿ���������һ������
class Level : public GameState {
public:
	~Level() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// �����࣬��ʵ����
class Prize : public GameState {
public:
	~Prize() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;
	
private:

};

// ��β�����࣬��ʵ����
class Ending : public GameState {
public:
	~Ending() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

// ���ս�β�࣬��ʵ����
class GameOver : public GameState {
public:
	~GameOver() {}
	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

private:

};

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
