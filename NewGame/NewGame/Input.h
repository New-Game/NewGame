/**
 * Project:      NewGame
 * File Name:    Input.h
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ����ģ��ͷ�ļ�
 */

#pragma once

#include <Windows.h>
#include "System.h"

enum Key {
	KEY_ENTER,
//	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_ESC,
	KEY_A,
	KEY_S,
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
	//
	static LRESULT CALLBACK MainHandle(HWND, UINT, WPARAM, LPARAM);

	static INT_PTR CALLBACK HandleForExit(HWND, UINT, WPARAM, LPARAM);

	static INT_PTR CALLBACK HandleForResume(HWND, UINT, WPARAM, LPARAM);
	
	static INT_PTR CALLBACK HandleForRestart(HWND, UINT, WPARAM, LPARAM);

	static bool GetPressedKey(enum Key key) {
		return pressed_key_[key];
	}

	// ��������key_pressed[]����
	static void ResetPressedKey() {
		memset(pressed_key_, false, NUM_OF_KEY);
	}

private:
	// ������ȫ�ֱ������������Զ�ȫΪfalse����˲����صس�ʼ��
	static bool pressed_key_[NUM_OF_KEY];
};
