/**
 * Project:      NewGame
 * File Name:    System.h
 * Author:       Atlas Shen
 * Date:         2017/4/15
 * Purpose:      系统管理器头文件
 */

#pragma once

#include "AEEngine.h"
#include <Windows.h>

// System类的实现完全只是为了封装与它相关的状态量（成员变量）和行为（成员函数）
// 因此它的成员都是static的，static成员变量相当于全局变量，static成员函数相当于全局函数
// System类不能用于生成对象（实例）
class System {
public:
	// 系统初始化函数
	static void Start(HINSTANCE, int);

	// 系统退出函数
	static void End();

	// 返回游戏帧率值
	static unsigned GetFrameRate() {
		return frame_rate_;
	}

	// 返回AE系统初始化信息的结构体
	static AESysInitInfo& GetAESysInitInfo() {
		return sys_init_info_;
	}

	// 返回当前窗口实例
	static HINSTANCE& GetHInstance() {
		return instance_;
	}

	// 返回当前窗口句柄
	static HWND& GetHandle() {
		return handle_;
	}

private:
	// 窗口宽度
	static const int window_width_ = 1016;

	// 窗口高度（要把标题栏的高度考虑进去）
	static const int window_height_ = 640;
	
	// 游戏帧率
	static const unsigned frame_rate_ = 120;

	// AE系统初始化信息的结构体
	static AESysInitInfo sys_init_info_;

	// Window Class窗口类
	static WNDCLASS win_class_;

	// 当前实例
	static HINSTANCE instance_;

	// 当前窗口句柄
	static HWND handle_;

	//// 生成一个文件流对象，用来和AE控制台输出流相连
	//static std::ofstream console_out_;

	//// 保存cout被重定向前的流对象缓冲指针，之后可用于恢复该流对象缓冲指针
	//static std::streambuf* streambuf_pointer_;
};
