#include "EffectManager.h"
#include "Role.h"

EffectManager::EffectManager(Role* _parent)
{
	parent = _parent;
}

void EffectManager::Apply(Effect* e)
{
	Attribute* attr = parent->GetAttribute();
	if(e != nullptr){
		EffectType type = e->GetType();
		float intensity = e->GetIntensity();
		if (type == EffectType::PLUS_CURHP)
			attr->AddCurHP(intensity);
		else if (type == EffectType::MUL_CURHP)
			attr->SetCurHP((float)attr->GetCurHP() * intensity);
		else if (type == EffectType::PLUS_MAXHP)
			attr->AddMaxHP(intensity);
		else if (type == EffectType::MUL_MAXHP)
			attr->SetMaxHP((float)attr->GetMaxHP() * intensity);
		else if (type == EffectType::PLUS_ATK)
			attr->AddATK(intensity);
		else if (type == EffectType::MUL_ATK)
			attr->SetATK((float)attr->GetATK() * intensity);
		else if (type == EffectType::PLUS_DEF)
			attr->AddDEF(intensity);
		else if (type == EffectType::MUL_DEF)
			attr->SetDEF((float)attr->GetDEF() * intensity);
		else if (type == EffectType::PLUS_SPD)
			attr->AddSPD(intensity);
		else if (type == EffectType::MUL_SPD)
			attr->SetSPD((float)attr->GetSPD() * intensity);
	}
}
