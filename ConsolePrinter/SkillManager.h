#pragma once

#include <list>
#include <string>

using namespace std;

class Role;
class Skill;

typedef list<Skill*> SKILLLIST;

class SkillManager {
	SKILLLIST skillList;
	Role* owner;
	int capacity;

public:
	SkillManager(Role* role, int _capacity);

	bool Attach(Skill* target);
	bool Detach(Skill* target);

	Skill* GetSkillAt(int index);
	int GetIndexOf(Skill* target);	//����target���б��ж�Ӧ��λ��,���б���û�и�target,�򷵻�-1

	string* Apply(Skill* skill, Role* applier, Role* target);
	string* Apply(int index, Role* applier, Role* target);
};