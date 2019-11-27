#pragma once
#include "Buff.h"

class Role;

class BurntBuff :public Buff {
private:
	float intensity;

public:
	void OnApply(Role*);
	void OnDetach(Role*);
	BurntBuff(int _turns);
};