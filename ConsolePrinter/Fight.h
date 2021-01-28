#pragma once

class Fighter;

class Fight {
private:
	Fighter* a;
	Fighter* b;
	bool isFighting;

public:
	void FightLoop();
};