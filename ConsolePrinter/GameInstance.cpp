#include "GameInstance.h"
#include "Screen.h"
#include "LevelManager.h"
#include "UI_DEF.h"
#include <thread>

GameInstance* GameInstance::instance = nullptr;

void CheckKeyLoop();

GameInstance::GameInstance()
{
	instance = this;
	isGoing = true;
	player = nullptr;
}

GameInstance* GameInstance::GetInstance()
{
	if (instance == nullptr)
		GameInstance();
	return instance;
}

void GameInstance::Begin()
{
	void TestLine();
	TestLine();

	//启动画面
	Screen::Screen_Init();

	//加载启动关卡
	LevelManager::LoadBeginLevel();

	//启动键盘检测
	std::thread keyCheck(CheckKeyLoop);
	keyCheck.detach();

	//启动游戏主循环
	GameMainLoop();
}

void TestLine() {

}

void GameInstance::GameMainLoop()
{
	while (isGoing) {

	}
	//exit(0);
}

#include <conio.h>
#include "WidgetManager.h"
void CheckKeyLoop() {
	while (1) {
		if (_kbhit())
			//当按下按键
		{
			int key = _getch();
			WidgetManager::BoardcastKey(key);
		}
	}
}

void GameInstance::Shutdown()
{
	isGoing = false;
	instance = nullptr;
	exit(0);
}

Player* GameInstance::GetPlayer()
{
	return player;
}

#include "Player.h"
void GameInstance::CreatePlayer(const std::string& name)
{
	void TestPlayerLine();
	player = new Player(20, name);
	TestPlayerLine();
}

#include "Items.h"
#include "Equipments.h"

void TestPlayerLine() {
	GameInstance::GetInstance()->GetPlayer()->GetInventory()->AddItem(new Cup(), 50);
	GameInstance::GetInstance()->GetPlayer()->GetInventory()->AddItem(new Pen(), 33);
	GameInstance::GetInstance()->GetPlayer()->GetInventory()->AddItem(new AHat(), 1);
}

void GameInstance::SetGameState(bool state)
{
	isGoing = state;
}
