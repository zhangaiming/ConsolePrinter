#pragma once
#include "Effect.h"

class Role;

class Item {
protected:
	const char* name;	//物品的名称
	const char* description;	//物品的描述
public:
	const int maxStack;	//最大堆叠数量

public:
	Item(const char* _name, const char* _description, int _maxStack);
	char* GetName();
	char* GetDesc();

	virtual void OnUsed(Role* target);
	virtual int GetType();

	bool EqualsTo(Item& item);
	bool operator==(Item&);
};

