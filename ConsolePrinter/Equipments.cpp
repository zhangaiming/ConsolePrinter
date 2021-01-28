#include "Equipments.h"

AHat::AHat() : Equipment("Hat", "这是一顶帽子 [可装备]", EquipmentType::Hat)
{
	
}

int AHat::GetType()
{
	return 10001;
}

