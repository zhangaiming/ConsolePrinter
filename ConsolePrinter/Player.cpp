#include "Player.h"

Player::Player(int inv_cap, string _name):Fighter(inv_cap, _name)
{
}

bool Player::ConductAction()
{
	return false;
}

bool Player::Attack()
{
	return false;
}

bool Player::UseItem()
{
	return false;
}
