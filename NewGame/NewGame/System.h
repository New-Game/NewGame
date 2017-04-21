/**
 * Project:      NewGame
 * File Name:    System.h
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      ϵͳ������ͷ�ļ�
 */

#pragma once

#include "AEEngine.h"
#include <fstream>
#include <Windows.h>

// System���ʵ����ȫֻ��Ϊ�˷�װ������ص�״̬������Ա����������Ϊ����Ա������
// ������ĳ�Ա����static�ģ�static��Ա�����൱��ȫ�ֱ�����static��Ա�����൱��ȫ�ֺ���
// System�಻���������ɶ���ʵ����
class System {
public:
	// ϵͳ��ʼ������
	static void Initialize(HINSTANCE, int);

	// ϵͳ�˳�����
	static void Exit();

	// ����AEϵͳ��ʼ����Ϣ�Ľṹ��
	static AESysInitInfo& GetAESysInitInfo() {
		return sys_init_info_;
	}

	// ���ص�ǰ����ʵ��
	static HINSTANCE& GetHInstance() {
		return h_instance_;
	}

	//// ��������дlog���ļ�������
	//static std::ofstream& GetLogFile() {
	//	return log_file_;
	//}

private:
	// AEϵͳ��ʼ����Ϣ�Ľṹ��
	static AESysInitInfo sys_init_info_;

	// Window Class������
	static WNDCLASS win_class_;

	// ��ǰʵ��
	static HINSTANCE h_instance_;

	//// ����һ���ļ������󣬿���ͨ�������ļ�,֮��Ϳ�������ļ���дlog
	//static std::ofstream log_file_;

	// ����һ���ļ�������������AE����̨���������
	static std::ofstream console_out_;

	// ����cout���ض���ǰ�������󻺳�ָ�룬֮������ڻָ��������󻺳�ָ��
	static std::streambuf* streambuf_pointer_;
};
