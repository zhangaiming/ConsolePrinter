#pragma once
#include "Item.h"

class Role;

class ItemStack {
public:
	Item* item;	//��Ʒ���е���Ʒ

private:
	int amount;	//��Ʒ������Ʒ������

public:
	int SetAmount(int a);	//��������, �������������, �����ʱ����0
	int AddAmount(int a);	//��������, �������������, �����ʱ����0
	int GetAmount();
	void Use(Role*);

	ItemStack(Item*);
	ItemStack(Item*,int);
};