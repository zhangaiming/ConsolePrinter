#pragma once
#include <string>
using namespace std;

class Role;

class Skill {
private:
	string* name;
	string* description;
	int consume;

public:
	Skill(const char* _name, const char* _desc, int _consume);
	char* GetName();
	char* GetDescription();
	virtual string Apply(Role* applier, Role* target) = 0;

	bool EqualsTo(Skill*);
};