#include "ItemStack.h"
#include "Role.h"

int ItemStack::SetAmount(int a)
{
	int r = 0;
	if (item != nullptr) {
		if (a <= 0)
			amount = 0;
		else if (a >= item->maxStack) {
			amount = item->maxStack;
			r = (a + amount) - item->maxStack;
		}
		else
			amount = a;
	}

	return r;
}

int ItemStack::AddAmount(int a)
{
	return SetAmount(a + GetAmount());
}

int ItemStack::GetAmount()
{
	return amount;
}

void ItemStack::Use(Role* role)
{
	item->OnUsed(role);
}

ItemStack::ItemStack(Item* _item)
{
	item = _item;
	SetAmount(1);
}

ItemStack::ItemStack(Item* _item, int _amount)
{
	item = _item;
	SetAmount(_amount);
}
