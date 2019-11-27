#pragma once

enum class EffectType {
	PLUS_CURHP = 0,	//当前血量_加减
	MUL_CURHP,	//当前血量_乘除
	PLUS_MAXHP,	//最大血量_加减
	MUL_MAXHP,	//最大血量_乘除

	PLUS_ATK,	//攻击力_加减
	MUL_ATK,	//攻击力_乘除

	PLUS_DEF,	//防御力_加减
	MUL_DEF,	//防御力_乘除

	PLUS_SPD,	//速度_加减
	MUL_SPD,	//速度_乘除
};

class Effect {
	EffectType effectType;	//效果类型
	float intensity;	//效果的强度

public:
	Effect(EffectType e, float i) :effectType(e), intensity(i) {}
	EffectType GetType();
	float GetIntensity();
};