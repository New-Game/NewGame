/**
 * Project:      NewGame
 * File Name:    System.h
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ϵͳ������ͷ�ļ�
 */

#pragma once

#include "AEEngine.h"
#include <Windows.h>

// System���ʵ����ȫֻ��Ϊ�˷�װ������ص�״̬������Ա����������Ϊ����Ա������
// ������ĳ�Ա����static�ģ�static��Ա�����൱��ȫ�ֱ�����static��Ա�����൱��ȫ�ֺ���
// System�಻���������ɶ���ʵ����
class System {
public:
	// ϵͳ��ʼ������
	static void Start(HINSTANCE, int);

	// ϵͳ�˳�����
	static void End();

	// ������Ϸ֡��ֵ
	static unsigned GetFrameRate() {
		return frame_rate_;
	}

	// ����AEϵͳ��ʼ����Ϣ�Ľṹ��
	static AESysInitInfo& GetAESysInitInfo() {
		return sys_init_info_;
	}

	// ���ص�ǰ����ʵ��
	static HINSTANCE& GetHInstance() {
		return instance_;
	}

	// ���ص�ǰ���ھ��
	static HWND& GetHandle() {
		return handle_;
	}

private:
	// ���ڿ��
	static const int window_width_ = 1016;

	// ���ڸ߶ȣ�Ҫ�ѱ������ĸ߶ȿ��ǽ�ȥ��
	static const int window_height_ = 640;
	
	// ��Ϸ֡��
	static const unsigned frame_rate_ = 120;

	// AEϵͳ��ʼ����Ϣ�Ľṹ��
	static AESysInitInfo sys_init_info_;

	// Window Class������
	static WNDCLASS win_class_;

	// ��ǰʵ��
	static HINSTANCE instance_;

	// ��ǰ���ھ��
	static HWND handle_;

	//// ����һ���ļ�������������AE����̨���������
	//static std::ofstream console_out_;

	//// ����cout���ض���ǰ�������󻺳�ָ�룬֮������ڻָ��������󻺳�ָ��
	//static std::streambuf* streambuf_pointer_;
};
