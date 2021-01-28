#include "Label.h"

Label::Label(int m_length, Vector2 pos, const char* t, const Color& _fore, const Color& _back)
{
	max_length = m_length;
	position = pos;
	text = (char*)t;
	fore = _fore;
	back = _back;
}

#include "StringTool.h"
#include <string>
void Label::Print()
{
	Erase();
	std::string temp = splitWstring(s2ws(text), max_length);
	ConsolePrinter::Print(position, temp.data(), fore, back);
}

void Label::Erase()
{
	for (int i = 0; i < max_length; i++) {
		ConsolePrinter::Print(Vector2(position.x + i, position.y), " ");
	}
}

void Label::SetForeColor(const Color& c)
{
	fore = c;
	Print();
}

void Label::SetBackColor(const Color& c)
{
	back = c;
	Print();
}

void Label::SetText(const char* t)
{
	text = (char*)t;
	Print();
}

char* Label::GetText()
{
	return text;
}
