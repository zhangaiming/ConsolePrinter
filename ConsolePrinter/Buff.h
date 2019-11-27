#pragma once
#include "Effect.h"

class Role;

class Effect;

class Buff {
protected:
	int restTurn;	//剩余的回合数
	const char* displayName;	//buff的名称
	const char* description;	//buff的描述

public:
	Buff(int _turns);
	virtual void OnApply(Role*);	//应用时调用
	virtual void OnAttach(Role*);	//附加到角色上时调用
	virtual void OnDetach(Role*) = 0;	//从角色上去除时调用
	int GetRestTurn();
};

