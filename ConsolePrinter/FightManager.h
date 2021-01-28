#pragma once
#include <string>
#include <list>

using namespace std;

class Fighter;
class Fight;

class FightManager {
	static list<string*> fightMessages;	//用来装战斗的信息
	static Fight* fight;	//正在进行的战斗

public:
	static void LaunchFight(Fighter* a, Fighter* b);
	static void EndFight(Fight* fight);

	static void AddMessage(string message);
};