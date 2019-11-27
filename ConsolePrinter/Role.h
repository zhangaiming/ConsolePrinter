#pragma once
#include "Attribute.h"
#include "EffectManager.h"
#include "BuffManager.h"
#include "Inventory.h"
#include "SkillManager.h"
#include <string>

class Role {
private:
	Attribute* attribute;
	EffectManager* effectManager;
	BuffManager* buffManager;
	Inventory* inventory;
	SkillManager* skillManager;
	string* name;

public:
	Role(int inv_capacity, string* _name);
	void ApplyEffect(Effect* effect);
	void AttachBuff(Buff* buff);

	Attribute* GetAttribute();
	BUFFLIST* GetBuffList();
	Inventory* GetInventory();
	SkillManager* GetSkillManager();
	string* GetName();
};