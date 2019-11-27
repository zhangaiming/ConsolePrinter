#pragma once
#include "Item.h"

class Cup :public Item {
public:
	Cup();
	void OnUsed(Role* target);
	int GetType();
};

class Pen :public Item {
public:
	Pen();
	void OnUsed(Role* target);
	int GetType();
};