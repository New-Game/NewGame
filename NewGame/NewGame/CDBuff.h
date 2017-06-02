/**
* Project:      NewGame
* File Name:    CDBuff.h
* Author:       Atlas
* Date:         2017/6/02
* Purpose:      ������CDBuff��ͷ�ļ�
*/

#pragma once

#include "Buff.h"

class CDBuff : public Buff {
public:
	CDBuff(Rect rect, string picture_file_name) : Buff(rect, picture_file_name) {}
	CDBuff() {}
	~CDBuff() {}

	void Load() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
	void Affect(Character* p_character) override;
private:

};
