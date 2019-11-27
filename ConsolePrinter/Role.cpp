#include "Role.h"

Role::Role(int inv_capacity, string* _name)
{
	attribute = new Attribute();
	effectManager = new EffectManager(this);
	buffManager = new BuffManager(this);
	inventory = new Inventory(inv_capacity);
	skillManager = new SkillManager(this, 10);
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

SkillManager* Role::GetSkillManager()
{
	SkillManager* result(skillManager);
	return result;
}

string* Role::GetName()
{
	return name;
}
