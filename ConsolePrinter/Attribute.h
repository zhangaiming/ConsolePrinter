#pragma once

class Attribute {
	int curHP = 20;
	int maxHP = curHP;
	int ATK = 20;
	int DEF = 20;
	int SPD = 20;
	int curMM = 50;
	int maxMM = curMM;

public:
	void SetCurHP(int);
	int GetCurHP();
	void AddCurHP(int);

	void SetMaxHP(int);
	int GetMaxHP();
	void AddMaxHP(int);

	void SetATK(int);
	int GetATK();
	void AddATK(int);

	void SetDEF(int);
	int GetDEF();
	void AddDEF(int);

	void SetSPD(int);
	int GetSPD();
	void AddSPD(int);

	void SetCurMM(int);
	int GetCurMM();
	void AddCurMM(int);

	void SetMaxMM(int);
	int GetMaxMM();
	void AddMaxMM(int);
};