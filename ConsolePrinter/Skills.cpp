#include "Skills.h"
#include "Role.h"

FireUp::FireUp():Skill("������", "23333", 10)
{

}

string FireUp::Apply(Role* applier, Role* target)
{
	string result = applier->GetName() + "ʹ���˻�����,��" + target->GetName() + "�����x���˺�";
	return result;
}
