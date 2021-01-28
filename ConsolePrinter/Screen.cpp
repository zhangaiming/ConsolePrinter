#include "Screen.h"
#include "ConsolePrinter.h"
#include "UI_DEF.h"
#include "CursorControler.h"

#include <string>
void Screen::Screen_Init()
{
	//设置窗口大小
	std::string cmd = "mode con cols=";
	cmd += std::to_string(SCREENSIZE_HOR + 1);
	cmd += " lines=";
	cmd += std::to_string(SCREENSIZE_VER);
	system(cmd.data());

	//画出画面边框
	ConsolePrinter::PrintRectangle((char*)"#", Vector2(0, 0), SCREENSIZE_HOR, SCREENSIZE_VER, Color::DARKMAGENTA, Color::DEFAULT);
	HideCursor(true);
}

#include <list>
#include "WidgetManager.h"
#include "Widget.h"
void Screen::Refresh()
{
	//画出画面边框
	ConsolePrinter::PrintRectangle((char*)"#", Vector2(0, 0), SCREENSIZE_HOR, SCREENSIZE_VER, Color::DARKMAGENTA, Color::DEFAULT);

	WIDLIST wids = WidgetManager::GetWidgets();
	for (auto iter = wids.begin(); iter != wids.end(); iter++) {
		(*iter)->Print();
	}
}

#include "CursorControler.h"
#include <iostream>
void Screen::Erase()
{
	for (int y = 1; y < SCREENSIZE_VER - 1; y++) {
		for (int x = 1; x < SCREENSIZE_HOR - 1; x++) {
			MoveCursor(x, y);
			std::cout << " ";
		}
	}
}
