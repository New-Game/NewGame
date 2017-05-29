/**
 * Project:      NewGame
 * File Name:    State.h
 * Author:       Atlas Shen
 * Date:         2017/4/18
 * Purpose:      ״̬��ͷ�ļ�
 */

#pragma once

// ״̬�࣬����һ�������ࣨ���ڴ��麯�����������������ɶ��󣬳�Ա����ʹ���麯����ʵ�ֶ�̬
// �൱��һ���ӿڣ�Ϊ������Ϸ���󣨰�����Ϸ״̬����ϷԪ�أ��ṩʵ������ĺ���
class State {
public:
	virtual void Load() = 0;
	virtual void Reset() = 0;
	virtual void Unload() = 0;
protected:
	virtual ~State() {}
};
