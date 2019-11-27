#pragma once
#include "Item.h"

class Role;

class ItemStack {
public:
	Item* item;	//物品堆中的物品

private:
	int amount;	//物品堆中物品的数量

public:
	int SetAmount(int a);	//设置数量, 返回溢出的数量, 无溢出时返回0
	int AddAmount(int a);	//增加数量, 返回溢出的数量, 无溢出时返回0
	int GetAmount();
	void Use(Role*);

	ItemStack(Item*);
	ItemStack(Item*,int);
};