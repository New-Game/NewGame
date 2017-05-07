/**
 * Project:      NewGame
 * File Name:    GameStateManager.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      ��Ϸ״̬��������ͷ�ļ�
 */

#pragma once

#include "GameState.h"

enum GameStates {
	GAME_PREFACE,
	BACKGROUND_STORY,
	CHARACTER_PICK,
	LEVEL1_PREFACE,
	LEVEL1,
	LEVEL1_ENDING,
	LEVEL2_PREFACE,
	LEVEL2,
	LEVEL2_ENDING,
	LEVEL3_PREFACE,
	LEVEL3,
	LEVEL3_ENDING,
	PRIZE,
	GAME_ENDING,
	NUM_OF_GAME_STATES
};

// GameStateManager���ʵ����ȫֻ��Ϊ�˷�װ������ص�״̬������Ա����������Ϊ����Ա������
// ������ĳ�Ա����static�ģ�static��Ա�����൱��ȫ�ֱ�����static��Ա�����൱��ȫ�ֺ���
// GameStateManeger�಻���������ɶ���ʵ����
class GameStateManager {
public:
	// ��ʼ����Ϸ״̬������
	static void Start();

	// �˳���Ϸ״̬������
	static void End();

	// ����ָ��ǰ��Ϸ״̬��ָ��
	static GameState* GetGameState() {
		return *game_state_pointer_;
	}

	// �Ƿ�����һ����Ϸ״̬
	static bool HasNextGameState() {
		return game_state_pointer_ != game_state_ + GAME_ENDING;
	}

	// �ѵ�ǰ��Ϸ״̬����Ϊ��һ��״̬��������HasNextGameState()����true������µ��ã�
	static void NextGameState() {
		++game_state_pointer_;
	}

private:
	static GameState* game_state_[NUM_OF_GAME_STATES];
	static GameState** game_state_pointer_;
};
