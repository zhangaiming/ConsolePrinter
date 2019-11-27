#include "Attribute.h"

void Attribute::SetCurHP(int num)
{
	if (num <= 0) {
		curHP = 0;
	}
	else if (num >= maxHP) {
		curHP = maxHP;
	}
	else {
		curHP = num;
	}
}

int Attribute::GetCurHP()
{
	return curHP;
}

void Attribute::AddCurHP(int num)
{
	SetCurHP(GetCurHP() + num);
}

void Attribute::SetMaxHP(int num)
{
	if (num <= 1) {
		maxHP = 1;
	}
	else {
		maxHP = num;
	}
}

int Attribute::GetMaxHP()
{
	return maxHP;
}

void Attribute::AddMaxHP(int num)
{
	SetMaxHP(GetMaxHP() + num);
}

void Attribute::SetATK(int num)
{
	if (num <= 0) {
		ATK = 0;
	}
	else {
		ATK = num;
	}
}

int Attribute::GetATK()
{
	return ATK;
}

void Attribute::AddATK(int num)
{
	SetATK(GetATK() + num);
}

void Attribute::SetDEF(int num)
{
	if (num <= 0) {
		DEF = 0;
	}
	else {
		DEF = num;
	}
}

int Attribute::GetDEF()
{
	return DEF;
}

void Attribute::AddDEF(int num)
{
	SetDEF(GetDEF() + num);
}

void Attribute::SetSPD(int num)
{
	if (num <= 0) {
		SPD = 0;
	}
	else {
		SPD = num;
	}
}

int Attribute::GetSPD()
{
	return SPD;
}

void Attribute::AddSPD(int num)
{
	SetSPD(GetSPD() + num);
}


void Attribute::SetCurMM(int num)
{
	if (num <= 0) {
		curMM = 0;
	}
	else if (num >= maxMM) {
		curMM = maxMM;
	}
	else {
		curMM = num;
	}
}

int Attribute::GetCurMM()
{
	return curMM;
}

void Attribute::AddCurMM(int num)
{
	SetCurMM(GetCurMM() + num);
}

void Attribute::SetMaxMM(int num)
{
	if (num <= 1) {
		maxMM = 1;
	}
	else {
		maxMM = num;
	}
}

int Attribute::GetMaxMM()
{
	return maxMM;
}

void Attribute::AddMaxMM(int num)
{
	SetMaxMM(GetMaxMM() + num);
}