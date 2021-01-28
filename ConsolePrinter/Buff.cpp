#include "Buff.h"

Buff::Buff(int _turns)
{
	restTurn = _turns;
	displayName = "ERROR";
	description = "ERROR";
}

void Buff::OnApply(Role*)
{
	restTurn--;
}

void Buff::OnAttach(Role*)
{

}

int Buff::GetRestTurn()
{
	return restTurn;
}
