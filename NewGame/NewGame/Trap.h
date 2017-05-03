/**
 * Project:      NewGame
 * File Name:    Trap.h
 * Author:       Long
 * Date:         2017/4/18
 * Purpose:      ������ͷ�ļ�
 */

#pragma once

#include "GameElement.h"

// �����࣬�̳���GameElement�࣬ͬ�����ǳ����࣬�����������ɶ���
// �����������������࣬��Ա����ʹ���麯����ʵ�ֶ�̬
class Trap : public GameElement {
public:
	Trap() {}
	virtual ~Trap() {}

	void Load() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Free() override;
	void Unload() override;

protected:
};
