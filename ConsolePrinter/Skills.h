#pragma once


class Skill;

class FireUp : public Skill{
public:
	string* Apply(Role* applier, Role* target);
	FireUp();
};