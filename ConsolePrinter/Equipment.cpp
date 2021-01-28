#include "Equipment.h"

Equipment::Equipment(const char* _name, const char* _description, const EquipmentType& _type) : Item(_name, _description)
{
	type = _type;
}

void Equipment::OnEffectApply(Role* applier, Role* target)
{
}

void Equipment::OnBuffAttach(Role* target, Buff* buff)
{
}

void Equipment::OnUsed(Role* target)
{
}

void Equipment::OnSelfUnequiped(Role* target)
{
}

int Equipment::GetType()
{
	return 10000;
}

EquipmentType Equipment::GetEType()
{
	return type;
}
