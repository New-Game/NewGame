/**
 * Project:      NewGame
 * File Name:    Input.h
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ����ģ��ͷ�ļ�
 */

#pragma once

#include <Windows.h>
#include <cstdlib>
#include "System.h"

enum Key {
	KEY_ENTER,
	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_ESC,
	KEY_A,
	KEY_S,
	KEY_Y,
	KEY_N,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	NUM_OF_KEY
};

// Input���ʵ����ȫֻ��Ϊ�˷�װ������ص�״̬������Ա����������Ϊ����Ա������
// ������ĳ�Ա����static�ģ�static��Ա�����൱��ȫ�ֱ�����static��Ա�����൱��ȫ�ֺ���
// Input�಻���������ɶ���ʵ����
class Input {
public:
	// ������Ӧ����Ļص�����
	static LRESULT CALLBACK Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	static bool GetPressedKey(enum Key key) {
		return pressed_key_[key];
	}

	// ��������key_pressed[]����
	static void ResetPressedKey() {
		memset(pressed_key_, false, NUM_OF_KEY);

		// дlog
		System::GetLogFile() << "Input: Reset" << std::endl;
	}

private:
	// ������ȫ�ֱ������������Զ�ȫΪfalse����˲����صس�ʼ��
	static bool pressed_key_[NUM_OF_KEY];
};
