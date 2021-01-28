#pragma once
#include "Role.h"

class Fighter : public Role {
public:
	Role* enemy;

private:
	virtual bool Escape();
	virtual bool UseItem();
	virtual bool Attack();

public:
	virtual bool ConductAction();
	Fighter(int inv_cap, string name);
};