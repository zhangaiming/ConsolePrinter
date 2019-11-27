#pragma once
#include <list>
#include "Effect.h"

using namespace std;

typedef list<Effect*> EFFECTLIST;

class Role;

class EffectManager {
public:
	Role* parent;

public:
	EffectManager(Role* _parent);
	void Apply(Effect* effect);
};