#pragma once
#include "Item.h"

class Role;
class Buff;
class Effect;

enum class EquipmentType {
	Hat = 0,
	Clothing = 1,
	Gloves = 2,
	Pants = 3,
	Shoes = 4,
};

class Equipment :public Item {
	EquipmentType type;

public:
	Equipment(const char* _name, const char* _description, const EquipmentType& type);

	virtual void OnEffectApply(Role* applier, Role* target);	//当装备此装备的角色被应用effect时调用此事件
	virtual void OnBuffAttach(Role* target, Buff* buff);	//当装备此装备的角色被附加buff时调用此事件
	virtual void OnUsed(Role* target);	//当被装备时调用此事件
	virtual void OnSelfUnequiped(Role* target);	//当被卸下时调用此事件

	virtual int GetType();
	EquipmentType GetEType();
};