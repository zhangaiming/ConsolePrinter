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

	virtual void OnEffectApply(Role* applier, Role* target);	//��װ����װ���Ľ�ɫ��Ӧ��effectʱ���ô��¼�
	virtual void OnBuffAttach(Role* target, Buff* buff);	//��װ����װ���Ľ�ɫ������buffʱ���ô��¼�
	virtual void OnUsed(Role* target);	//����װ��ʱ���ô��¼�
	virtual void OnSelfUnequiped(Role* target);	//����ж��ʱ���ô��¼�

	virtual int GetType();
	EquipmentType GetEType();
};