#pragma once
#include "ItemStack.h"
#include <list>

using namespace std;

class Inventory {
	list<ItemStack*> itemStacks;
	int inv_capacity;	//背包的容量

public:
	bool AddItem(Item*, int);	//向背包中加入相应数量的物品,溢出则返回false
	bool AddItemStack(ItemStack*);	//向背包中加入物品堆,溢出则返回false

	ItemStack* GetStackAt(int index);	//获取相应位置的物品堆,若超出size则返回一个nullptr

	int GetAmountOf(Item*);	//统计并返回背包中某物品的数量
	int GetStacksNum();	//返回背包中已有的物品堆数
	int GetCapacity();	//返回背包的容量

	void Check();	//清除背包中物品数量为0的物品堆
	void Sort();	//对背包中的物品进行整理排序

	Inventory(int);

};