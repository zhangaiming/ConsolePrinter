#pragma once
#include "Selectable.h"
#include "Widget.h"
#include <string>

class Button : public Selection, public Widget{
	std::string text;
	int size;
	void(*lightedFunc)();
	void(*unlightedFunc)();

public:
	bool isLighted;
	bool adaptiveSize;
	
public:
	Button(const char* _text, Vector2 _pos, void(*s_func)(), void(*l_func)() = nullptr, void(*u_func)() = nullptr);

	void OnSelected();	//��ѡ���¼�
	void OnLighted();	//������ʾ
	void OnUnlighted();	//ȡ��������ʾ

	void SetText(const char*);
	std::string GetText();

	Button* GetType();
	void Print();
	void Erase();

	void SetSize(int s);
	int GetSize();
	void SetSizeAdaptState(bool);
	void Adapt();

	void SetVisiable(bool);

	bool operator==(Button* target);
};