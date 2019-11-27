#pragma once

enum class EffectType {
	PLUS_CURHP = 0,	//��ǰѪ��_�Ӽ�
	MUL_CURHP,	//��ǰѪ��_�˳�
	PLUS_MAXHP,	//���Ѫ��_�Ӽ�
	MUL_MAXHP,	//���Ѫ��_�˳�

	PLUS_ATK,	//������_�Ӽ�
	MUL_ATK,	//������_�˳�

	PLUS_DEF,	//������_�Ӽ�
	MUL_DEF,	//������_�˳�

	PLUS_SPD,	//�ٶ�_�Ӽ�
	MUL_SPD,	//�ٶ�_�˳�
};

class Effect {
	EffectType effectType;	//Ч������
	float intensity;	//Ч����ǿ��

public:
	Effect(EffectType e, float i) :effectType(e), intensity(i) {}
	EffectType GetType();
	float GetIntensity();
};