#include "Equipments.h"

AHat::AHat() : Equipment("Hat", "����һ��ñ�� [��װ��]", EquipmentType::Hat)
{
	
}

int AHat::GetType()
{
	return 10001;
}

