#include "Role.h"

Role::Role(int inv_capacity, string _name)
{
	attribute = new Attribute(20, 5, 5, 5, 20);
	effectManager = new EffectManager(this);
	buffManager = new BuffManager(this);
	inventory = new Inventory(inv_capacity);
	equipmentBar = new EquipmentBar(this);
	name = _name;
}

void Role::ApplyEffect(Effect* effect)
{
	effectManager->Apply(effect);
}

void Role::AttachBuff(Buff* buff)
{
	buffManager->Attach(buff);
}

Attribute* Role::GetAttribute()
{
	return attribute;
}

BUFFLIST* Role::GetBuffList()
{
	return &buffManager->GetBuffList();
}

Inventory* Role::GetInventory()
{
	return inventory;
}

EquipmentBar* Role::GetEquipmentBar()
{
	return equipmentBar;
}

string Role::GetName()
{
	return name;
}
