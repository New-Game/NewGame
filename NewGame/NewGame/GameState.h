/**
 * Project:      NewGame
 * File Name:    GameState.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      ��Ϸ״̬��ͷ�ļ�
 */

#pragma once

#include <string>
#include "Character.h"

using namespace std;

// ��Ϸ״̬�࣬�̳���State�࣬ͬ�����ǳ����࣬�����������ɶ���
// ��������������Ϸ״̬�࣬��Ա����ʹ���麯����ʵ�ֶ�̬

// ������Ϸ״̬���Գ���Ϊ������
// ��һ������״̬�а����ҷ������ѡ�������
// �ڶ�������״̬����ʾ�����Ϣ����Enter���Խ�����һ״̬��
// �����־��ǹؿ�״̬��ÿ���ؿ����ǹؿ����һ������

class GameState {
public:
	// �޲ι��캯��
	GameState() : 
			is_ready_for_next_game_state_(false), 
			is_ready_for_restart_(false), 
			is_ready_for_exit_(false) {}

	// δд���ƹ��캯������Ϊû����������

	// ����������
	virtual ~GameState() {}

	// ���������ࣨ�����ࣩ��д�� ���麯����ÿ�����඼������д�����������������Ϸ״̬�����з�ʽ

	virtual void Load() = 0;

	virtual void Reset() = 0;

	virtual void Process() = 0;

	virtual void Unload() = 0;

	bool GetIsReadyForNextGameState() const {
		return is_ready_for_next_game_state_;
	}

	bool GetIsReadyForRestart() const {
		return is_ready_for_restart_;
	}

	bool GetIsReadyForExit() const {
		return is_ready_for_exit_;
	}

	// �ڷǹؿ�״̬ʱ����Enter��ʱ���ã�������״̬��������һ״̬
	void SetIsReadyForNextGameState() {
		is_ready_for_next_game_state_ = true;
	}

	// �ڹؿ�״̬ʱ����Backspaceʱ���ã�׼�����¿�ʼ����
	void SetIsReadyForRestart() {
		is_ready_for_restart_ = true;
	}

	// ���Ѿ����½��뱾״̬׼����ʼ����״̬ǰ���ã�����flag��ֵ
	void ResetIsReadyForRestart() {
		is_ready_for_restart_ = false;
	}

	// ���κ�״̬�°���ESC��ʱ���ã�׼���˳���Ϸ
	void SetIsReadyForExit() {
		is_ready_for_exit_ = true;
	}

	static Character* picked_character_;

	//static UINT ID[10];
	//static MCI_OPEN_PARMS mciopen[10];
	//static MCI_PLAY_PARMS mcipaly[10];

protected:
	// ����������Ϸ���̵�flag
	bool is_ready_for_next_game_state_;
	bool is_ready_for_restart_;
	bool is_ready_for_exit_;
};
