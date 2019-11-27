#include "SkillManager.h"
#include "Role.h"
#include "Skill.h"

SkillManager::SkillManager(Role* role, int _capacity)
{
	owner = role;
	capacity = _capacity;
}

bool SkillManager::Attach(Skill* target)
{
	if (skillList.size() < capacity && GetIndexOf(target) == -1) {
		//����б��п�λ, ��û�иü���
		skillList.push_back(target);
		return true;
	}
	else {
		return false;
	}
}

bool SkillManager::Detach(Skill* target)
{
	int i = GetIndexOf(target);
	if (i != -1) {
		//����б����иü���
		SKILLLIST::iterator iter = skillList.begin();
		while (i--)
			iter++;
		skillList.erase(iter);
		return true;
	}
	return false;
}

Skill* SkillManager::GetSkillAt(int index)
{
	SKILLLIST::iterator iter = skillList.begin();

	if (index >= skillList.size())
		return nullptr;

	while (index--)
		iter++;

	return *iter;
}

int SkillManager::GetIndexOf(Skill* target)
{
	int result = -1;
	int i = 0;
	if (skillList.size() != 0) {
		for (SKILLLIST::iterator iter = skillList.begin(); iter != skillList.end(); iter++) {
			if ((*iter)->EqualsTo(target)) {
				result = i;
			}
			else {
				i++;
			}
		}
	}

	return result;
}

string* SkillManager::Apply(Skill* skill, Role* applier, Role* target)
{
	int skill_accuracy = skill->GetAccuracy();
	int mana_consume = skill->GetConsume();
	srand((unsigned int)time_t(NULL));
	if (mana_consume > target->GetAttribute()->GetCurMM()) {
		if (GetIndexOf(skill) != -1) {
			if ((rand() % 100) > (100 - skill_accuracy)) {
				//�ɹ�
				//ʵʩ����
				return skill->Apply(applier, target);
			}
		}
	}
}

string* SkillManager::Apply(int index, Role* applier, Role* target)
{

	Skill* skill = GetSkillAt(index);
	if (skill == nullptr) {
		return -1;
	}
	
	return Apply(skill, applier, target);
}
