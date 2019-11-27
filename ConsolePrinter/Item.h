#pragma once
#include "Effect.h"

class Role;

class Item {
protected:
	const char* name;	//��Ʒ������
	const char* description;	//��Ʒ������
public:
	const int maxStack;	//���ѵ�����

public:
	Item(const char* _name, const char* _description, int _maxStack);
	char* GetName();
	char* GetDesc();

	virtual void OnUsed(Role* target);
	virtual int GetType();

	bool EqualsTo(Item& item);
	bool operator==(Item&);
};

