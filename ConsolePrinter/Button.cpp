#include "Button.h"
#include "ConsolePrinter.h"

Button::Button(const char* _text, Vector2 _pos, void(*s_func)(), void(*l_func)(), void(*u_func)()) : Widget(_pos)
{
	selectedFunc = s_func;
	lightedFunc = l_func;
	unlightedFunc = u_func;
	isLighted = false;
	size = 0;
	adaptiveSize = true;

	text = _text;
	if (adaptiveSize)
		Adapt();
	
}

void Button::OnSelected()
{
	if(selectedFunc != nullptr)
		selectedFunc();
	else {
		//´íÎó
	}
}

void Button::OnLighted()
{
	isLighted = true;
	if (lightedFunc != nullptr)
		lightedFunc();
}

void Button::OnUnlighted()
{
	isLighted = false;
	if (unlightedFunc != nullptr)
		unlightedFunc();
}

void Button::SetText(const char* a)
{
	Erase();
	text = a;
	if (adaptiveSize)
		Adapt();
	Print();
}

std::string Button::GetText()
{
	return text;
}

Button* Button::GetType()
{
	return this;
}
#include "StringTool.h"
void Button::Print()
{
	std::string temp = splitWstring(s2ws(text), size);

	if (isLighted) {
		ConsolePrinter::PrintHorLine(" ", position, size, Color::BLACK, Color::GRAY);
		ConsolePrinter::Print(position, temp.data(), Color::BLACK, Color::GRAY);
	}
		
	else {
		ConsolePrinter::PrintHorLine(" ", position, size, Color::DEFAULT, Color::DEFAULT);
		ConsolePrinter::Print(position, temp.data(), Color::DEFAULT, Color::DEFAULT);
	}
		
}

void Button::Erase()
{
	for (int i = 0; i < size; i++) {
		ConsolePrinter::Print(Vector2(position.x + i, position.y), " ");
	}
}

void Button::SetSize(int s)
{
	size = s;
}

int Button::GetSize()
{
	return size;
}

#include "StringTool.h"
void Button::SetSizeAdaptState(bool state)
{
	adaptiveSize = state;
	if (state)
		Adapt();
}

void Button::Adapt()
{
	SetSize(GetColumnNum(text));
}

void Button::SetVisiable(bool state)
{
	isVisialable = state;
	if (!state)
		Erase();
	else
		Print();
}

bool Button::operator==(Button* target)
{
	if (this->text._Equal(target->text) && this->selectedFunc == target->selectedFunc)
		return true;
	return false;
}
