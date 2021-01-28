#include "BeginMenu.h"
#include "WidgetManager.h"
#include "ButtonGroup.h"
#include "Button.h"
#include "UI_DEF.h"
#include "ConsolePrinter.h"

#include <iostream>
#include <string>

void OnNewGamePressed();
void OnQuitGamePressed();

void BeginMenu::OnLoad()
{

	ButtonGroup* bg = new ButtonGroup();
	WidgetManager::Attach(bg);
	bg->AttachSelection(new Button("新游戏", Vector2(SCREENSIZE_HOR / 2 - 3, SCREENSIZE_VER / 2 + 1), OnNewGamePressed));
	bg->AttachSelection(new Button("退出游戏", Vector2(SCREENSIZE_HOR / 2 - 4, SCREENSIZE_VER / 2 + 3), OnQuitGamePressed));

	bg->Print();

	const char* title[6] =
	{
	" #######   #######    ######  ",
	" #      #  #      #  #      # ",
	" #######   #######   #        ",
	" #    #    #         #    ### ",
	" #     #   #         #      # ",
	" #      #  #          ######  " };
	for (int i = 0; i < 6; i++) {
		ConsolePrinter::Print(Vector2(SCREENSIZE_HOR / 2 - 15, SCREENSIZE_VER / 2 - 8+ i), title[i], Color::DARKBLUE, Color::DEFAULT);
	}

	
}

#include "LevelManager.h"
#include "NewGame.h"

void OnNewGamePressed() {
	LevelManager::Load(new NewGame);
}

#include "GameInstance.h"
void OnQuitGamePressed() {
	GameInstance::GetInstance()->Shutdown();
}