#include "Fight.h"
#include "Fighter.h"

void Fight::FightLoop()
{
	while (true) {
		if (a->ConductAction())
			return;
		if (b->ConductAction())
			return;
	}
}
