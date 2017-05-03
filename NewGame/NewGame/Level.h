/**
 * Project:      NewGame
 * File Name:    Level.h
 * Author:       Atlas Shen
 * Date:         2017/4/19
 * Purpose:      关卡类头文件
 */

#pragma once

#include <iostream>
#include "GameState.h"
#include "System.h"
#include "GameElementManager.h"

using namespace std;

// 关卡类，多实例类，每个关卡都是它的一个对象
class Level : public GameState {
public:
	Level() : handle() {}
	Level(string config_file_name) : handle(config_file_name) {}
	~Level() {}

	void Load() override;
	void Initialize() override;
	void Process() override;
	void Free() override;
	void Unload() override;

private:
	GameElementManager handle;
};
