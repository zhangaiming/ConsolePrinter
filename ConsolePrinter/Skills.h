#pragma once
#include "Skill.h"
class Role;

class FireUp : public Skill{
public:
	FireUp();
	string Apply(Role* applier, Role* target);
};