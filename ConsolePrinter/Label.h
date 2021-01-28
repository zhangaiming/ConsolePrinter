#pragma once
#include "Widget.h"
#include "ConsolePrinter.h"

class Label : public Widget {
	int max_length;
	char* text;
	Color fore;
	Color back;

public:
	Label(int m_length, Vector2 pos, const char* t = "", const Color& fore = Color::DEFAULT, const Color& back = Color::DEFAULT);
	void Print();
	void Erase();

	void SetForeColor(const Color&);
	void SetBackColor(const Color&);

	void SetText(const char* t);
	char* GetText();
	
};