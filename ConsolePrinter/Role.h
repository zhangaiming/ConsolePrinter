#pragma once
#include "Attribute.h"
#include "EffectManager.h"
#include "BuffManager.h"
#include "Inventory.h"
#include "EquipmentBar.h"
#include <string>

class BaseAttribute;

class Role {
private:
	Attribute* attribute;
	EffectManager* effectManager;
	BuffManager* buffManager;
	Inventory* inventory;
	EquipmentBar* equipmentBar;
	string name;

public:
	Role(int inv_capacity, string _name);
	void ApplyEffect(Effect* effect);
	void AttachBuff(Buff* buff);

	Attribute* GetAttribute();
	BUFFLIST* GetBuffList();
	Inventory* GetInventory();
	EquipmentBar* GetEquipmentBar();
	string GetName();
};