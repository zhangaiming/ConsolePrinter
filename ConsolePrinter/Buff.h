#pragma once
#include "Effect.h"

class Role;

class Effect;

class Buff {
protected:
	int restTurn;	//ʣ��Ļغ���
	const char* displayName;	//buff������
	const char* description;	//buff������

public:
	Buff(int _turns);
	virtual void OnApply(Role*);	//Ӧ��ʱ����
	virtual void OnAttach(Role*);	//���ӵ���ɫ��ʱ����
	virtual void OnDetach(Role*) = 0;	//�ӽ�ɫ��ȥ��ʱ����
	int GetRestTurn();
};

