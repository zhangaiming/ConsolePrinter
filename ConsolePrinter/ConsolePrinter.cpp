#include <iostream>
#include "Vector.h"
#include <Windows.h>
#include "ConsolePrinter.h"
#include "UI_DEF.h"

WORD GetDefaultConsoleColor();

WORD ConsolePrinter::defaultColor = GetDefaultConsoleColor();
HANDLE ConsolePrinter::hOut = GetStdHandle(STD_OUTPUT_HANDLE);


WORD GetDefaultConsoleColor() {
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbInfo);
	return csbInfo.wAttributes;
}

void ConsolePrinter::Print(const Vector2& pos, const char* c, const Color& fore, const Color& back)
{
	if (pos.x >= 0 && pos.x < SCREENSIZE_HOR && pos.y >= 0 && pos.y < SCREENSIZE_VER) {
		SetColor(Colors(fore, back));
		GoTo(pos);
		std::cout << c;
		ResetColor();
	}
}

/*void ConsolePrinter::Print(const Vector2& pos, const char* c, const Colors& color)
{
	if (pos.x >= 0 && pos.x < SCREENSIZE_HOR && pos.y >= 0 && pos.y < SCREENSIZE_VER) {
		SetColor(color);
		GoTo(pos);
		std::cout << c;
		ResetColor();
	}
}*/

void ConsolePrinter::PrintHorLine(const char* c, const Vector2& beginPos, const int length, const Color& fore, const Color& back)
{
	for (int i = 0; i < length; i++) {
		Print(Vector2(beginPos.x + i, beginPos.y), c, fore, back);
	}
}

void ConsolePrinter::PrintVerLine(const char* c, const Vector2& beginPos, const int length, const Color& fore, const Color& back)
{
	for (int i = 0; i < length; i++) {
		Print(Vector2(beginPos.x, beginPos.y + i), c, fore, back);
	}
}

void ConsolePrinter::PrintRectangle(const char* c, const Vector2& pos, int hor, int ver, const Color& fore, const Color& back)
{
	PrintHorLine(c, pos, hor, fore, back);
	PrintVerLine(c, pos, ver, fore, back);
	PrintHorLine(c, Vector2(pos.x, pos.y + ver - 1), hor, fore, back);
	PrintVerLine(c, Vector2(pos.x + hor - 1, pos.y), ver, fore, back);
}

void ConsolePrinter::GoTo(const Vector2& pos)
{
	COORD coord = { (SHORT)pos.x,(SHORT)pos.y };
	SetConsoleCursorPosition(hOut, coord);
}

void ConsolePrinter::SetDefaultColor(const Color& fore, const Color& back)
{
	defaultColor = (WORD)fore | (WORD)back;
}

void ConsolePrinter::SetDefaultColor(const Colors& colors)
{
	Colors a = colors;
	defaultColor = a.GetBackColor() | a.GetForeColor();
}

void ConsolePrinter::SetColor(Colors colors)
{
	WORD fc = colors.GetForeColor();
	WORD bc = colors.GetBackColor();
	if (fc == (WORD)Color::DEFAULT && bc != (WORD)((int)Color::DEFAULT * 16)) {
		//前景默认
		SetConsoleTextAttribute(hOut, (WORD)Color::GRAY | bc);
	}

	else if (bc == (WORD)((int)Color::DEFAULT * 16) && fc != (WORD)Color::DEFAULT) {
		//背景默认
		SetConsoleTextAttribute(hOut, (WORD)((int)Color::BLACK * 16) | fc);
	}

	else if (bc == (WORD)((int)Color::DEFAULT * 16) && fc == (WORD)Color::DEFAULT) {
		SetConsoleTextAttribute(hOut, defaultColor);
	}

	else if (bc != (WORD)((int)Color::DEFAULT * 16) && fc != (WORD)Color::DEFAULT) {
		SetConsoleTextAttribute(hOut, fc | bc);
	}
}

void ConsolePrinter::ResetColor() {
	SetConsoleTextAttribute(hOut, defaultColor);
}

WORD Colors::GetForeColor()
{
	return (WORD)foregroundColor;
}

WORD Colors::GetBackColor()
{
	//*16来使其转换成背景色对应的数值
	return (WORD)backgroundColor * 16;
}
