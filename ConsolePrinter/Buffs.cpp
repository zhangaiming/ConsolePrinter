#include "Buffs.h"
#include "Role.h"


//ÉÕÉËBuff

void BurntBuff::OnApply(Role* role)
{
	intensity = (float)role->GetAttribute()->GetMaxHP() * 0.05f;
	Effect* effect = new Effect(EffectType::PLUS_CURHP, -intensity);
	role->ApplyEffect(effect);
}

void BurntBuff::OnDetach(Role*)
{
}

BurntBuff::BurntBuff(int _turns) : Buff(_turns), intensity(0) {}
