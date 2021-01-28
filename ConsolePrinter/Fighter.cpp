#include "Fighter.h"
#include "FightManager.h"
#include <string>
#include <random>

bool Fighter::Escape()
{
	FightManager::AddMessage(this->GetName() + string("��ʼ��������..."));
	srand((unsigned int)time_t(NULL));
	int prob = rand() % 100 + 1;
	if (prob < 50) {
		FightManager::AddMessage(this->GetName() + string("����ʧ����..."));
		return false;
	}
	else
	{
		srand((unsigned int)time_t(NULL));
		if ((rand() % 100 + 1) <= prob) {
			FightManager::AddMessage(this->GetName() + string("���ܳɹ�!"));
			return true;
		}
		else {
			FightManager::AddMessage(this->GetName() + string("����ʧ����..."));
			return false;
		}
	}
}

bool Fighter::UseItem()
{
	return false;
}

bool Fighter::Attack()
{
	return false;
}

bool Fighter::ConductAction()
{
	return false;
}

Fighter::Fighter(int inv_cap, string name) : Role(inv_cap, name)
{
	enemy = nullptr;
}
