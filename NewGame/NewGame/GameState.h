/* Project:      NewGame
 * File Name:    GameState.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      ��Ϸ״̬��ͷ�ļ�
 */

#pragma once

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

// ��Ϸ״̬�����࣬��������������Ϸ״̬�࣬���г�Ա������Ϊ���麯��
class GameState {
public:
	virtual ~GameState() = 0;
	virtual void Load() = 0;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Free() = 0;
	virtual void Unload() = 0;

protected:

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
