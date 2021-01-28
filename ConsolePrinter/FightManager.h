#pragma once
#include <string>
#include <list>

using namespace std;

class Fighter;
class Fight;

class FightManager {
	static list<string*> fightMessages;	//����װս������Ϣ
	static Fight* fight;	//���ڽ��е�ս��

public:
	static void LaunchFight(Fighter* a, Fighter* b);
	static void EndFight(Fight* fight);

	static void AddMessage(string message);
};