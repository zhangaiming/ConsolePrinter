#include "Skill.h"

Skill::Skill(const char* _name, const char* _desc, int _consume)
{
	name = new string(_name);
	description = new string(_desc);
	consume = _consume;
}

char* Skill::GetName()
{
	return (char*)name->data();
}

char* Skill::GetDescription()
{
	return (char*)description->data();
}

bool Skill::EqualsTo(Skill* target)
{
	if (target->consume == this->consume && target->description->_Equal(*this->description) && target->name->_Equal(*this->name))
		return true;
	return false;
}
