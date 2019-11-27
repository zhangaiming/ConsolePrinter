#include <iostream>
#include "Vector.h"
#include <Windows.h>
#include "ConsolePrinter.h"

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
	SetColor(Colors(fore, back));
	GoTo(pos);
	std::cout << c;
	ResetColor();
}

void ConsolePrinter::Print(const Vector2& pos, const char* c, const Colors& color)
{
	SetColor(color);
	GoTo(pos);
	std::cout << c;
	ResetColor();
}

void ConsolePrinter::Print(const char* c, const Color& fore, const Color& back)
{
	SetColor(Colors(fore, back));
	std::cout << c;
	ResetColor();
}

void ConsolePrinter::Print(const char* c, const Colors& color)
{
	SetColor(color);
	std::cout << c;
	ResetColor();
}

void ConsolePrinter::PrintLine(const Vector2& pos, const char* c, const Color& fore, const Color& back)
{
	SetColor(Colors(fore, back));
	GoTo(pos);
	std::cout << c << std::endl;
	ResetColor();
}

void ConsolePrinter::PrintLine(const Vector2& pos, const char* c, const Colors& color)
{
	SetColor(color);
	GoTo(pos);
	std::cout << c << std::endl;
	ResetColor();
}

void ConsolePrinter::PrintLine(const char* c, const Color& fore, const Color& back)
{
	SetColor(Colors(fore, back));
	std::cout << c << std::endl;
	ResetColor();
}

void ConsolePrinter::PrintLine(const char* c, const Colors& color)
{
	SetColor(color);
	std::cout << c << std::endl;
	ResetColor();
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
