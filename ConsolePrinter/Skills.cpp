#include "Skills.h"
#include "Role.h"

FireUp::FireUp():Skill("火球术", "23333", 10)
{

}

string FireUp::Apply(Role* applier, Role* target)
{
	string result = applier->GetName() + "使用了火球术,对" + target->GetName() + "造成了x点伤害";
	return result;
}
