/**
 * Project:      NewGame
 * File Name:    Wall.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      ǽ����ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

// ǽ���࣬��ֱ�����ɶ���
class Wall : public GameElement {
public:
	Wall() {}
	Wall(int size, const Position position) : GameElement(size, position) {}
	~Wall() {}

	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;
private:

};
