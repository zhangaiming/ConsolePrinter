#pragma once

class Role;

class Attribute {
	int curHP;
	int maxHP;
	int ATK;
	int DEF;
	int SPD;
	int curMM;
	int maxMM;

public:
	Attribute(int _maxHP, int _ATK, int _DEF, int _SPD, int _maxMM);

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