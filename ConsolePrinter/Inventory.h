#pragma once
#include "ItemStack.h"
#include <list>

using namespace std;

class Inventory {
	list<ItemStack*> itemStacks;
	int inv_capacity;	//����������

public:
	bool AddItem(Item*, int);	//�򱳰��м�����Ӧ��������Ʒ,����򷵻�false
	bool AddItemStack(ItemStack*);	//�򱳰��м�����Ʒ��,����򷵻�false

	ItemStack* GetStackAt(int index);	//��ȡ��Ӧλ�õ���Ʒ��,������size�򷵻�һ��nullptr

	int GetAmountOf(Item*);	//ͳ�Ʋ����ر�����ĳ��Ʒ������
	int GetStacksNum();	//���ر��������е���Ʒ����
	int GetCapacity();	//���ر���������

	void Check();	//�����������Ʒ����Ϊ0����Ʒ��
	void Sort();	//�Ա����е���Ʒ������������

	Inventory(int);

};