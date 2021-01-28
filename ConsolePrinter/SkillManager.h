#pragma once
#include "Skill.h"
#include <list>

using namespace std;

typedef list<Skill*> SKILLLIST;

class Role;

class SkillManager {
private:
	SKILLLIST skillList;
	Role* owner;

public:
	SkillManager(Role* _owner);
	string ApplySkill(Skill* skill, Role* target);

	Skill* GetSkillAt(int);
	int GetIndexOf(Skill*);
	bool RemoveSkill(Skill*);
	bool LearnSkill(Skill*);
};