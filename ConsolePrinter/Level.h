#pragma once
#include <list>

class Level {
public:
	virtual void OnLoad() = 0;
	virtual void OnDestory();
};