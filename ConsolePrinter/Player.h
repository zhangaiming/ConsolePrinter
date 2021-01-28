#pragma once
#include "Fighter.h"

class Player : public Fighter {
public:
	Player(int inv_cap, string _name);

	bool ConductAction();
	bool Attack();
	bool UseItem();
};