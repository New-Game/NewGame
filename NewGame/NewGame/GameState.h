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
	virtual void Process() = 0;
	bool GetIsReadyForNextGameState() const {
		return is_ready_for_next_game_state_;
	}
	void SetIsReadyForNextGameState() {
		is_ready_for_next_game_state_ = true;
	}
protected:
	bool is_ready_for_next_game_state_;
	GameState() : is_ready_for_next_game_state_(false) {}
	GameState(GameState& game_state) {
		is_ready_for_next_game_state_ = game_state.GetIsReadyForNextGameState();
	}
	virtual ~GameState() = 0;
};

// ����Ϊ�������Ϸ״̬�࣬������Ϸ״̬���Գ���Ϊ������
// ��һ������״̬�а����ҷ������ѡ�������
// �ڶ�������״̬����ʾ�����Ϣ����Enter���Խ�����һ״̬��
// �����־��ǹؿ�״̬��ÿ���ؿ����ǹؿ����һ������

// ����ѡ���࣬��ʵ����
class CharacterPick : public GameState {
public:
	~CharacterPick() {}
	void Load() override;
	void Initialize() override;
	void Draw() override;
	void Process() override;
	void Free() override;
	void Unload() override;
private:

};

// ����࣬��ʵ���࣬ʵ��������
// ��Ϸǰ�򡢱������¡��ؿ�1ǰ�򡢹ؿ�1�������ؿ�2ǰ�򡢹ؿ�2�������ؿ�3ǰ�򡢹ؿ�3�������������ڡ���Ϸ���� ��Щ״̬
class Interval : public GameState {
public:
	~Interval() {}
	void Load() override;
	void Initialize() override;
	void Draw() override;
	void Process() override;
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
	void Draw() override;
	void Process() override;
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
