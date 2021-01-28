#include "Screen.h"
#include "ConsolePrinter.h"
#include "UI_DEF.h"
#include "CursorControler.h"

#include <string>
void Screen::Screen_Init()
{
	//���ô��ڴ�С
	std::string cmd = "mode con cols=";
	cmd += std::to_string(SCREENSIZE_HOR + 1);
	cmd += " lines=";
	cmd += std::to_string(SCREENSIZE_VER);
	system(cmd.data());

	//��������߿�
	ConsolePrinter::PrintRectangle((char*)"#", Vector2(0, 0), SCREENSIZE_HOR, SCREENSIZE_VER, Color::DARKMAGENTA, Color::DEFAULT);
	HideCursor(true);
}

#include <list>
#include "WidgetManager.h"
#include "Widget.h"
void Screen::Refresh()
{
	//��������߿�
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
