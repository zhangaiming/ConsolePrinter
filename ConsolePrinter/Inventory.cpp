#include "Inventory.h"

bool Inventory::AddItem(Item* item, int amount)
{
	while (amount > 0) {
		if (amount > item->maxStack) {
			ItemStack* temp = new ItemStack(item, item->maxStack);
			amount -= item->maxStack;
			if (!AddItemStack(temp)) {
				//�������ʧ���򷵻�
				return false;
			}
		}
		else {
			ItemStack* temp = new ItemStack(item, amount);
			amount = 0;
			if (!AddItemStack(temp)) {
				//�������ʧ���򷵻�
				return false;
			}
			return 1;
		}
	}

	
	
}
#include <iostream>
bool Inventory::AddItemStack(ItemStack* stack)
{
	//�ж���Ŀ���Ƿ���
	//����Ŀ������,�����Ƿ�����Ӧ����Ʒ�����п�λ
	//����Ŀ��δ��,ֱ�����,Ȼ������

	Sort();

	Item* item = stack->item;
	int amount = stack->GetAmount();

	if (GetStacksNum() >= inv_capacity) {
		//��
		
		if (GetAmountOf(stack->item) % stack->item->maxStack != 0) {
			//���п�λ
			for (int i = 0; i < GetStacksNum(); i++) {
				
				if (GetStackAt(i)->item->EqualsTo(*item)) {
					if (GetStackAt(i)->AddAmount(amount) <= 0) {
						//�����Ӻ������,�򷵻�true;
						return true;
					}
					else {
						//�����Ӻ����,������Ѱ;
						continue;
					}
				}
				else {
					continue;
				}
			}
		}
		else {
			//û�п�λ
			return false;
		}
	}
	else {
		//����δ��
		itemStacks.push_back(stack);
		Sort();
		return true;
	}

	return false;
}

bool Inventory::DropItem(Item* item, int amount)
{
	int a = GetAmountOf(item);
	if (a > 0) {
		int i = 0;
		while (i++ < GetCapacity() && amount > 0) {
			ItemStack* temp = GetStackAt(i);
			if (temp->item == item) {
				if (temp->GetAmount() < temp->item->maxStack) {
					if (amount >= temp->GetAmount()) {
						amount -= temp->GetAmount();
						temp->SetAmount(0);
					}
					else {
						temp->AddAmount(-amount);
						amount -= temp->GetAmount();
					}
					break;
				}
				else {
					if (amount >= temp->GetAmount()) {
						amount -= temp->GetAmount();
						temp->SetAmount(0);
					}
					else {
						temp->AddAmount(-amount);
						amount -= temp->GetAmount();
					}
				}
			}
		}

		Sort();
		if (amount > 0)
			return true;
	}
	return false;
}

ItemStack* Inventory::GetStackAt(int index)
{
	Check();
	if(index >= itemStacks.size())
		//����±����
		return nullptr;

	int i = 0;

	for (list<ItemStack*>::iterator iter = itemStacks.begin(); iter != itemStacks.end(); iter++) {
		if (i == index)
			return (*iter);
		else
			i++;
	}
}

int Inventory::GetAmountOf(Item* item)
{
	Check();
	int result = 0;
	for (int i = 0; i < itemStacks.size(); i++) {
		if (GetStackAt(i)->item ->EqualsTo(*item)) {
			result += GetStackAt(i)->GetAmount();
		}
	}
	return result;
}

int Inventory::GetStacksNum()
{
	return itemStacks.size();
}

int Inventory::GetCapacity()
{
	return inv_capacity;
}

void Inventory::Check()
{
	for (list<ItemStack*>::iterator iter = itemStacks.begin(); iter != itemStacks.end(); ) {
		if ((*iter)->GetAmount() == 0 || (*iter) == nullptr)
			itemStacks.erase(iter++);
		else
			iter++;
	}
}

bool Contain(list<Item*> l, Item* item);

void Inventory::Sort()
{
	Check();

	list<ItemStack*> result;
	list<Item*> solvedItems;
	int _amount = 0;

	for (int i = 0; i < itemStacks.size(); i++) {
		Item* solving = GetStackAt(i)->item;
		bool isSolved = Contain(solvedItems, solving);
		if (isSolved) {
			//����ѱ�����,���ж���һ��Ʒ
			continue;
		}

		solvedItems.push_back(solving);

		for (int j = i; j < itemStacks.size(); j++) {
			if (GetStackAt(j)->item->EqualsTo(*solving)) {
				//����ǵ�ǰ��Ʒ
				_amount += GetStackAt(j)->GetAmount();
			}
		}

		while (_amount > 0){
			int max_stack = solving->maxStack;
			if (_amount > max_stack) {
				ItemStack* temp = new ItemStack(solving, max_stack);
				_amount -= max_stack;
				result.push_back(temp);
			}
			else {
				ItemStack* temp = new ItemStack(solving, _amount);
				_amount = 0;
				result.push_back(temp);
			}
		} 

	}

	itemStacks.clear();
	itemStacks = result;
}

Inventory::Inventory(int capacity)
{
	inv_capacity = capacity;
}

bool Contain(list<Item*> l, Item* item) {
	bool result = false;
	for (list<Item*>::iterator iter = l.begin(); iter != l.end(); iter++) {
		if (item->EqualsTo(*(*iter)))
			result = true;
	}
	return result;
}