#pragma once
#include "Buffs.h"
#include <string>

class Skill {
	string* displayName;
	string* description;
	int consumeMM;
	int accuracy;	//ÃüÖÐÂÊ

public:
	virtual string* Apply(Role* applier, Role* target) = 0;
	Skill(const char* name, const char* desc, const int consume, const int ac);

	string* GetName();
	string* GetDesc();
	int GetConsume();

	int GetAccuracy();
	bool EqualsTo(Skill* skill);
};