#pragma once
#include "Widget.h"
#include <string>
#include <vector>

using namespace std;

class TextBox : public Widget {
private:
	Vector2 scale;
	list<string> texts;

public:
	TextBox(Vector2 _pos, Vector2 _scale);

	void WriteLine(string _text);
	void Erase();
	void Clear();
	void Print();
};