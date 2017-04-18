/* Project:      NewGame
 * File Name:    GameStateManager.h
 * Author:       Atlas Shen
 * Date:         2017/4/16
 * Purpose:      ��Ϸ״̬��������ͷ�ļ�
 */

#pragma once

#include "GameState.h"

//------------------------------------------------------------------------------
// Typedef:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

enum GameStates {
	MENU,
	BACKGROUND_STORY,
	CHARACTER_PICK,
	LEVEL1_PREFACE,
	LEVEL1,
	LEVEL2_PREFACE,
	LEVEL2,
	LEVEL3_PREFACE,
	LEVEL3,
	PRIZE,
	ENDING,
	GAME_OVER,
	NUM_OF_GAME_STATES
};

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Classes:
//------------------------------------------------------------------------------

// GameStateManager���ʵ����ȫֻ��Ϊ�˷�װ������ص�״̬������Ա����������Ϊ����Ա������
// ������ĳ�Ա����static�ģ�static��Ա�����൱��ȫ�ֱ�����static��Ա�����൱��ȫ�ֺ���
// GameStateManeger�಻���������ɶ���ʵ����
class GameStateManager {
public:
	// ��ʼ����Ϸ״̬������
	static void Initialize();

	// �˳���Ϸ״̬������
	static void Exit();

	// ����ָ��ǰ��Ϸ״̬��ָ��
	static GameState* GetGameState() {
		return *game_state_pointer_;
	}

	// �Ƿ�����һ����Ϸ״̬
	static bool HaveNextGameState() {
		return *game_state_pointer_ != game_state_[GAME_OVER];
	}

	// �ѵ�ǰ��Ϸ״̬����Ϊ��һ��״̬��������HaveNextGameState()����true������µ��ã�
	static void NextGameState() {
		++game_state_pointer_;
	}

	// ֻ���ڵ�ǰ״̬ΪLevel1����Level2����Level3ʱ���ܵ��øú���
	// �ӵ�һ�����¿�ʼ�������ڵ�ǰ״ִ̬��Free()��Unload()���ٰѵ�ǰ״̬��ΪLevel1��
	static void RestartFromBeginning();

	// ֻ���ڵ�ǰ״̬ΪLevel1����Level2����Level3ʱ���ܵ��øú���
	// �ӵ�ǰ�����¿�ʼ�����ڵ�ǰ״ִ̬��Free()���ٴ�ͷ��ʼִ�и�״̬��
	static void RestartFromCurrentLevel();

	// �Ƴ���Ϸ
	static void Quit();

	// ��ͣ��ǰ״̬
	static void Pause();

	// ������ǰ״̬
	static void Resume();

private:
	static GameState* game_state_[NUM_OF_GAME_STATES];
	static GameState** game_state_pointer_;
};

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
