#include "SkillManager.h"

SkillManager::SkillManager(Role* _owner)
{
	owner = _owner;
}

string SkillManager::ApplySkill(Skill* skill, Role* target)
{
	if (GetIndexOf(skill) != -1) {
		return skill->Apply(owner, target);
	}else
		return "";
}

Skill* SkillManager::GetSkillAt(int index)
{
	int i = 0;
	for (SKILLLIST::iterator iter = skillList.begin(); iter != skillList.end(); iter++) {
		if (index == i) {
			return (*iter);
		}
		else {
			i++;
			continue;
		}
	}
	return nullptr;
}

int SkillManager::GetIndexOf(Skill* target)
{
	int i = 0;
	for (; i < skillList.size(); i++) {
		if (GetSkillAt(i)->EqualsTo(target)) {
			return i;
		}
	}
	return -1;	//没有这个技能,返回-1
}

bool SkillManager::RemoveSkill(Skill* target)
{
	if (GetIndexOf(target) != -1) {
		for (SKILLLIST::iterator iter = skillList.begin(); iter != skillList.end(); ) {
			if ((*iter)->EqualsTo(target)) {
				skillList.erase(iter++);
				return true;
			}
		}
	}
	else
		return false;
}

bool SkillManager::LearnSkill(Skill* target)
{
	if(GetIndexOf(target) != -1)
		return false;
	else {
		skillList.push_back(target);
		return true;
	}
}
