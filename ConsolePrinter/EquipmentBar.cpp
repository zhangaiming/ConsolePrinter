#include "EquipmentBar.h"
#include "ItemStack.h"
#include "Equipment.h"
#include "Role.h"

EquipmentBar::EquipmentBar(Role* owner)
{
	role = owner;
	hat = nullptr;
	cloth = nullptr;
	glove = nullptr;
	pants = nullptr;
	shoes = nullptr;
}

ItemStack* EquipmentBar::GetEquipment(int _which)
{
	switch (_which) {
	case HAT:
		return hat;
		break;
	case CLOTH:
		return cloth;
		break;
	case GLOVE:
		return glove;
		break;
	case PANTS:
		return pants;
		break;
	case SHOES:
		return shoes;
		break;
	}
}

void EquipmentBar::Unequip(int _which)
{
	switch (_which) {
	case HAT:
		if (hat != nullptr) {
			if ((int)hat->item->GetType() >= 10000) {
				((Equipment*)hat->item)->OnSelfUnequiped(role);
				this->hat = nullptr;
			}
		}
		break;
	case CLOTH:
		if (cloth != nullptr) {
			if ((int)cloth->item->GetType() >= 10000) {
				((Equipment*)cloth->item)->OnSelfUnequiped(role);
				this->cloth = nullptr;
			}
		}
		break;
	case GLOVE:
		if (glove != nullptr) {
			if ((int)glove->item->GetType() >= 10000) {
				((Equipment*)glove->item)->OnSelfUnequiped(role);
				this->glove = nullptr;
			}
		}
		break;
	case PANTS:
		if (pants != nullptr) {
			if ((int)pants->item->GetType() >= 10000) {
				((Equipment*)pants->item)->OnSelfUnequiped(role);
				this->pants = nullptr;
			}
		}
		break;
	case SHOES:
		if (shoes != nullptr) {
			if ((int)shoes->item->GetType() >= 10000) {
				((Equipment*)shoes->item)->OnSelfUnequiped(role);
				this->shoes = nullptr;
			}
		}
		break;
	}
}

void EquipmentBar::Equip(ItemStack* equip)
{
	if ((int)equip->item->GetType() >= 10000) {
		Equipment* e = (Equipment*)equip->item;
		
		switch ((int)e->GetEType()) {
		case HAT:
			if (hat != nullptr)
				Unequip(HAT);
			hat = new ItemStack(equip->item, equip->GetAmount());
			e->OnUsed(role);
			break;
		case CLOTH:
			if (cloth != nullptr)
				Unequip(CLOTH);
			cloth = new ItemStack(equip->item, equip->GetAmount());
			e->OnUsed(role);
			break;
		case PANTS:
			if (pants != nullptr)
				Unequip(PANTS);
			pants = new ItemStack(equip->item, equip->GetAmount());
			e->OnUsed(role);
			break;
		case GLOVE:
			if (glove != nullptr)
				Unequip(GLOVE);
			glove = new ItemStack(equip->item, equip->GetAmount());
			e->OnUsed(role);
			break;
		case SHOES:
			if (shoes != nullptr)
				Unequip(SHOES);
			shoes = new ItemStack(equip->item, equip->GetAmount());
			e->OnUsed(role);
			break;
		}

	}
}
