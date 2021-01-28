#include "NewGame.h"
#include "Widget.h"
#include "WidgetManager.h"
#include "ConsolePrinter.h"
#include "UI_DEF.h"
#include "ButtonGroup.h"
#include "Button.h"

void OnNameButtonPressed();
void OnEnterButPressed();
Button* b = nullptr;

bool hasInput = false;

void NewGame::OnLoad()
{
	ConsolePrinter::PrintRectangle("#", Vector2(SCREENSIZE_HOR / 2 - 13, SCREENSIZE_VER / 2 - 2), 26, 4, Color::GRAY);

	ButtonGroup* bg = new ButtonGroup();
	ConsolePrinter::Print(Vector2(SCREENSIZE_HOR / 2 - 12, SCREENSIZE_VER / 2 - 1), "你的名字:", Color::WHITE);
	b = new Button("按空格键开始输入...", Vector2(SCREENSIZE_HOR / 2 - 12, SCREENSIZE_VER / 2), OnNameButtonPressed);
	b->adaptiveSize = false;
	b->SetSize(24);
	bg->AttachSelection(b);
	Button* EnterBut = new Button("确定", Vector2(SCREENSIZE_HOR / 2 - 2, SCREENSIZE_VER / 2 + 6), OnEnterButPressed);
	bg->AttachSelection(EnterBut);
	bg->Print();
}

#include <iostream>
#include <sstream>
#include "CursorControler.h"
void OnNameButtonPressed() {
	if (b != nullptr) {
		b->adaptiveSize = true;
		b->SetText("");
		HideCursor(false);
		std::string temp;
		std::getline(std::cin, temp);
		b->adaptiveSize = false;
		b->SetSize(24);
		b->SetText(temp.data());
		HideCursor(true);
		hasInput = true;
	}
}

#include "GameInstance.h"
#include "MainLevel.h"
#include "LevelManager.h"
void OnEnterButPressed() {
	if (hasInput) {
		bool legal = true;
		std::string temp = b->GetText();
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == " "[0]) {
				legal = false;
			}
		}

		if (!legal) {
			b->SetText("名称含有非法字符。");
			hasInput = false;
		}

		else {
			GameInstance::GetInstance()->CreatePlayer(temp.data());
			LevelManager::Load(new MainLevel());
		}
	}
	else {
		b->SetText("按空格键开始输入...");
	}
}