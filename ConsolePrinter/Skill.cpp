#include "Skill.h"
#include "Role.h"

Skill::Skill(const char* name, const char* desc, const int consume, const int ac)
{
	displayName = new string(name);
	description = new string(desc);
	consumeMM = consume;
	accuracy = ac;
}

string* Skill::GetName()
{
	return displayName;
}

string* Skill::GetDesc()
{
	return description;
}

int Skill::GetConsume()
{
	return consumeMM;
}

int Skill::GetAccuracy()
{
	return accuracy;
}

bool Skill::EqualsTo(Skill* skill)
{
	if (skill->displayName == this->displayName && skill->accuracy == this->accuracy && skill->description == this->description && skill->consumeMM == this->consumeMM)
		return true;
	return false;
}
