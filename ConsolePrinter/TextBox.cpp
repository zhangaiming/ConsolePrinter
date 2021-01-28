#include "TextBox.h"
#include "CursorControler.h"
#include <algorithm>
#include <iostream>
#include "StringTool.h"

TextBox::TextBox(Vector2 _pos, Vector2 _scale) : Widget(_pos)
{
	scale = _scale;
}


void TextBox::WriteLine(string _text)
{
	if (_text.length() > scale.x) {
		//如果超出边框

		wstring w_text = s2ws(_text);
		string fore = splitWstring(w_text, scale.x);
		string rest = _text.substr(fore.length());
		WriteLine(fore);
		WriteLine(rest);
	}
	else {
		if (texts.size() >= scale.y) {
			//如果行数超出可显示的范围,则整个textBox进行一次刷新,所有行上移
			//(*texts.begin()).~basic_string();
			texts.pop_front();
			texts.push_back(_text);
			Print();
		}
		else {
			texts.push_back(_text);
			MoveCursor(position.x, position.y + texts.size() - 1);
			cout << _text << endl;
		}
	}
}

void TextBox::Erase()
{
	for (int y = 0; y < scale.y; y++) {
		MoveCursor(position.x, position.y + y);
		for (int x = 0; x < scale.x; x++) {
			cout << " ";
		}
		cout << endl;
	}
}

void TextBox::Clear()
{
	Erase();
	texts.clear();
}

void TextBox::Print() 
{
	Erase();
	MoveCursor(position.x, position.y);	//将光标移至文本框的原点
	for (list<string>::iterator iter = texts.begin(); iter != texts.end(); iter++) {
		cout << (*iter) << endl;
	}
}
