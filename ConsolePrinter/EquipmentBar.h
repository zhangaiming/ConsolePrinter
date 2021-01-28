#pragma once

#define HAT 0
#define CLOTH 1
#define GLOVE 2
#define PANTS 3
#define SHOES 4

class ItemStack;
class Role;

class EquipmentBar {
	Role* role;

	ItemStack* hat;
	ItemStack* cloth;
	ItemStack* glove;
	ItemStack* pants;
	ItemStack* shoes;

public:
	EquipmentBar(Role* owner);

	//HAT = 0, CLOTH = 1, GLOVE = 2, PANTS = 3, SHOES = 4
	ItemStack* GetEquipment(int _which);
	void Unequip(int _which);
	void Equip(ItemStack* equip);

};