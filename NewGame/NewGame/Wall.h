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
	Wall(Rect rect, string picture_file_name) : GameElement(rect, picture_file_name) {}

	Wall() {}

	~Wall() {}

	void Load() override;

	void Update() override;

	void Draw() override;

	void Unload() override;

private:

};
